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

namespace ParLib
{
    // Thread and mutex pools
	std::vector<std::thread>	                                            thread_pool{};
	std::unique_ptr<std::mutex[]>	                                        mutex_pool;

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
	return std::distance(ParLib::thread_pool.cbegin(), std::find_if(ParLib::thread_pool.cbegin(), ParLib::thread_pool.cend(),
		[](const std::thread& t) { return t.get_id() == std::this_thread::get_id(); }));
}

unsigned int no_threads()
{
	return ParLib::thread_pool.size();
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
void execute_in_parallel(const size_t& n_threads, Fun&& f, Args ... args)
{
	for (size_t i = 0; i < n_threads; i++)
		ParLib::thread_pool.emplace_back(std::forward<Fun>(f), std::forward<Args>(args) ...);

	for (auto& t : ParLib::thread_pool)
		t.join();

	ParLib::thread_pool.clear();
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