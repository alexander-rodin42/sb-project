//
// Created by Alexander on 8/1/2022.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "nlohmann/json.hpp"

#include "ConverterJSON.h"

std::vector<std::string> ConverterJSON::GetTextDocuments() {
    std::vector<std::string> result;
    std::vector<std::string> addressList;

    GetFileAddresses(addressList);

    for (auto & address : addressList) {
        std::ifstream inFile(address);

        if (!inFile.is_open()) {
            std::cerr << "Text file missing: " << address << std::endl;
        }
        else {
            std::stringstream text;
            text << inFile.rdbuf();
            inFile.close();
            result.push_back(text.str());
        }
    }
    return result;
}

std::vector<std::string> ConverterJSON::GetRequests() {
    std::vector<std::string> result;

    std::ifstream inFile("requests.json");
    if (inFile.is_open()) {
        nlohmann::json inRequests;
        inFile >> inRequests;
        inFile.close();

        for (auto i = inRequests.find("requests")->begin(); i != inRequests.find("requests")->end(); ++i) {
            result.push_back(i.value());
        }
    }
    return result;
}


int ConverterJSON::GetResponsesLimit() {
    std::ifstream inFile("config.json");

    nlohmann::json inConfig;
    inFile >> inConfig;
    inFile.close();

    if (inConfig["config"].contains("max_responses")) {
        return inConfig["config"]["max_responses"];
    }
    else {
        return 5;
    }
}

void ConverterJSON::GetFileAddresses(std::vector<std::string> &list) {
    std::ifstream inFile("config.json");

    if (inFile.is_open()) {
        nlohmann::json inConfig;
        inFile >> inConfig;
        inFile.close();

        for (auto i = inConfig.find("files")->begin(); i != inConfig.find("files")->end(); ++i) {
            list.push_back(i.value());
        }
    }
}



