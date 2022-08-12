//
// Created by Alexander on 8/2/2022.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "SearchServer.h"
#include "WordHandler.h"

bool RelativeIndex::operator==(const RelativeIndex &other) const
{
    return (docId == other.docId &&
            rank == other.rank);
}

SearchServer::SearchServer(std::vector<std::string>& inputDocs, const int& inputResponsesLimit)
: responsesLimit(inputResponsesLimit)
{
    index.UpdateDocumentBase(inputDocs);
}

std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string>& inputRequests)
{
    std::vector<std::vector<std::string>> uniqueWordsInRequests;

    for (int i = 0; i < inputRequests.size(); ++i)
    {
        uniqueWordsInRequests.push_back(WordHandler::chooseUniqueWords(inputRequests[i]));
        sortToEntry(uniqueWordsInRequests[i]);
    }

    //std::vector<std::vector<RelativeIndex>> result;

    for (auto & request : uniqueWordsInRequests)
    {
        std::map<size_t, size_t> suitableFiles;

        for (auto & words : request)
        {
            bool wordIsFind = true;

        }

    }




    return std::vector<std::vector<RelativeIndex>>();
}

void SearchServer::sortToEntry(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end(), [this](std::string& first, std::string& second)
    {
      size_t firstCount = 0;
      size_t secondCount = 0;

      std::vector<Entry> entry(index.GetWordCount(first));
      for (auto & i : entry) firstCount += i.count;

      entry = index.GetWordCount(second);
      for (auto & i : entry) secondCount += i.count;

      return firstCount < secondCount;
    });
}


