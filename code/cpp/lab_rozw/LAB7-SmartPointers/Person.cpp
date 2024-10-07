#include "Person.h"
// https://www.learncpp.com/cpp-tutorial/15-7-circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr/

Person::Person(string _name) : name(move(_name)), uuid (rand())
{
    cout << name << " (uuid:" << uuid << ") created; memory address of the object: " << this << endl;
}

Person::~Person() {
    cout << name << " (uuid:" << uuid << ") died; memory address of the released object: " << this << endl;
    for (auto & person_who_likes_me : people_who_likes_me)
    {
        if (auto spt = person_who_likes_me.lock()) { // Has to be copied into a shared_ptr before usage
            cout << spt->name << " erases " << this->name << " (uuid:" << uuid << ")"  << " from his friends." << endl;
            spt->friends.erase(this->uuid);
        }
    }
}

void Person::AddFriend(shared_ptr<Person> &p, shared_ptr<Person> &me) {
    auto ret = this->friends.insert({p->uuid, p});
    if(ret.second){
        //    weak_ptr<Person> me = weak_ptr<Person>(*this);            // Bad: The weak_ptr can point only to shared_ptr.
        //    weak_ptr<Person> me = weak_ptr<Person>(Person("Jas"));    // Bad: The weak_ptr can point only to shared_ptr.

        //    weak_ptr<Person> me = make_shared<Person>(*this);         // Bad: Creates copy of the object and returns shared_ptr to it. The shared pointer is destroyed immediately.

        //    shared_ptr<Person> me = make_shared<Person>(*this);       // Bad: Creates copy of the object and returns shared_ptr to it
        //    shared_ptr<Person> me = this->shared_from_this();         // Bad: shared_from_this is called without having std::shared_ptr owning the caller
        //    shared_ptr<Person> me = (*this).shared_from_this();       // Bad: shared_from_this is called without having std::shared_ptr owning the caller

        //    shared_ptr<Person> me = shared_ptr<Person>(this);         // Bad: shared_ptr does not know that another shared_ptr (in main) has acquired this object.
        //    As a result it will be destroyed twice:
        //    first when I die and the list of people_who_likes_me<shared_ptr<Person> > is disposed,
        //    second time when main goes out of scope - the original object is destroyed)
        //    p->people_who_likes_me.emplace_back(me);

        p->people_who_likes_me.emplace_back(me);
    }
    else {
        cout << "Person with uuid "<< p->uuid <<" and name " << ret.first->second.lock()->name;
        cout << " is already a friend of " << this->name << endl;
    }
}


void Person::PrintFriends() {
    cout << this->name << " have following friends:" << endl;
    for (auto & m_friend : friends)
    {
        if (auto spt = m_friend.second.lock()) { // Has to be copied into a shared_ptr before usage
            cout << "\t" << spt->name << " (uuid:" << spt->uuid << ")" << endl;
        } else{
            cout << "\t" << "Unable to reach person with uuid: " << m_friend.first << endl;
        }
    }
}

void Person::ClearUnreachableFriends() {
    std::cout << this->name << " is clearing unreachable friends:" << std::endl;
    auto it_friend = friends.begin();

    while (it_friend != friends.end()) {
        if (!it_friend->second.lock()) { // Has to be copied into a shared_ptr before usage
            cout << "\t" << this->name << " removed unreachable person (with uuid:" << it_friend->first << ") from friends." << endl;
            // erase() makes the passed iterator invalid
            // But returns the iterator following the deleted element
            it_friend = friends.erase(it_friend);
        }
        else{
            ++it_friend;
        }
    }
}

