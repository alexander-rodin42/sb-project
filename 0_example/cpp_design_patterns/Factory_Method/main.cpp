#include <iostream>
#include <vector>
#include <assert.h>

enum Warrior_ID { Infantryman_ID=0, Archer_ID, Horseman_ID };

// Иерархия классов игровых персонажей
class Warrior
{
public:
    virtual void info() = 0;
    virtual ~Warrior() {}
    // Параметризированный статический фабричный метод
    static Warrior* createWarrior( Warrior_ID id );
};

class Infantryman: public Warrior
{
public:
    void info() {
        std::cout << "Infantryman" << std::endl;
    }
};

class Archer: public Warrior
{
public:
    void info() {
        std::cout << "Archer" << std::endl;
    }
};

class Horseman: public Warrior
{
public:
    void info() {
        std::cout << "Horseman" << std::endl;
    }
};


// Реализация параметризированного фабричного метода
Warrior* Warrior::createWarrior( Warrior_ID id )
{
    Warrior * p;
    switch (id)
    {
        case Infantryman_ID:
            p = new Infantryman();
            break;
        case Archer_ID:
            p = new Archer();
            break;
        case Horseman_ID:
            p = new Horseman();
            break;
        default:
            assert( false);
    }
    return p;
};

int main() {
    std::vector<Warrior*> v;
    v.push_back( Warrior::createWarrior( Infantryman_ID));
    v.push_back( Warrior::createWarrior( Archer_ID));
    v.push_back( Warrior::createWarrior( Horseman_ID));

    for(auto & i : v)
        i->info();


    return 0;
}
