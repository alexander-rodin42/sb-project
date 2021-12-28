#include <iostream>
#include <vector>

//Kadane's algorithm

int main() {
    std::vector<int> sequenceNumbers = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int startIndex = 0,
        endIndex = 0,
        minusPos = -1,
        sum = 0,
        maxSum = sequenceNumbers[0];

    for (int i = 0; i < sequenceNumbers.size(); i++) {
        sum += sequenceNumbers[i];

        if (sum > maxSum) {
            maxSum = sum;
            startIndex = minusPos + 1;
            endIndex = i;
        }

        if (sum < 0) {
            sum = 0;
            minusPos = i;
        }

    }
    std::cout << startIndex << " " << endIndex << std::endl;

    return 0;
}