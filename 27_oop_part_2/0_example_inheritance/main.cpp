#include <iostream>
#include <cassert>

class Monster {
public:
    std::string name = "unknown";
    double attackDamage = 10;
    double health = 100;

    void attack() const {
        std::cout << name << " is attacking: " << attackDamage << std::endl;
    }
private:
};

class FlyingMonster : public Monster {
public:
    double flyingSpeed = 20;

    void fly() {
        std::cout << name << " is flying: " << flyingSpeed << std::endl;
    }
private:
};

class ShootingMonster : public Monster {
public:
    double attackRange = 30;
    void shoot() {
        attack();
        std::cout << "shooting: " << attackRange << std::endl;
    }

private:
};

int main() {
    FlyingMonster* flyingMonster = new FlyingMonster();
    flyingMonster->name = "First monster";
    flyingMonster->fly();
    flyingMonster->attack();

    delete flyingMonster;
    flyingMonster = nullptr;

    auto* shootingMonster = new ShootingMonster();
    shootingMonster->name = "Second monster";
    shootingMonster->shoot();
    delete shootingMonster;
    shootingMonster = nullptr;

    return 0;
}
