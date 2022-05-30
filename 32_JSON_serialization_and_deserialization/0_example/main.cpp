#include <iostream>
#include <string>
#include <fstream>

#include "nlohmann/json.hpp"

struct Record {
    std::string name;
    std::string family;
    int age{};
    bool married{};
};

int main() {
    Record record;
//    std::cin >> record.name >> record.family >> record.age >> record.married;
//    std::ofstream file("record.json");
//
//    nlohmann::json dict = {
//            {"name", record.name},
//            {"family", record.family},
//            {"age", record.age},
//            {"married", record.married}
//    };
//    dict["name"] = record.name;
//    dict["family"] = record.family;
//    dict["age"] = record.age;
//    dict["married"] = record.married;
//    file << dict;
//    file.close();

    std::string name;
    nlohmann::json dict2 = "{ \"name\": \"Alexander\" }"_json;
    name = dict2["name"];
    std::cout << name << std::endl;

    std::ifstream inFile("record.json");
    nlohmann::json inDict;
    inFile >> inDict;
    record.name = inDict["name"];
    record.family = inDict["family"];
    record.age = inDict["age"];
    record.married = inDict["married"];

    std::cout << record.name << " " << record.family << " " << record.age << " " << record.married << std::endl;
    inFile.close();

    return 0;
}
