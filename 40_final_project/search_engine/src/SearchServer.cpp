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

SearchServer::SearchServer(const std::vector<std::string>& inputDocs, const int& inputResponsesLimit)
: responsesLimit(inputResponsesLimit)
{
    index.UpdateDocumentBase(inputDocs);
}

std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string>& inputRequests)
{
    std::vector<std::vector<std::string>> uniqueWordsInRequests;

    //determine unique words in queries and sort them from rare to frequently encountered
    for (int i = 0; i < inputRequests.size(); ++i)
    {
        uniqueWordsInRequests.push_back(WordHandler::chooseUniqueWords(inputRequests[i]));
        sortByRarity(uniqueWordsInRequests[i]);
    }

    std::vector<std::vector<RelativeIndex>> result;

    for (auto & request : uniqueWordsInRequests)
    {
        std::map<size_t, size_t> docList = getListDocContainingWords(request);
        std::vector<RelativeIndex> requestResult;

        if (!docList.empty())
        {
            requestResult = calculateRelevance(docList, request);
        }

        result.push_back(requestResult);
    }
    return result;
}

void SearchServer::sortByRarity(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end(), [this](std::string& first, std::string& second)
    {
      size_t firstCount = 0;
      size_t secondCount = 0;

        std::map<size_t, size_t> entry(index.GetWordCount(first));
        for (auto & i : entry) firstCount += i.second;

        entry = index.GetWordCount(second);
        for (auto & i : entry) secondCount += i.second;

      return firstCount < secondCount;
    });
}

std::map<size_t, size_t> SearchServer::getListDocContainingWords(const std::vector<std::string>& request)
{
    std::map<size_t, size_t> docList(index.GetWordCount(request[0]));

    for (int i = 1; i < request.size(); ++i)
    {
        std::map<size_t, size_t> comparedDocList(index.GetWordCount(request[i]));
        std::vector<size_t> docIdForRemoving;

        for (auto &j: docList)
        {
            if (comparedDocList.find(j.first) == comparedDocList.end())
            {
                docIdForRemoving.push_back(j.first);
            }
        }

        for (auto &j: docIdForRemoving)
        {
            comparedDocList.erase(j);
        }
    }
    return docList;
}

std::vector<RelativeIndex>
SearchServer::calculateRelevance(const std::map<size_t, size_t>& docList,
                                 const std::vector<std::string>& request)
{
    std::vector<RelativeIndex> result;
    size_t absoluteRelevance = 0;

    for (auto & i : docList)
    {
        size_t relevance = 0.0f;

        for(auto & j : request)
        {
            std::map<size_t, size_t> temp = index.GetWordCount(j);
            relevance += temp[i.first];
        }

        if (relevance > absoluteRelevance) {
            absoluteRelevance = relevance;
        }

        RelativeIndex currentDoc = { i.first, (float)relevance };
        result.push_back(currentDoc);
    }

    for (auto & doc : result)
    {
        doc.rank /= (float)absoluteRelevance;
    }

    std::sort(result.begin(), result.end(), [](const RelativeIndex& first, const RelativeIndex& second)
    {
        return first.rank > second.rank;
    });

    if (result.size() > responsesLimit)
    {
        result.resize(responsesLimit);
    }

    return result;
}


