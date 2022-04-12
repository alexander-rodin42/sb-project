#pragma once

#include <iostream>
#include <map>
#include <vector>

#include "Person.h"

class MobilePhone {
public:
    void add();
    void call(const std::string& phoneNumber);
    void sms(const std::string& phoneNumber);
    void print(std::string& name);

private:
    std::map<std::string, Person> phoneNumberBook{};
    std::map<std::string, std::vector<Person>> nameBook{};
};