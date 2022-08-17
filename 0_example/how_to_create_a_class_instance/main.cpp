#include <iostream>

struct Base {
  Base() { Print("Constructor"); };
  virtual ~Base() { Print("Destructor"); }

  virtual void Print(const std::string &value) {
    std::cout << value << " - Base" << std::endl;
  }
};

struct Child : public Base {
  Child() { Print("Constructor"); };
  virtual ~Child() { Print("Destructor"); }

  virtual void Print(const std::string &value) {
    std::cout << value << " - Child" << std::endl;
  }
};

int main() {
  Base *base = new Child();
  base->Print("Main");
  delete base;

  std::cout << "-----------------" << std::endl;

  Child *child = new Child();
  child->Print("Main");
  delete child;

  return 0;
}
