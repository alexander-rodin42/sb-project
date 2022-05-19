#include <iostream>
#include <map>
#include <vector>

#include <cpr/cpr.h>

void input_argument (std::string& argument, std::map<std::string, std::string>& arguments) {
    std::string value;

    do {
        std::cout << "> Enter an argument: ";
        std::cin >> argument;

        if (!(argument == "get" || argument == "post")) {
            std::cout << "> Enter value: ";
            std::cin >> value;

            arguments[argument] = value;
        }
    }
    while (!(argument == "get" || argument == "post"));
}

void request_method_get (std::map<std::string, std::string>& arguments) {
    std::string url = "https://httpbin.org/get?";

    std::map<std::string, std::string>::iterator it;
    for (it = arguments.begin(); it != arguments.end(); ++it) {
        url += it->first + "=" + it->second;

        auto it_next = it;
        if (++it_next != arguments.end()) {
            url += "&";
        }
    }

    cpr::Response r = cpr::Get(cpr::Url(url));
    std::cout << r.text << std::endl;
}

void request_method_post (std::map<std::string, std::string>& arguments) {
    std::vector<cpr::Pair> pairs;

    for (const auto& i : arguments) {
        pairs.emplace_back((std::string)i.first, (std::string)i.second);
    }

    cpr::Response r = cpr::Post(cpr::Url("https://httpbin.org/post"),
                                cpr::Payload(pairs.begin(), pairs.end()));
    std::cout << r.text << std::endl;
}

int main() {
    std::map<std::string, std::string> arguments;
    std::string command;

    std::cout << R"(Enter "get" or "post" for the appropriate request.)" << std::endl;
    input_argument(command, arguments);

    if (command == "get") {
        request_method_get(arguments);
    }
    else {
        request_method_post(arguments);
    }
    return 0;
}
