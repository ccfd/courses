#ifndef INCGUARD_PARLIB_HPP
#define INCGUARD_PARLIB_HPP

#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <memory>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

void sync();

namespace ParLib
{
    // Thread and mutex pools
	std::vector<std::thread>	                                            thread_pool{};
	std::unique_ptr<std::mutex[]>	                                        mutex_pool;
    size_t                                                                  number_of_threads = 0;
    std::vector<std::thread::id>                                            thread_ids{};

    // Syncing stuff
    std::mutex                                                              sync_mutex;
    size_t                                                                  sync_counter = 0;
    std::condition_variable                                                 sync_var;
    bool                                                                    sync_flag = false;

    // Timing stuff
    std::map< size_t, std::chrono::time_point<std::chrono::steady_clock> >  tics;
    std::mutex                                                              tic_mutex;
}

unsigned int self_id()
{
    const auto ttid = std::this_thread::get_id();
    const auto thread_ptr = ParLib::thread_ids.data();
    const auto dl = [&]()
    {
        return std::distance(thread_ptr, std::find(thread_ptr, thread_ptr + ParLib::number_of_threads, ttid));
    };
    auto ret = dl();

    while (ret == ParLib::number_of_threads)
	    ret = dl();

    return ret;
}

unsigned int no_threads()
{
	return ParLib::number_of_threads;
}

void init_mutex(const size_t& n_mutex)
{
    ParLib::mutex_pool = std::move(std::unique_ptr<std::mutex[]>(new std::mutex[n_mutex]));
}

void mutex_lock(const size_t& mutex_no)
{
	ParLib::mutex_pool[mutex_no].lock();
}

void mutex_unlock(const size_t& mutex_no)
{
	ParLib::mutex_pool[mutex_no].unlock();
}

template <typename Fun, typename ... Args>
void execute_in_parallel(const size_t& n_threads, const Fun& f, const Args& ... args)
{
    ParLib::number_of_threads = n_threads;
    ParLib::thread_ids.resize(n_threads);
    ParLib::thread_pool.resize(n_threads - 1);

    for (size_t i = 0; i < n_threads - 1; i++)
    {
        ParLib::thread_pool[i] = std::thread(f, args...);
        ParLib::thread_ids[i] = ParLib::thread_pool[i].get_id();
    }

    ParLib::thread_ids.back() = std::this_thread::get_id();
    std::invoke(f, args...);

	for (auto& t : ParLib::thread_pool)
		t.join();

	ParLib::thread_pool.clear();
    ParLib::thread_ids.clear();
    ParLib::number_of_threads = 0;
}

void sync()
{
    using ParLib::sync_mutex;
    using ParLib::sync_counter;
    using ParLib::sync_flag;
    using ParLib::sync_var;

    // Acquire mutex
    std::unique_lock<std::mutex> lock(sync_mutex);

    // If previous sync is still happening, wait until all threads exit
    if (sync_flag)
        sync_var.wait(lock, []() -> bool { return !ParLib::sync_flag; });

    // Log self as syncing
    sync_counter++;

    // Check if last thread reporting
    if (sync_counter == no_threads())
        sync_flag = true;

    // Wait until all threads arrive at sync
    else
        sync_var.wait(lock, []() -> bool { return ParLib::sync_flag; });

    // De-log self
    sync_counter--;

    // Notify the next waiting thread
    sync_var.notify_all();

    // Last thread out resets flag
    if (sync_counter == 0)
        sync_flag = false;
};

void tic(const size_t& tic_id = 0)
{
    std::lock_guard<std::mutex> tic_lock(ParLib::tic_mutex);
    ParLib::tics[tic_id] = std::chrono::steady_clock::now();
}

double toc(const size_t& tic_id = 0)
{
    std::lock_guard<std::mutex> toc_lock(ParLib::tic_mutex);

    const auto tic_it = ParLib::tics.find(tic_id);

    if (tic_it == ParLib::tics.cend())
    {
        std::cerr << "toc error: tic was never called for the key " << tic_id << '\n';
        return 0;
    }
    else
        return std::chrono::duration<double>(std::chrono::steady_clock::now() - (*tic_it).second).count();
}

#endif // include guard