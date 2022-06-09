#include <iostream>

#include "Pond.h"
#include "CustomExceptions.h"

int main() {
    Pond pond;
    pond.print();

    try {
        while (true) {
            try {
                int sectorNumber;
                std::cout << "In which sector to throw a fishing rod? (1-10): ";
                std::cin >> sectorNumber;
                pond.castFishingRod(sectorNumber);
            }
            catch (const std::invalid_argument& x) {
                std::cout << x.what() << std::endl;
            }
            catch (const SectorIsEmpty& x) {
                std::cout << x.what() << std::endl;
            }
        }
    }
    catch (const FishCaughtInTheSector& x) {
        std::cout << x.what() << " From " << pond.getTryCounter() << " attempts." << std::endl;
    }
    catch (const BootCaughtInTheSector& x) {
        std::cout << x.what() << std::endl;
    }

    return 0;
}
