#include <iostream>
#include <string>

void AddItem (int rowNumber, int placeNumber, int (&items)[2][6]) {
    items[rowNumber][placeNumber] += 1;
}

void RemoveItem (int rowNumber, int placeNumber, int (&items)[2][6]) {
    items[rowNumber][placeNumber] -= 1;
}

void TransferItem (int fromRowNumber, int fromPlaceNumber, int toRowNumber, int toPlaceNumber, int (&items)[2][6]) {
    items[fromRowNumber][fromPlaceNumber] -= 1;
    items[toRowNumber][toPlaceNumber] += 1;
}

void PrintItem (const std::string& itemsName, int (&items)[2][6]) {
    std::cout << itemsName << std::endl;
    for (int i = 0; i < 2; i++) {
        std::cout << "Row " << i + 1 << " -\t";
        for (int j = 0; j < 6; j++) {
            std::cout << items[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int forks[2][6] = {{1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1}};

    int spoons[2][6] = {{1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1}};

    int knives[2][6] = {{1, 1, 1, 1, 1, 1},
                         {1, 1, 1, 1, 1, 1}};

    int dessertSpoons[2][6] = {{1, 0, 0, 0, 0, 0},
                                {1, 0, 0, 0, 0, 0}};

    int plates[2][6] = {{3, 2, 2, 2, 2, 2},
                        {3, 2, 2, 2, 2, 2}};

    int chairs[2][6] = {{1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1}};

    AddItem( 0, 4, chairs);
    TransferItem( 0, 0, 1, 2, spoons);
    RemoveItem( 0,0,plates);

    PrintItem( "Forks:", forks);
    PrintItem( "Spoons:", spoons);
    PrintItem( "Knives:", knives);
    PrintItem( "Dessert spoons:", dessertSpoons);
    PrintItem( "Plates:", plates);
    PrintItem( "Chairs:", chairs);

    return 0;
}
