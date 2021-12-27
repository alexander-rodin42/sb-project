#include <iostream>
#include <vector>

int main() {
    std::vector<int> sequenceNumbers = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int startIndex, endIndex, sum;
    int maxSum = sequenceNumbers[0];

    for (int i = 0; i < sequenceNumbers.size(); i++) {
        sum = sequenceNumbers[i];
        for (int j = i + 1; j < sequenceNumbers.size(); j++) {
            sum += sequenceNumbers[j];

            if (sum > maxSum) {
                maxSum = sum;
                startIndex = i;
                endIndex = j;
            }
        }
    }
    std::cout << startIndex << " " << endIndex << std::endl;

    return 0;
}
