#include <iostream>

struct Base {
    Base() {Print("Constructor");};
    virtual void Print(const std::string& value) {
        std::cout << value << " - Base" << std::endl;
    }

    virtual ~Base() {
        Print("Destructor");
    }
};

struct Child : public Base {
    Child() {Print("Constructor");};
    virtual void Print(const std::string& value) {
        std::cout << value << " - Child" << std::endl;
    }

    virtual ~Child() {
        Print("Destructor");
    }
};

int main() {
    Base* base = new Child();
    base->Print("Main ");
    delete base;

    return 0;
}
