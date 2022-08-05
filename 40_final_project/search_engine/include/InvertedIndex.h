//
// Created by Alexander on 8/2/2022.
//

#pragma once

#ifndef SEARCH_ENGINE_INVERTEDINDEX_H
#define SEARCH_ENGINE_INVERTEDINDEX_H

struct Entry {
    size_t doc_id;
    size_t count;

    bool operator == (const Entry& other) const;
};

class InvertedIndex {
public:
    InvertedIndex() = default;

    void UpdateDocumentBase(std::vector<std::string> inputDocs);
    std::vector<Entry> GetWordCount(const std::string& word);
private:
    std::vector<std::string> docs;
};


#endif //SEARCH_ENGINE_INVERTEDINDEX_H
