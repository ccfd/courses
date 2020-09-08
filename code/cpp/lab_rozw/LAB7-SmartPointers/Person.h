#pragma once

#include <memory>
#include <iostream>
#include <map>
#include <list>
using namespace std;

class Person
{
    string name;
    const int uuid; // for simplicity an int is used instead boost::uuid
    map< int, weak_ptr<Person> > friends;
//    list< shared_ptr<Person> > people_who_likes_me; // Bad - see comments in Person.cpp
    list< weak_ptr<Person> > people_who_likes_me;
public:
    explicit Person(string _name); // for simplicity use rand() instead of instead boost::uuid to initialize the uuid
    ~Person();
    void AddFriend(shared_ptr<Person> &p, shared_ptr<Person> &me);
    void PrintFriends();
    void ClearUnreachableFriends(); // Alternatively, the Person class apart from knowing own friends may store
};

