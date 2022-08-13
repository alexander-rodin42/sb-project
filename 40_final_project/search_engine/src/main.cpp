#include <iostream>
#include <string>
#include <fstream>

#include "nlohmann/json.hpp"

#include "ConverterJSON.h"
#include "CustomExceptions.h"
#include "InvertedIndex.h"

void printProgramName(nlohmann::json& config)
{
    std::cout << "Started execution ";

    if (config["config"].contains("name"))
    {
        std::cout << config["config"]["name"].get<std::string>();
    }

    if (config["config"].contains("version"))
    {
        std::cout << " v" << config["config"]["version"];
    }
    std::cout << std::endl;
}

void checkConfig(const std::string& configPath)
{
    std::ifstream inFile(configPath);

    if (!inFile.is_open())
    {
        throw ConfigFileIsMissing();
    }

    nlohmann::json inConfig;
    inFile >> inConfig;
    inFile.close();

    if (!inConfig.contains("config"))
    {
        throw ConfigFileIsEmpty();
    }

    printProgramName(inConfig);
}

void checkRequests(const std::string& requestsPath)
{
    std::ifstream inFile(requestsPath);

    if (!inFile.is_open())
    {
        throw RequestsFileIsMissing();
    }

    nlohmann::json inRequests;
    inFile >> inRequests;
    inFile.close();

    if (!inRequests.contains("requests") || inRequests["requests"].empty())
    {
        throw RequestsFileIsEmpty();
    }
}

bool isReadyToStart()
{
    try
    {
        checkConfig("config.json");
        checkRequests("requests.json");
        return true;
    }
    catch (const ConfigFileIsMissing& exception)
    {
        std::cerr << exception.what() << std::endl;
        return false;
    }
    catch (const ConfigFileIsEmpty& exception)
    {
        std::cerr << exception.what() << std::endl;
        return false;
    }
    catch (const RequestsFileIsMissing& exception)
    {
        std::cerr << exception.what() << std::endl;
        return false;
    }
    catch (const RequestsFileIsEmpty& exception)
    {
        std::cerr << exception.what() << std::endl;
        return false;
    }
}

int main()
{
    if (isReadyToStart())
    {
        //
        std::vector<std::string> textDocuments = ConverterJSON::GetTextDocuments();
        for (int i = 0; i < textDocuments.size(); ++i)
        {
            std::cout << i + 1 << ": " << textDocuments[i] << std::endl;
        }
        //
        std::vector<std::string> responses = ConverterJSON::GetRequests();
        for (int i = 0; i < responses.size(); ++i)
        {
            std::cout << i + 1 << ": " << responses[i] << std::endl;
        }
        //
        std::cout << "Responses limit: " << ConverterJSON::GetResponsesLimit() << std::endl;
        //
        InvertedIndex invertedIndex;
        invertedIndex.UpdateDocumentBase(textDocuments);
        //
        std::map<size_t, size_t> eMap = invertedIndex.GetWordCount("milk");
        //
        std::cout << "-----------" << std::endl;
        for (auto & entry : eMap) {
            std::cout << entry.first << " " << entry.second << std::endl;
        }
    }
    return 0;
}
