#include <iostream>
#include <string>
#include <fstream>

#include "nlohmann/json.hpp"

void create_database() {
    nlohmann::json database = {
            {"The Gentlemen", {
                {"country", "United Kingdom"},
                {"date", {
                    {"day", 01},
                    {"mouth", "January"},
                    {"year", 2020}
                }},
                {"directed", "Guy Ritchie"},
                {"screenwriter", {"Guy Ritchie", "Ivan Atkinson", "Marn Davies"}},
                {"producer", {"Guy Ritchie", "Ivan Atkinson", "Bill Block"}},
                {"starring", {
                    {"Matthew McConaughey", "Michael Pearson"},
                    {"Charlie Hunnam", "Ray"},
                    {"Henry Golding", "Dry Eye"},
                    {"Michelle Dockery", "Rosalind Pearson"},
                    {"Jeremy Strong", "Matthew"},
                    {"Eddie Marsan", "Big Dave"},
                    {"Colin Farrell", "Coach"},
                    {"Hugh Grant", "Fletcher"}
                }}
                              }},
            {"Revolver", {
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
                    {"Andre Benjamin", "Avi"},
                    {"Mark Strong", "Sorter"},
                    {"Terrence Maynard", "Paul"},
                    {"Francesca Annis", "Lily Walker"}
                }}
            }},
            {"The Man from U.N.C.L.E.", {
                {"country", "United Kingdom"},
                {"date", {
                    {"day", 14},
                    {"mouth", "August"},
                    {"year", 2015}
                }},
                {"directed", "Guy Ritchie"},
                {"screenwriter", {"Guy Ritchie", "Lionel Wigram"}},
                {"producer", {"John Davis", "Steve Clark-Hall", "Lionel Wigram", "Guy Ritchie"}},
                {"starring", {
                    {"Henry Cavill", "Solo"},
                    {"Armie Hammer", "Illya"},
                    {"Alicia Vikander", "Gaby"},
                    {"Elizabeth Debicki", "Victoria"},
                    {"Luca Calvani", "Alexander"},
                    {"Sylvester Groth", "Uncle Rudi"},
                    {"Hugh Grant", "Waverly"}
                }}
            }},
            {"Aladdin", {
                {"country", "United States"},
                {"date", {
                    {"day", 24},
                    {"mouth", "May"},
                    {"year", 2019}
                }},
                {"directed", "Guy Ritchie"},
                {"screenwriter", {"John August", "Guy Ritchie"}},
                {"producer", {"Dan Lin", "Jonathan Eirich"}},
                {"starring", {
                    {"Will Smith", "Genie"},
                    {"Mena Massoud", "Aladdin"},
                    {"Naomi Scott", "Princess Jasmine"},
                    {"Marwan Kenzari", "Jafar"},
                    {"Navid Negahban", "Sultan"},
                    {"Nasim Pedrad", "Dalia"},
                    {"Billy Magnussen", "Prince Anders"}
                }}
            }},
            {"Men in Black", {
                {"country", "United States"},
                {"date", {
                    {"day", 2},
                    {"mouth", "July"},
                    {"year", 1997}
                }},
                {"directed", "Barry Sonnenfeld"},
                {"screenwriter", {"Ed Solomon"}},
                {"producer", {"Walter F. Parkes", "Laurie MacDonald", "Steven Spielberg"}},
                {"starring", {
                    {"Tommy Lee Jones", "Kay"},
                    {"Will Smith", "Jay"},
                    {"Linda Fiorentino", "Laurel"},
                    {"Vincent D'Onofrio", "Edgar"},
                    {"Rip Torn", "Zed"}
                }}
            }},
            {"Snatch", {
                {"country", "United States"},
                {"date", {
                    {"day", 23},
                    {"mouth", "August"},
                    {"year", 2000}
                }},
                {"directed", "Guy Ritchie"},
                {"screenwriter", {"Guy Ritchie"}},
                {"producer", {"Matthew Vaughn"}},
                {"starring", {
                    {"Benicio del Toro", "Franky Four Fingers"},
                    {"Dennis Farina", "Cousin Avi"},
                    {"Vinnie Jones", "Bullet-Tooth Tony"},
                    {"Brad Pitt", "Mickey O'Neil"},
                    {"Rade Šerbedžija", "Boris the Blade"},
                    {"Jason Statham", "Turkish"}
                }}
            }},
            {"Wrath of Man", {
                {"country", "United States"},
                {"date", {
                    {"day", 7},
                    {"mouth", "May"},
                    {"year", 2021}
                }},
                {"directed", "Guy Ritchie"},
                {"screenwriter", {"Guy Ritchie", "Ivan Atkinson", "Marn Davies"}},
                {"producer", {"Guy Ritchie", "Ivan Atkinson", "Bill Block"}},
                {"starring", {
                    {"Jason Statham", "H"},
                    {"Holt McCallany", "Bullet"},
                    {"Jeffrey Donovan", "Jackson"},
                    {"Josh Hartnett", "Boy Sweat Dave"},
                    {"Laz Alonso", "Carlos"},
                    {"Raúl Castillo", "Sam"},
                    {"Deobia Oparei", "Brad"},
                    {"Eddie Marsan", "Terry"},
                    {"Scott Eastwood", "Jan"}
                }}
            }}
    };

    std::ofstream file("database.json");
    file << database;
    file.close();
}

void load_database(nlohmann::json& database) {
    std::ifstream file("database.json");
    if (file.is_open()) {
        file >> database;
        file.close();
    }
    else {
        std::cout << "Database not found." << std::endl;
    }
}

bool CheckName (const std::string& name) {
    return (std::all_of(name.begin(), name.end(), [](char i){return i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z';}));
}

void ConvertNameToFormat (std::string& name) {
    for (int i = 0; i < name.length(); i++){
        if (i == 0 && name[i] >= 'a' && name[i] <= 'z') {
            name[i] -= 32;
        }
        else if (i != 0 && name[i] >= 'A' && name[i] <= 'Z') {
            name[i] += 32;
        }
    }
}

void input(std::string& name) {
    std::cout << "Enter the actor's first or last name: ";
    do {
        std::cin >> name;
    }
    while(!CheckName(name));
}

void find_actor(std::string& name, nlohmann::json& database) {
    bool actorFound;

    for (auto movie = database.begin(); movie != database.end(); ++movie) {
        std::string fullName;
        std::string rol;
        actorFound = false;

        for(auto j = movie->find("starring")->begin(); j != movie->find("starring")->end() && !actorFound; ++j) {
            fullName = j.key();

            if (fullName.find(name) != std::string::npos) {
                rol = j.value();
                actorFound = true;
            }
        }
        if (actorFound) {
            std::cout << fullName << " played the role of " << rol << " in the movie \"" << movie.key()
                      << "\" (" << movie.value()["date"]["year"] << ")" << std::endl;
        }
    }

    if (!actorFound) {
        std::cout << "Actor not found." << std::endl;
    }
}

int main() {
    //create_database();
    std::string name;
    input(name);
    ConvertNameToFormat(name);

    nlohmann::json database;
    load_database( database);

    find_actor(name, database);
    return 0;
}
