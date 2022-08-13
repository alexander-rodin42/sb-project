#include "gtest/gtest.h"

#include <algorithm>
#include "InvertedIndex.h"

TEST(TestCase, BasicTest3)
{
    const std::vector<std::string> docs = {
            "milk milk water water",
            "milk water water",
            "milk milk milk milk milk water water water water water",
            "americano cappuccino"
    };
    std::vector<std::string> requestWords = { "milk", "cappuccino", "water", };

    InvertedIndex index;

    index.UpdateDocumentBase(docs);

    std::sort(requestWords.begin(), requestWords.end(), [&index](std::string& first, std::string& second)
    {
        size_t firstCount = 0;
        size_t secondCount = 0;

        std::map<size_t, size_t> entry(index.GetWordCount(first));
        for (auto & i : entry) firstCount += i.second;

        entry = index.GetWordCount(second);
        for (auto & i : entry) secondCount += i.second;

        return firstCount < secondCount;
    });

    const std::vector<std::string> expected = { "cappuccino", "milk", "water" };

    ASSERT_EQ(requestWords, expected);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
