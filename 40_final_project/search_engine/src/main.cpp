#include <iostream>
#include <string>
#include <fstream>

#include "nlohmann/json.hpp"


#include "SearchServer.h"
#include "ConverterJSON.h"
#include "CustomExceptions.h"


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
        SearchServer searchServer(ConverterJSON::GetTextDocuments(), ConverterJSON::GetResponsesLimit());
        ConverterJSON::putAnswers(searchServer.search(ConverterJSON::GetRequests()));
    }
    return 0;
}
