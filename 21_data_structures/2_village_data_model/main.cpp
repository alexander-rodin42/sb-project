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
};

struct Plot {
    int number{};
    double area{};
    std::vector<Building> buildings;

    void AddBuildings(const int &buildingsNumber) {
        for (int i = 0; i < buildingsNumber; i++) {
            buildings.emplace_back();
            buildings[buildings.size() - 1].number = int(buildings.size());
        }
    }
};

struct Village {
    std::string name;
    double area{};
    std::vector<Plot> plots;

    void AddPlots(const int &plotsNumber) {
        for (int i = 0; i < plotsNumber; i++) {
            plots.emplace_back();
            plots[plots.size() - 1].number = int(plots.size());
        }
    }
};

void SetFloorsParameters (Building& building) {
    for (int i = 0; i < building.floors.size(); i++) {
        if (i == 0) {
            std::cout << "-------------------------------" << std::endl;
            std::cout << "The area of the first floor is equal to the area of the building - " << building.area << "." << std::endl;
            building.floors[i].area = building.area;
        }
        else {
            do {
                std::cout << "  Enter floor area (m2) #" << building.floors[i].number << ": ";
                std::cin >> building.floors[i].area;
                if (building.floors[i].area > building.floors[i - 1].area) {
                    std::cout << "(!) The area of the floor should not exceed the area of the lower floor." << std::endl;
                }
            }
            while ( !(building.floors[i].area > 0 && building.floors[i].area <= building.floors[i - 1].area));
        }

        int roomsNumber;
        do {
            std::cout << "Minimum number of rooms: " << GetMinRooms(building.buildingType) << "." << std::endl;
            std::cout << "Maximum number of rooms: " << GetMaxRooms(building.buildingType) << "." << std::endl;
            std::cout << "Enter the number of rooms on floor #" << building.floors[i].number << ": ";
            std::cin >> roomsNumber;
        }
        while ( !(roomsNumber >= GetMinRooms(building.buildingType) && roomsNumber <= GetMaxRooms(building.buildingType)));

        building.floors[i].AddRooms( roomsNumber);

        double sumArea;

        do {
            sumArea = 0;

            for (auto & room : building.floors[i].rooms) {
                do {
                    std::cout << "Available area per floor - " << building.floors[i].area - sumArea << "/" << building.floors[i].area << "." << std::endl;
                    std::cout << "Enter the area (m2) of the room #" << room.number << ": ";
                    std::cin >> room.area;
                    sumArea += room.area;
                }
                while (room.area < 0);
            }

            if ( !(sumArea <= building.floors[i].area + 0.01 && sumArea >= building.floors[i].area - 0.01)) {
                std::cout << "(!) The total area of the rooms should be equal to the floor area (accuracy +-0.01)." << std::endl;
            }
        }
        while ( !(sumArea <= building.floors[i].area + 0.01 && sumArea >= building.floors[i].area - 0.01));
    }
}

void SetBuilding (Building& building) {
    do {
        std::cout << "Choose the type for building #" << building.number << "." << std::endl;
        std::cout << "1 - House"     << std::endl;
        std::cout << "2 - Garage"    << std::endl;
        std::cout << "3 - Barn"      << std::endl;
        std::cout << "4 - Bathhouse" << std::endl;
        std::cout << "Enter building type number: ";
        std::cin >> building.buildingType;
    }
    while (building.buildingType < 1 || building.buildingType > 4);

    do {
        std::cout << "Enter building area (m2) #" << building.number << ": ";
        std::cin >> building.area;
    }
    while (building.area < 0);

    int floorsNumber;
    do {
        std::cout << "Maximum number of floors for the current building type (" << GetBuildingType(building.buildingType) << ") - ";
        std::cout << GetMaxFloors(building.buildingType) << std::endl;
        std::cout << "Enter the number of floors for building #" << building.number << ": ";
        std::cin >> floorsNumber;
    }
    while ( !(floorsNumber > 0 && floorsNumber <= GetMaxFloors(building.buildingType)));
    building.AddFloors( floorsNumber);
}

void SetBuildingsParameters (Plot& plot) {
    double sumArea;
    int houseCounter;

    do {
        sumArea = 0.0;
        houseCounter = 0;

        if (sumArea > plot.area) {
            std::cout << "-------------------------------" << std::endl;
            std::cout << "(!) The total area of buildings cannot exceed the area of the plot." << std::endl;
        }

        for (auto & building : plot.buildings) {
            std::cout << "-------------------------------" << std::endl;
            std::cout << "Available area - " << plot.area - sumArea << "/" << plot.area << "." << std::endl;
            SetBuilding( building);
            sumArea += building.area;

            if (building.buildingType == HOUSE) {
                houseCounter++;
            }

            SetFloorsParameters( building);
        }

        if (houseCounter < 1) {
            std::cout << "(!) There must be at least 1 house on the site." << std::endl;
        }
    } while ( !(sumArea <= plot.area && houseCounter > 0));


}

void SetPlot (Plot& plot) {
    do {
        std::cout << "Enter the area (m2) of plot #" << plot.number << ": ";
        std::cin >> plot.area;
    }
    while (plot.area < 0);

    int buildingsNumber;
    do {
        std::cout << "Enter the number of buildings on lot #" << plot.number << ": ";
        std::cin >> buildingsNumber;
    }
    while (buildingsNumber < 1);
    plot.AddBuildings( buildingsNumber);
}

void SetPlotsParameters (Village& village) {
    double sumArea = 0.0;

    do {
        if (sumArea > village.area) {
            std::cout << "-------------------------------" << std::endl;
            std::cout << "(!) The total area of the plots should not exceed the area of the village." << std::endl;
            sumArea = 0.0;
        }
        for (auto & plot : village.plots) {
            std::cout << "-------------------------------" << std::endl;
            std::cout << "Available area - " << village.area - sumArea << "/" << village.area << "." << std::endl;
            SetPlot( plot);
            sumArea += plot.area;
        }
    }
    while (sumArea > village.area);
}

void SetVillage (Village& village) {
    std::cout << "Enter the name of the village: ";
    std::cin >> village.name;

    do {
        std::cout << "Enter the area of the village: ";
        std::cin >> village.area;
    }
    while (village.area < 0);

    int plotsNumber;

    do {
        std::cout << "Enter the number of plots of land: ";
        std::cin >> plotsNumber;
    }
    while (plotsNumber < 1);
    village.AddPlots( plotsNumber);

    SetPlotsParameters( village);

    for (auto & plot : village.plots) {
        std::cout << "-------------------------------" << std::endl;
        std::cout << "--> Plot #" << plot.number << std::endl;
        SetBuildingsParameters( plot);
    }
}

void PrintInfo (Village& village) {
    std::cout << std::endl;
    std::cout << "--> Plot #" << village.name << " (" << village.area << " m2): " << std::endl;
    for (auto & plot : village.plots) {
        std::cout << "--> Plot #" << plot.number << " (" << plot.area << " m2): " << std::endl;
        for (auto & building : plot.buildings) {
            std::cout << "  Building #" << building.number << " (" << GetBuildingType( building.buildingType);
            std::cout << " - " << building.area << " m2)" << std::endl;
            for (auto & floor : building.floors) {
                std::cout << "Floor #" << floor.number << " (" << floor.area << " m2): ";
                for (auto & room : floor.rooms) {
                    std::cout << "Room #" << room.number << " - " << room.area << " m2. ";
                }
                std::cout << std::endl;
            }
        }
    }
}

double GetTotalLivingArea (Village& village) {
    std::cout << std::endl;
    double result = 0;

    for (auto & plot : village.plots) {
        for (auto & building : plot.buildings) {
            for (auto & floor : building.floors) {
                if (building.buildingType == HOUSE) {
                    result += floor.area;
                }
            }
        }
    }
    return result;
}

int main() {
    Village newVillage;

    SetVillage( newVillage);
    PrintInfo( newVillage);

    std::cout << "Total living area in the village \"" << newVillage.name << "\": " << GetTotalLivingArea( newVillage);
    std::cout << " m2." << std::endl;

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