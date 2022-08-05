//
// Created by Alexander on 8/1/2022.
//

#pragma once

#ifndef SEARCH_ENGINE_SEARCHSERVER_H
#define SEARCH_ENGINE_SEARCHSERVER_H

class ConverterJSON {
public:
    ConverterJSON() = default;

    static std::vector<std::string> GetTextDocuments();
    static std::vector<std::string> GetRequests();
    static int GetResponsesLimit();

private:
    static void GetFileAddresses(std::vector<std::string>& list);

};

#endif //SEARCH_ENGINE_SEARCHSERVER_H