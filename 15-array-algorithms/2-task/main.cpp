#include <iostream>
#include <vector>

int main() {
    std::vector<int> sequenceNumbers = {2, 7, 11, 15};
    int number = 9;

    for (int i = 0; i < sequenceNumbers.size(); i++) {
        for (int j = i + 1; j < sequenceNumbers.size(); j++) {

            if (sequenceNumbers[i] + sequenceNumbers[j] == number) {
                std::cout << sequenceNumbers[i] << " " << sequenceNumbers[j] << std::endl;
                i = sequenceNumbers.size();
                break;
            }
        }
    }
    return 0;
}
