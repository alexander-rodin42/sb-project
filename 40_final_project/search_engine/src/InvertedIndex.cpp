//
// Created by Alexander on 8/2/2022.
//

#include <iostream>
#include <string>
#include <vector>

#include "InvertedIndex.h"

bool Entry::operator==(const Entry &other) const {
    return (doc_id == other.doc_id &&
            count == other.count);
}
