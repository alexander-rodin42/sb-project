#include <iostream>

class BaseClass
{
public:
	BaseClass()
	{
		std::cout << "BaseClass()" << std::endl;
	}
	virtual ~BaseClass() = 0;

private:
};

BaseClass::~BaseClass()
{
	std::cout << "~BaseClass()" << std::endl;
}

class ChildClass : public BaseClass
{
public:
	ChildClass()
	{
		std::cout << "ChildClass()" << std::endl;
	}

	virtual ~ChildClass()
	{
		std::cout << "~ChildClass()" << std::endl;
	}

private:
};

int main(int argc, char* argv[])
{
	BaseClass* a = new ChildClass();
	delete a;

	// BaseClass b; //error

	return 0;
}
