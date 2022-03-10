#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> firstMap;

    std::pair<std::string, int> newPair ("banana", 1);

    //1
    firstMap.insert(std::pair<std::string, int> ("apple", 2));          //add
    firstMap.insert(std::make_pair<std::string, int> ("hello", 3));     //add 2
    firstMap.insert(std::make_pair("new", 4));                          //add 3 ??
    firstMap["potato"] = 12;                                                        //add 4 !!
    firstMap["lemon"];                                                              //add 5 int value = 0

    std::cout << firstMap["new"] << std::endl;                                          //"4"

    for (auto & it : firstMap) {
        std::cout << it.first << " " << it.second << std::endl;
    }

    //2
    firstMap.insert(std::pair<std::string, int> ("apple", 3));          // does not replace existing
    std::cout << firstMap["apple"] << std::endl;                                        //"2"

    //3
    std::map<std::string, int>::iterator mapIterator = firstMap.find("apple");   // .find iterator (pointer)
    auto mapIterator1 = firstMap.find("new");                                    // short entry
    std::cout << mapIterator->first << " " << mapIterator->second << std::endl;
    std::cout << mapIterator1->first << " " << mapIterator1->second << std::endl;

    //4
    std::map<int, std::string> secondMap;

    secondMap.insert(std::make_pair<int, std::string> (2, "two"));
    secondMap.insert(std::make_pair<int, std::string> (7, "seven"));
    secondMap.insert(std::make_pair<int, std::string> (3, "three"));
    secondMap.insert(std::make_pair<int, std::string> (10, "ten"));
    secondMap.insert(std::make_pair<int, std::string> (4, "tour"));
    secondMap.insert(std::make_pair<int, std::string> (1, "one"));

    for (std::map<int, std::string>::iterator it = secondMap.begin(); it != secondMap.end(); ++it ) {  // recommended: auto & it
        std::cout << it->first << " " << it->second << std::endl;
    }

    //4.1
    std::cout << secondMap.begin()->first << std::endl;         // minimum

    //4.2
    auto findIterator = secondMap.find(3);               // auto
    secondMap.erase( findIterator);                      // .erase - removes element by pointer
    secondMap.erase(1);                                  // .erase - removes element by key

    for (auto & it : secondMap) {
        std::cout << it.first << " " << it.second << std::endl;
    }

    return 0;
}
