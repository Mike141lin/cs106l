#include "user.h"
#include <iostream>
#include <string>

// --- Provided Starter Functions ---

User::User(const std::string& name)
    : _name(name)
    , _friends(nullptr)
    , _size(0)
    , _capacity(0)
{
}

void User::add_friend(const std::string& name)
{
    if (_size == _capacity) {
        _capacity = 2 * _capacity + 1;
        std::string* newFriends = new std::string[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            newFriends[i] = _friends[i];
        }
        delete[] _friends;
        _friends = newFriends;
    }

    _friends[_size++] = name;
}

std::string User::get_name() const
{
    return _name;
}

size_t User::size() const
{
    return _size;
}

void User::set_friend(size_t index, const std::string& name)
{
    _friends[index] = name;
}


// --- Assignment Implementations ---

// Part 1: Print Operator
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "User(name=" << user._name << ", friends=[";
    for (size_t i = 0; i < user._size; ++i) {
        os << user._friends[i];
        if (i < user._size - 1) {
            os << ", ";
        }
    }
    os << "])";
    return os;
}

// Part 2: Special Member Functions

// Destructor
User::~User() {
    delete[] _friends;
}

// Copy Constructor
User::User(const User& other) {
    _name = other._name;
    _size = other._size;
    _capacity = other._capacity;

    _friends = new std::string[_capacity];

    for (size_t i = 0; i < _size; ++i) {
        _friends[i] = other._friends[i];
    }
}

// Copy Assignment Operator
User& User::operator=(const User& other) {
    if (this != &other) {
        delete[] _friends;

        _name = other._name;
        _size = other._size;
        _capacity = other._capacity;

        _friends = new std::string[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            _friends[i] = other._friends[i];
        }
    }
    return *this;
}

// Part 3: Other Overloaded Operators

// operator+=
User& User::operator+=(User& rhs) {
    this->add_friend(rhs._name);
    rhs.add_friend(this->_name);
    return *this;
}

// operator<
bool User::operator<(const User& rhs) const {
    return this->_name < rhs._name;
}
