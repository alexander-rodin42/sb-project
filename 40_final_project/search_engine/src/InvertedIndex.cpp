//
// Created by Alexander on 8/2/2022.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <thread>

#include "InvertedIndex.h"

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
    replaceCapitalLetters(word);

    if (freqDictionary.find(word) != freqDictionary.end())
    {
        result = freqDictionary[word];
    }

    freqDictionaryAccess.unlock();
    return result;
}

void InvertedIndex::documentIndexing(size_t docId, const std::string& doc)
{
    std::string word;

    for (int i = 0; i < doc.size(); ++i)
    {
        if (doc[i] >= 'a' && doc[i] <= 'z' || doc[i] >= 'A' && doc[i] <= 'Z')
        {
            word += doc[i];
        }

        if ((i == doc.size() - 1 || (doc[i] == ' ' || doc[i] == '\n')) && !word.empty())
        {
            freqDictionaryAccess.lock();
            replaceCapitalLetters(word);

            if (freqDictionary.find(word) != freqDictionary.end())
            {
                bool entryIsFind = false;

                for (size_t j = 0; j < freqDictionary[word].size() && !entryIsFind; ++j)
                {
                    if(freqDictionary[word][j].docId == docId)
                    {
                        ++freqDictionary[word][j].count;
                        entryIsFind = true;
                    }
                }

                if (!entryIsFind)
                {
                    Entry result{ docId, 1 };
                    freqDictionary[word].push_back(result);
                }
            }
            else
            {
                Entry result{ docId, 1 };
                freqDictionary[word].push_back(result);
            }
            freqDictionaryAccess.unlock();

            word.clear();
        }
    }
}

void InvertedIndex::replaceCapitalLetters(std::string& word) {
    for (char & i : word){
        if (i >= 'A' && i <= 'Z') {
            i += 32;
        }
    }
}




