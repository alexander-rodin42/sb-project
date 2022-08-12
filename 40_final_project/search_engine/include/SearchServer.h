//
// Created by Alexander on 8/2/2022.
//

#pragma once

#ifndef SEARCH_ENGINE_SEARCHSERVER_H
#define SEARCH_ENGINE_SEARCHSERVER_H

#include "InvertedIndex.h"

struct RelativeIndex
{
    size_t docId;
    float rank;

    bool operator==(const RelativeIndex& other) const;
};

class SearchServer {
public:
    explicit SearchServer(std::vector<std::string>& inputDocs, const int& inputResponsesLimit);
    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string>& inputRequests);

    void sortToEntry(std::vector<std::string>& words);

private:
    InvertedIndex index;
    int responsesLimit;
};

#endif //SEARCH_ENGINE_SEARCHSERVER_H
