#include <iostream>

//#include "Dog.h"
#include "SharedPtrToy.h"

void first_ptr() {
    SharedPtrToy first("Bone");
    SharedPtrToy second("Ball");
    std::cout << "Swap: " << (*first).getName() << " and " << second->getName() << std::endl;
    first.swap(second);

    SharedPtrToy third(first);
    SharedPtrToy fourth("Mouse");

    std::cout << "Bone - " << second.use_count() << " , Ball - " << third.use_count()
              << " , Mouse - " << fourth.use_count() << std::endl;
    std::cout << std::boolalpha << "Check unique: " << "Bone - " << second.unique() << " , Ball - " << third.unique()
              << " , Mouse - " << fourth.unique() << std::endl;

    third = second;
    fourth.reset();
    if (!fourth) {
        std::cout << "Mouse - " << fourth.use_count() << std::endl;
        std::cout << std::boolalpha << "Check unique: Mouse - " << fourth.unique() << std::endl;
    }

    std::cout << std::boolalpha << "Check \"owner_before\": first and second - " << first.owner_before(second)
                                << ", second and third - " << second.owner_before(third)
                                << ", third and fourth - " << third.owner_before(fourth) << std::endl;
    Toy* pb = first.get();
    first = second;
}

SharedPtrToy make_shared_toy(const std::string name) {
    return SharedPtrToy("Bone");
}

SharedPtrToy make_shared_toy(const SharedPtrToy& toy) {
    const auto& a(toy);
    return a;
}

int main() {
    //Dog a("Sharik", "Ball", 5);
    //first_ptr();

    auto a = make_shared_toy("Ball");
    auto b = make_shared_toy(a);
    //a.reset();
    //b.reset();
    std::cout << b.use_count() << std::endl;

    return 0;
}
