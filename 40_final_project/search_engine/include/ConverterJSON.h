//
// Created by Alexander on 8/1/2022.
//

#pragma once

class ConverterJSON {
public:
    ConverterJSON() = default;

    std::vector<std::string> GetTextDocuments();
    std::vector<std::string> GetRequests();
    int GetResponsesLimit();

private:
    static void GetFileAddresses(std::vector<std::string>& list);

};