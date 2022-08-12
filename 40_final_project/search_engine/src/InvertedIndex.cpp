//
// Created by Alexander on 8/2/2022.
//

#include <iostream>
#include <string>
#include <vector>
#include <thread>

#include "InvertedIndex.h"
#include "WordHandler.h"

bool Entry::operator==(const Entry &other) const
{
    return (docId == other.docId &&
            count == other.count);
}

void InvertedIndex::UpdateDocumentBase(const std::vector<std::string>& inputDocs)
{
    std::vector<std::thread*> concurrentProcessing;
    std::thread* fileProcessing;

    for (size_t docId = 0; docId < inputDocs.size(); ++docId)
    {
        fileProcessing = new std::thread(&InvertedIndex::documentIndexing, this, docId, inputDocs[docId]);
        concurrentProcessing.push_back(fileProcessing);
    }

    for (size_t docId = 0; docId < inputDocs.size(); ++docId)
    {
        concurrentProcessing[docId]->join();
        delete concurrentProcessing[docId];
    }
}

std::vector<Entry> InvertedIndex::GetWordCount(std::string word)
{
    freqDictionaryAccess.lock();
    std::vector<Entry> result;
    WordHandler::replaceCapitalLetters(word);

    if (freqDictionary.find(word) != freqDictionary.end()) {
        for (auto & i : freqDictionary[word]) {
            result.push_back(i.second);
        }
    }
    freqDictionaryAccess.unlock();
    return result;
}

void InvertedIndex::documentIndexing(size_t docId, const std::string& doc)
{
    std::vector<std::string> words(WordHandler::getWords(doc));

    freqDictionaryAccess.lock();

    for (auto & word : words)
    {
        bool entryIsFind = false;
        bool wordIsFind = freqDictionary.find(word) != freqDictionary.end();

        if (wordIsFind) {
            if (freqDictionary[word].find(docId) != freqDictionary[word].end())
            {
                ++freqDictionary[word][docId].count;
                entryIsFind = true;
            }
        }

        if (!wordIsFind || !entryIsFind)
        {
            Entry result{ docId, 1 };
            freqDictionary[word][docId] = result;
        }

    }
    freqDictionaryAccess.unlock();
}






