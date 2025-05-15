
#include <iostream>
#include <list>
#include <string>

using namespace std;

class IChatRoom;

class IUser {
public:
    virtual void SendMessage(IChatRoom *iChatRoom, string message) = 0;
    virtual void ReceiveMessage(string message) = 0;
    virtual ~IUser() = default;
};

class IChatRoom {
public:
    virtual void DistributeMessage(IUser *sender, string msg) = 0;
    virtual void RegisterUser(IUser *user) = 0;
    virtual ~IChatRoom() = default;
};

class User : public IUser {
private:
    const string user_name;
public:
    explicit User(string _name): user_name(move (_name)){
        cout << this-> user_name << " created." << endl;
    };

    void SendMessage(IChatRoom *iChatRoom, string msg) override {
        iChatRoom->DistributeMessage(this, msg);
    }

    void ReceiveMessage(string msg) override {
        cout << "\t" << this->user_name << " received: " << msg << endl;
    }

    ~User() override {
        cout << this-> user_name << " died." << endl;
    };
};


class ChatRoom : public IChatRoom {
private:
    list<IUser*> users;
    const string room_name;
public:
    explicit ChatRoom(string _room_name) : room_name(move(_room_name)) {
        cout << this-> room_name << " created." << endl;
    };

    void DistributeMessage(IUser *sender, string msg) override {
        for (auto &user : this->users) {
            if (sender != user) {
                user->ReceiveMessage(msg);
            }
        }
    }

    void RegisterUser(IUser *user) override {
        this->users.emplace_back(user);
    }

    ~ChatRoom() override {
        cout << this-> room_name << " destroyed." << endl;
    };
};

int main(int argc, char *argv[]) {
    IUser *katie = new User("Katie");
    IUser *john = new User("John");
    IUser *alice = new User("Alice");
    IUser *bob = new User("Bob");

    cout << "-----------------------------------------" << endl; //first chat room
    IChatRoom *chatRoomA = new ChatRoom("chatRoomA");

    chatRoomA->RegisterUser(katie);
    chatRoomA->RegisterUser(john);
    chatRoomA->RegisterUser(alice);

    katie->SendMessage(chatRoomA, "Hi there, I'm Katie!");
    john->SendMessage(chatRoomA, "Msg from John.");
//    chatA->DistributeMessage(katie, "Hi there, I'm Katie!");

    cout << "-----------------------------------------" << endl; //second chat room
    IChatRoom *chatRoomB = new ChatRoom("chatRoomB");
    chatRoomB->RegisterUser(alice);
    chatRoomB->RegisterUser(bob);

    bob->SendMessage(chatRoomB, "Mr Bob is there.");

    cout << "-----------------------------------------" << endl;

    delete chatRoomB;
    delete chatRoomA;

    delete bob;
    delete alice;
    delete john;
    delete katie;

    return EXIT_SUCCESS;
}
