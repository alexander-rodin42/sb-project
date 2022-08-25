#include <fstream>
#include <iostream>
#include <string>

#include "nlohmann/json.hpp"

int main() {
    nlohmann::json config = {
            {"config",
             {{"name", "SearchEngine"},
              {"version", 1.0},
              {"max_responses", 5},
              {"files", {"resources\\file001.txt", "resources\\file002.txt", "resources\\file003.txt", "resources\\file004.txt",
                         "resources\\file005.txt", "resources\\file006.txt", "resources\\file007.txt", "resources\\file008.txt",
                         "resources\\file009.txt", "resources\\file010.txt", "resources\\file011.txt", "resources\\file012.txt",
                         "resources\\file013.txt", "resources\\file014.txt", "resources\\file015.txt", "resources\\file016.txt",
                         "resources\\file017.txt", "resources\\file018.txt", "resources\\file019.txt", "resources\\file020.txt",
                         "resources\\file021.txt", "resources\\file022.txt"}}}}};

    std::ofstream outFile("config.json");
    outFile << config.dump(4);
    outFile.close();

    //--------------------------------------------------------------------------------------------------------------

    nlohmann::json requests = {
            {"requests",
             {"london",
              "moscow is the capital of russia",
              "water milk"}}};

    std::ofstream outFile2("requests.json");
    outFile2 << requests.dump(4);
    outFile2.close();

    return 0;
}
