#pragma once

#include <string>

class Human
{
public:
    Human() : name_{"Anonymous"}, age_{0}, likes_dogs_{true}, likes_cats_{true} {}
    Human(std::string name, unsigned int age, bool ld, bool lk)
        : name_{std::move(name)}, age_{age}, likes_dogs_{ld}, likes_cats_{lk}
    {}

    const std::string& getName() const { return name_; }
    unsigned int       getAge() const { return age_; }
    bool               isMonster() const { return !likes_dogs_ && !likes_cats_; }
    void               birthday() { ++age_; }

private:
    std::string  name_;
    unsigned int age_;
    bool         likes_dogs_;
    bool         likes_cats_;
};
