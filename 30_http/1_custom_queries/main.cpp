#include <iostream>
#include <cpr/cpr.h>

void input_command (std::string& command) {
    do {
        std::cout << "> Enter command: ";
        std::cin >> command;
    }
    while (!(command == "get"
             || command == "post"
             || command == "put"
             || command == "delete"
             || command == "patch"
             || command == "exit"));
}

void request_method_get (const std::string& url) {
    cpr::Response r = cpr::Get(cpr::Url(url + "/get"),
                                cpr::Header({{"Accept", "text/html"}}));
    std::cout << r.text << std::endl;
}

void request_method_post (const std::string& url) {
    std::string name, city;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter city: ";
    std::cin >> city;

    cpr::Response r = cpr::Post(cpr::Url(url + "/post"),
                                cpr::Payload({{"name", name.c_str()},
                                              {"city", city.c_str()}}));
    std::cout << r.text << std::endl;
}

void request_method_put (const std::string& url) {
    std::string name, city;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter city: ";
    std::cin >> city;

    cpr::Response r = cpr::Put(cpr::Url(url + "/put"),
                                cpr::Payload({{"name", name.c_str()},
                                              {"city", city.c_str()}}));
    std::cout << r.text << std::endl;
}

void request_method_delete (const std::string& url) {
    std::string name, city;
    std::cout << "Enter name: ";
    std::cin >> name;

    cpr::Response r = cpr::Delete(cpr::Url(url + "/delete"),
                                  cpr::Payload({{"anything", name.c_str()}}));
    std::cout << r.text << std::endl;
}

void request_method_patch (const std::string& url) {
    std::string name, city;
    std::cout << "Enter new name: ";
    std::cin >> name;

    cpr::Response r = cpr::Patch(cpr::Url(url + "/patch"),
                               cpr::Payload({{"name", name.c_str()}}));
    std::cout << r.text << std::endl;
}

int main() {
    std::string url = "https://httpbin.org";
    std::string command;
    std::cout << "Available commands: get, post, put, delete, patch, exit." << std::endl;

    do {
        input_command(command);

        if (command == "get") {
            request_method_get(url);
        }
        else if (command == "post") {
            request_method_post(url);
        }
        else if (command == "put") {
            request_method_put(url);
        }
        else if (command == "delete") {
            request_method_delete(url);
        }
        else if (command == "patch") {
            request_method_patch(url);
        }
    }
    while (command != "exit");

    return 0;
}
