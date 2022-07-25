#include <iostream>
#include <vector>

// Иерархия классов игровых персонажей
class Warrior
{
public:
    virtual void info() = 0;
    virtual ~Warrior() = default;
};

class Infantryman: public Warrior
{
public:
    void info() override {
        std::cout << "Infantryman" << std::endl;
    };
};

class Archer: public Warrior
{
public:
    void info() override {
        std::cout << "Archer" << std::endl;
    };
};

class Horseman: public Warrior
{
public:
    void info() override {
        std::cout << "Horseman" << std::endl;
    };
};

// Фабрики объектов
class Factory
{
public:
    virtual Warrior* createWarrior() = 0;
    virtual ~Factory() = default;
};

class InfantryFactory: public Factory
{
public:
    Warrior* createWarrior() override {
        return new Infantryman;
    }
};

class ArchersFactory: public Factory
{
public:
    Warrior* createWarrior() override {
        return new Archer;
    }
};

class CavalryFactory: public Factory
{
public:
    Warrior* createWarrior() override {
        return new Horseman;
    }
};

int main() {
    auto* infantry_factory = new InfantryFactory;
    auto* archers_factory  = new ArchersFactory ;
    auto* cavalry_factory  = new CavalryFactory ;

    std::vector<Warrior*> v;
    v.push_back( infantry_factory->createWarrior());
    v.push_back( archers_factory->createWarrior());
    v.push_back( cavalry_factory->createWarrior());

    for (auto & i : v)
        i->info();

    return 0;
}
