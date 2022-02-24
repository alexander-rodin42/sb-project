#include <iostream>
#include <vector>

enum buildingType {
    HOUSE = 1,
    GARAGE,
    BARN,
    BATHHOUSE
};

int GetMaxFloors (const int& buildingType) {
    if (buildingType == HOUSE) {
        return 3;
    }
    else if (buildingType == GARAGE || buildingType == BARN) {
        return 2;
    }
    else {
        return 1;
    }
}

int GetMaxRooms (const int& buildingType) {
    if (buildingType == HOUSE) {
        return 4;
    }
    else if (buildingType == BATHHOUSE) {
        return 3;
    }
    else {
        return 1;
    }
}

int GetMinRooms (const int& buildingType) {
    if (buildingType == HOUSE || buildingType == BATHHOUSE) {
        return 2;
    }
    else {
        return 1;
    }
}

std::string GetBuildingType (const int& buildingType) {
    if (buildingType == HOUSE) {
        return "house";
    }
    else if (buildingType == GARAGE) {
        return "garage";
    }
    else if (buildingType == BARN) {
        return  "bran";
    }
    else {
        return "bathhouse";
    }
}

struct Room {
    int number{};
    double area{};
};

struct Floor {
    int number{};
    double area{};
    std::vector<Room> rooms;

    void AddRooms (const int& roomsNumber) {
        for (int i = 0; i < roomsNumber; i++) {
            rooms.emplace_back();
            rooms[rooms.size() - 1].number = int(rooms.size());
        }
    }
};

struct Building {
    int number{};
    int buildingType{};
    double area{};
    std::vector<Floor> floors;

    void AddFloors (const int& floorsNumber) {
        for (int i = 0; i < floorsNumber; i++) {
            floors.emplace_back();
            floors[floors.size() - 1].number = int(floors.size());
        }
    }

    void SetParameters () {
        do {
            std::cout << "Choose the type for building #" << this->number << "." << std::endl;
            std::cout << "1 - House"     << std::endl;
            std::cout << "2 - Garage"    << std::endl;
            std::cout << "3 - Barn"      << std::endl;
            std::cout << "4 - Bathhouse" << std::endl;
            std::cout << "Enter building type number: ";
            std::cin >> this->buildingType;
        }
        while (this->buildingType < 1 || this->buildingType > 4);

        do {
            std::cout << "Enter building area #" << this->number << ": ";
            std::cin >> this->area;
        }
        while (this->area < 0);

        int floorsNumber;
        do {
            std::cout << "Maximum number of floors for the current building type (" << GetBuildingType(this->buildingType) << ") - ";
            std::cout << GetMaxFloors(this->buildingType) << std::endl;
            std::cout << "Enter the number of floors for building #" << this->number << ": ";
            std::cin >> floorsNumber;
        }
        while ( !(floorsNumber > 0 && floorsNumber <= GetMaxFloors(this->buildingType)));

        this->AddFloors( floorsNumber);

        for (int i = 0; i < this->floors.size(); i++) {
            if (this->floors[i].number == 1) {
                std::cout << "-------------------------------" << std::endl;
                std::cout << "The area of the first floor is equal to the area of the building - " << this->area << "." << std::endl;
                this->floors[i].area = this->area;
            }
            else {
                do {
                    std::cout << "  Enter floor area #" << this->floors[i].number << ": ";
                    std::cin >> this->floors[i].area;
                    if (this->floors[i].area > this->floors[i - 1].area) {
                        std::cout << "(!) The area of the floor should not exceed the area of the lower floor." << std::endl;
                    }
                }
                while ( !(this->floors[i].area > 0 && this->floors[i].area <= this->floors[i - 1].area));
            }

            int roomsNumber;
            do {
                std::cout << "Minimum number of rooms: " << GetMinRooms(this->buildingType) << "." << std::endl;
                std::cout << "Maximum number of rooms: " << GetMaxRooms(this->buildingType) << "." << std::endl;
                std::cout << "Enter the number of rooms on floor #" << this->floors[i].number << ": ";
                std::cin >> roomsNumber;
            }
            while ( !(roomsNumber >= GetMinRooms(this->buildingType) && roomsNumber <= GetMaxRooms(this->buildingType)));

            this->floors[i].AddRooms( roomsNumber);

            for (auto & floor : this->floors) {
                double sumArea;

                do {
                    sumArea = 0;
                    for (auto & room :  this->floors[i].rooms) {

                        do {
                            std::cout << "Available area per floor - " << this->floors[i].area - sumArea << "/" << this->floors[i].area << "." << std::endl;
                            std::cout << "Enter the area of the room #"<< room.number << ": ";
                            std::cin >> room.area;
                            sumArea += room.area;
                        }
                        while (room.area < 0);
                    }

                    if (!(sumArea <= this->floors[i].area + 0.01 || sumArea >= this->floors[i].area - 0.01)) {
                        std::cout << "(!) The total area of the rooms should be equal to the floor area (Accuracy +-0.01)." << std::endl;
                    }
                }
                while ( !(sumArea <= this->floors[i].area + 0.01 || sumArea >= this->floors[i].area - 0.01));
            }
        }
    }
};

struct Plot {
    int number{};
    double area{};
    std::vector<Building> buildings;

    void AddBuildings (const int& buildingsNumber) {
        for (int i = 0; i < buildingsNumber; i++) {
            buildings.emplace_back();
            buildings[buildings.size() - 1].number = int(buildings.size());
        }
    }

    void SetParameters () {
        do {
            std::cout << "Enter the area of plot #" << this->number << ": ";
            std::cin >> this->area;
        }
        while (this->area < 0);

        int buildingsNumber;

        do {
            std::cout << "Enter the number of buildings on lot #" << this->number << ": ";
            std::cin >> buildingsNumber;
        }
        while (buildingsNumber < 1);

        this->AddBuildings( buildingsNumber);
    }

    void SetBuildingParameters () {
        double sumArea;
        int houseCounter;

        do {
            sumArea = 0.0;
            houseCounter = 0;

            if (sumArea > this->area) {
                std::cout << "(!) The total area of buildings cannot exceed the area of the plot." << std::endl;
            }

            for (auto & building : this->buildings) {
                std::cout << "-------------------------------" << std::endl;
                std::cout << "Available area - " << this->area - sumArea << "/" << this->area << "." << std::endl;
                building.SetParameters();
                sumArea += building.area;

                if (building.buildingType == HOUSE) {
                    houseCounter++;
                }
            }

            if (houseCounter < 1) {
                std::cout << "(!) There must be at least 1 house on the site." << std::endl;
            }
        } while ( !(sumArea <= this->area && houseCounter > 0));
    }
};

struct Village {
    std::string name;
    double area{};
    std::vector<Plot> plots;

    void AddPlots (const int& plotsNumber) {
        for (int i = 0; i < plotsNumber; i++) {
            plots.emplace_back();
            plots[plots.size() - 1].number = int(plots.size());
        }
    }

    void SetParameters () {
        std::cout << "Enter the name of the village: ";
        std::cin >> this->name;

        do {
            std::cout << "Enter the area of the village: ";
            std::cin >> this->area;
        }
        while (this->area < 0);

        int plotsNumber;

        do {
            std::cout << "Enter the number of plots of land: ";
            std::cin >> plotsNumber;
        }
        while (plotsNumber < 1);

        this->AddPlots( plotsNumber);
    }

    void SetPlotsParameters () {
        double sumArea = 0.0;
        do {
            if (sumArea > this->area) {
                std::cout << "(!) The total area of the plots should not exceed the area of the village." << std::endl;
                sumArea = 0.0;
            }
            for (auto & plot : this->plots) {
                std::cout << "-------------------------------" << std::endl;
                std::cout << "Available area - " << this->area - sumArea << "/" << this->area << "." << std::endl;
                plot.SetParameters();
                sumArea += plot.area;
            }
        } while (sumArea > this->area);
    }
};

int main() {
    Village settlement;

    settlement.SetParameters();
    settlement.SetPlotsParameters();

    for (auto & plot : settlement.plots) {
        std::cout << "-------------------------------" << std::endl;
        std::cout << "--> Plot #" << plot.number << std::endl;
        plot.SetBuildingParameters();
    }

    for (auto & plot : settlement.plots) {
        std::cout << "--> Plot #" << plot.number << std::endl;
        for (auto & building : plot.buildings) {
            std::cout << "  Building #" << building.number << " (" << GetBuildingType( building.buildingType) << ")" << std::endl;
            for (auto & floor : building.floors) {
                std::cout << "Floor #" << floor.number << " - ";
                for (auto & room : floor.rooms) {
                    std::cout << "Room #" << room.number << " - " << room.area << " m2, ";
                }
                std::cout << std::endl;
            }
        }
    }

    return 0;
}

/*
    Задание 2. Модель данных для посёлка

    С помощью структур данных создайте подробную модель посёлка.

    В посёлке есть множество участков. Каждый из них имеет свой уникальный номер. На каждом из участков должен быть
расположен как минимум один жилой дом, но возможны и другие сооружения, такие как гараж, сарай (бытовка) и баня. Для
каждого здания предусмотрена информация о площади, которую он занимает на участке.

    В жилом доме может быть 1–3 этажа. На каждом из этажей может быть 2–4 комнаты. Каждая комната при этом может быть
разных типов: спальня, кухня, ванная, детская, гостиная. Для каждой комнаты предусмотрены данные о её площади. Для
каждого этажа также есть данные о высоте потолка. В жилом доме и бане может быть печь с трубой, информация об этом
также должна быть предусмотрена в данных.

    Для всех упомянутых сущностей надо объявить соответствующие структуры данных.

    Вначале работы программы пользователь заполняет данные о посёлке: вводит общее количество участков и далее начинает
детализировать каждый из участков.

    Для каждого участка сначала заполняется общее количество построек, а затем детализируется каждая постройка, этажи,
комнаты на этажах.

    По итогам введённых данных вы можете рассчитать некий суммарный параметр, например, процент земли, занимаемой
постройками, к общей площади всего посёлка. Главное в этой задаче не сама операция подсчёта, а структуры данных.

Советы и рекомендации

    Используйте все имеющиеся у вас знания о типах данных в C++. Можно использовать уже изученные перечисления и
массивы, создавать структуры внутри структур и так далее.
*/