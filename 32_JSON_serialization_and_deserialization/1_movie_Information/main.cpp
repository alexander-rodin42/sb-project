#include <iostream>
#include <string>
#include <fstream>

#include "nlohmann/json.hpp"

int main() {
    nlohmann::json dictionary = {
            {"movie", "Revolver"},
            {"country", "United Kingdom"},
            {"date", {
                    {"day", 22},
                    {"mouth", "September"},
                    {"year", 2005}
            }},
            {"directed", "Guy Ritchie"},
            {"screenwriter", {"Guy Ritchie", "Luc Besson"}},
            {"producer", {"Luc Besson", "Virginie Silla", "Marty Katz"}},
            {"starring", {
                {"Jason Statham", "Jake Green"},
                {"Ray Liotta", "Dorothy Macha"},
                {"Vincent Pastore", "Zach"},
                {"Andre Benjamin" , "Avi"},
                {"Mark Strong", "Sorter"},
                {"Terrence Maynard", "Paul"},
                {"Francesca Annis", "Lily Walker"}
            }}
    };

    std::ofstream file("record.json");
    file << dictionary;
    file.close();
    return 0;
}
