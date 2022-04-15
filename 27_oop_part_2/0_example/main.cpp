#include <iostream>
#include <cassert>

class TrainCar {
public:
    explicit TrainCar(class Train* inTrain, const int& inPassengersMax)
            : passengersMax(inPassengersMax), train(inTrain) {
        assert(inTrain != nullptr);
        assert(inPassengersMax >= 0);
    };

    void load (int& value) {
        passengers += value;
        if (passengers > passengersMax) {
            passengers = passengersMax;
        }
    }

    int getPassengers() const {
        return passengers;
    }

    int getNumber();

private:
    int passengersMax = 0;
    int passengers = 0;

    class Train* train = nullptr;
};

class Train {
public:
    Train(const int& inCount, const int& inPassengersMax) : count(inCount) {
        assert(inCount >= 0);
        cars = new TrainCar*[inCount];
        for (int i = 0; i < count; ++i) {
            cars[i] = new TrainCar(this, inPassengersMax);
        }
    };

    TrainCar* getCarAt(const int& index) {
        if (this == nullptr) return nullptr; // protection against calling from an empty instance of the train class
                                             // защита от вызова из пустого экземпляра класса train
        if (index < 0) return nullptr;
        if (index >= this->count) return nullptr;
        return this->cars[index];
    }

    int getCount () const {
        return count;
    }
private:
    int count = 0;
    TrainCar** cars = nullptr;
};

int TrainCar::getNumber() {
    for (int i = 0; i < train->getCount(); ++i) {
        TrainCar* car = train->getCarAt(i);

        if (car == this) return i + 1;
    }
    assert(false);
};

int main() {
    Train* train = new Train(10, 30);

    Train* train2 = nullptr; // An empty instance of the train class
    train2->getCarAt(2); // call from an empty instance of the train class
                               // вызов из пустого экземпляра класса поезд

    for (int i = 0; i < train->getCount(); ++i) {
        int passengers = 0;
        std::cout << i + 1 << " - ";
        std::cin >> passengers;
        train->getCarAt(i)->load(passengers);
    }

    TrainCar* car3 = train->getCarAt(2);

    std::cout << car3->getNumber() << ": " << car3->getPassengers() << std::endl;

    return 0;
}
