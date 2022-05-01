#pragma once

class Train {
public:
    explicit Train(const int& inTrainNumber);
    int getTrainNumber() const;
    int getTravelTime() const;
private:
    int trainNumber = 0;
    int travelTime = 0;
};

