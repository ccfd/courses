
#include "Person.h"

int main() {

    srand(0);  // initialize random seed

    auto katie = make_shared<Person>("Katie");
    auto john = make_shared<Person>("John");
    auto alice = make_shared<Person>("Alice");

    auto bob = make_shared<Person>("Bob");
    auto another_person_called_bob = std::make_shared<Person>("Bob");

    katie->AddFriend(alice, katie);
    katie->AddFriend(bob, katie);

    john->AddFriend(bob, john);
    john->AddFriend(bob, john);  // try to insert duplicate object
    john->AddFriend(another_person_called_bob, john);  // try to insert duplicate name

    katie->AddFriend(john, katie);  // create a cyclic reference
    john->AddFriend(katie, john);  // create a cyclic reference

    cout << "-----------------------------------------" << endl;
    katie->PrintFriends();
    john->PrintFriends();
    cout << "-----------------------------------------" << endl;
    {
        auto thomas = make_shared<Person>("Thomas");
        john->AddFriend(thomas, john);
        john->PrintFriends();
        katie->AddFriend(thomas, katie);
        katie->PrintFriends();
    } // thomas died when he went out of scope
    john->PrintFriends();
    katie->PrintFriends();
    john->ClearUnreachableFriends();
    john->PrintFriends();
    katie->PrintFriends();
    cout << "-----------------------------------------" << endl;
    return EXIT_SUCCESS;
}

