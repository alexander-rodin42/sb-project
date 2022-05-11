#include <iostream>

class Animal {
public:
    virtual void voice(Animal* animal) = 0;
    virtual ~Animal() = default;
    int getId() const {
        return id;
    }
protected:
    int id = 0;
};

class Cat : virtual public Animal {
public:
    Cat() {
        id = 1;
    }
    virtual void voice(Animal* animal) {
        if (animal->getId() == this->id) {
            std::cout << "Purr ";
        }
        else {
            std::cout << "Meow ";
        }
    }
};

class Dog : virtual public Animal {
public:
    Dog() {
        id = 2;
    }
    virtual void voice(Animal* animal) {
        if (animal->getId() == this->id) {
            std::cout << "Woof ";
        }
        else {
            std::cout << "Bark ";
        }
    }
};

void meeting(Animal* first, Animal* second) {
    first->voice(second);
    second->voice(first);
    std::cout << std::endl;
}

int main() {
    Animal* firstCat = new Cat();
    Animal* secondCat = new Cat();
    Animal* firstDog = new Dog();
    Animal* secondDog = new Dog();

    meeting(firstCat, secondCat);
    meeting(firstCat, firstDog);
    meeting(secondDog, secondCat);
    meeting(firstDog, secondDog);

    delete firstCat;
    delete secondCat;
    delete firstDog;
    delete secondDog;

    return 0;
}
