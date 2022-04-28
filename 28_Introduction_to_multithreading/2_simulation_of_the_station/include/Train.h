#pragma once

class Train {
public:
    explicit Train(const int& inTrainNumber);
    int getTrainNumber() const;
    int getTravelTime() const;
    bool getArrived() const;
    void setArrived();
private:
    int trainNumber = 0;
    int travelTime = 0;
    bool arrived = false;
};

