
// http://www.lucadavidian.com/2018/09/16/observer-design-pattern/

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class IObserver {
public:
    virtual void Update(const string &msg) = 0;
    virtual ~IObserver() = default;
};

class Channel {
    list<IObserver *> observers;
protected:
    void Notify(const string &info) {
        for (auto &user : observers) {
            if (user != nullptr) {
                user->Update(info);
            }
        }
    }
public:
    void Attach(IObserver *iObserver) {
        observers.emplace_back(iObserver);
    }

    void Detach(IObserver *iObserver) {
        observers.remove(iObserver);
      //  observers.erase(remove(observers.begin(), observers.end(), iObserver), observers.end());  // use erase-remove for std::vector
    }

    virtual ~Channel() = default;
};

class WeatherChannel : public Channel {
    const string channel_name;
public:
    explicit WeatherChannel(string n) : channel_name(move(n)) {};
    void SetStatus(const string &msg) {
        Notify(channel_name + ": " + msg);
    }

    ~WeatherChannel() override {
        cout << "Channel: " << channel_name << " is destroyed." << endl;
    }
};

class User : public IObserver {
    const string user_name;
    string recent_news;
public:
    explicit User(string n): user_name(move(n)){};

    void Update(const string &msg) override {
        this->recent_news = msg;
        cout << "Msg for " << user_name << " is: " << recent_news << endl;
    }

    ~User() override {
        cout << "User: " << user_name << " is destroyed." << endl;
    }
};

int main(int argc, char *argv[]) {
    WeatherChannel weatherChannel("WeatherNews");

    // Users want to be updated about the news announced in the channel
    IObserver* charlie = new User("Charlie");
    IObserver* alice = new User("Alice");
    weatherChannel.Attach(charlie);
    weatherChannel.Attach(alice);

    // Lets set the weather status, this should update the users automatically
    weatherChannel.SetStatus("Air quality is bad.");

    // Now alice is not interested so she unsubscribe
    weatherChannel.Detach(alice);

    // Now lets set different status
    weatherChannel.SetStatus("Be careful, air quality is getting even worse.");

    delete alice;
    delete charlie;
    return EXIT_SUCCESS;
}


//Output:
//Msg for Charlie is: WeatherNews: Air quality is bad.
//Msg for Alice is: WeatherNews: Air quality is bad.
//Msg for Charlie is: WeatherNews: Be careful, air quality is getting even worse.
//User: Alice is destroyed.
//User: Charlie is destroyed.
//Channel: WeatherNews is destroyed.
//
//Process finished with exit code 0
