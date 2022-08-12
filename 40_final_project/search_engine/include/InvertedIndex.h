//
// Created by Alexander on 8/2/2022.
//

#pragma once

#ifndef SEARCH_ENGINE_INVERTEDINDEX_H
#define SEARCH_ENGINE_INVERTEDINDEX_H

#include <map>
#include <mutex>

struct Entry
{
    size_t docId;
    size_t count;

    bool operator==(const Entry& other) const;
};

class InvertedIndex
{
public:
    InvertedIndex() = default;
    InvertedIndex( const InvertedIndex& ) = delete;
    void operator=( const InvertedIndex& ) = delete;

    void UpdateDocumentBase(const std::vector<std::string>& inputDocs);
    std::vector<Entry> GetWordCount(std::string word);

private:
    std::map<std::string, std::map<size_t, Entry>> freqDictionary;
    std::mutex freqDictionaryAccess;

    void documentIndexing(size_t docId, const std::string& doc);
};


#endif //SEARCH_ENGINE_INVERTEDINDEX_H
