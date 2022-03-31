#include <iostream>
#include <string>

class Robot {
public:
    int id;
    int health;
    int damage;
    int speed;

    void attack() const {
        std::cout << "Robot #" << id << " deals damage: " << damage << std::endl;
    }

    void move() const {
        std::cout << "Robot #" << id << " move: " << speed << std::endl;
    }

    void checkHealth() const {
        std::cout << "Robot #" << id << " has health left: " << health << std::endl;
    }
private:
};

class PlaneControl {
public:
    void turnLeft() {
        leftAileron -= 30;
        rightAileron += 30;
    }

    void turnRight() {
        leftAileron += 30;
        rightAileron -= 30;
    }

    void setElevator (double value) {
        if (value < -30) value = -30;
        if (value > 30) value = 30;
        if (value == elevator) return;
        elevator = value;
    }

    void print () const {
        std::cout << leftAileron << std::endl;
        std::cout << rightAileron << std::endl;
        std::cout << elevator << std::endl;
    }

    double getLeftAileron () const {
        return leftAileron;
    }

    double getRightAileron () const {
        return rightAileron;
    }
    double getElevator () const {
        return elevator;
    }

    static void showInfo3(PlaneControl* planeControl) {
        std::cout << planeControl->getLeftAileron() << std::endl;
        std::cout << planeControl->getRightAileron() << std::endl;
        std::cout << planeControl->getElevator() << std::endl;
    }

    friend void showInfo2(PlaneControl* planeControl);

private:
    double leftAileron = 0;
    double rightAileron = 0;
    double elevator = 0;
};

void showInfo(PlaneControl* planeControl) {
    std::cout << planeControl->getLeftAileron() << std::endl;
    std::cout << planeControl->getRightAileron() << std::endl;
    std::cout << planeControl->getElevator() << std::endl;
}

void showInfo2(PlaneControl* planeControl) {
    std::cout << planeControl->leftAileron << std::endl;
    std::cout << planeControl->rightAileron << std::endl;
    std::cout << planeControl->elevator << std::endl;
}

int main() {
    std::cout << "(1.1)-stack------------------" << std::endl;
    Robot robot1 = {1, 100, 50, 10};
    robot1.attack();
    robot1.move();
    robot1.checkHealth();

    std::cout << "(1.2)-heap-------------------" << std::endl;
    Robot* robot2 = new Robot {2, 200, 60, 10}; //auto
    robot2->attack();
    robot2->move();
    robot2->checkHealth();
    delete robot2;

    std::cout << "(2.1)-access-modifiers-------" << std::endl;
    auto* planeControl = new PlaneControl();
    planeControl->turnLeft();
    planeControl->setElevator(10.0);
    planeControl->print();

    planeControl->turnRight();
    planeControl->print();

    delete planeControl;
    planeControl = nullptr;

    std::cout << "(3.1)-class-methods----------" << std::endl;
    planeControl = new PlaneControl();
    planeControl->turnLeft();
    planeControl->setElevator(15.2);

    showInfo( planeControl);
    showInfo2( planeControl);
    PlaneControl::showInfo3( planeControl); //static modifier

    delete planeControl;
    planeControl = nullptr;
    return 0;
}
