#include <iostream>
#include <cpr/cpr.h>

/*
    Типы медиа для Accept:
    text/html
    text/css
    image/png
    image/jpeg
*/

int main() {
    cpr::Response r = cpr::Get(cpr::Url("https://httpbin.org/get"));
    std::cout << r.text << std::endl;

    cpr::Response r2 = cpr::Get(cpr::Url("https://httpbin.org/headers"),
                                cpr::Header({{"user-agent","Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/101.0.0.0 Safari/537.36"},
                                             {"Accept", "text/html"}}));
    std::cout << r2.text << std::endl;

    //---------------------------------------------------------------------------------------------------------------
    std::cout << "Enter name, city: ";
    std::string name, city;
    std::cin >> name >> city;

    cpr::Response r3 = cpr::Post(cpr::Url("https://httpbin.org/post"),
                                cpr::Payload({{"name", name.c_str()},
                                              {"city", city.c_str()}}));
    std::cout << r3.text << std::endl;
    return 0;
}

