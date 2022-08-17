#include <iostream>

void logCall(const std::string& message)
{
	std::cout << message << std::endl;
}

class Customer
{
public:
	Customer() : name("no name") {}

	explicit Customer(const std::string& inName) : name(inName) {}

	Customer(const Customer& other) : name(other.name)
	{
		logCall("Copy constructor: Castomer");
	}

	Customer& operator=(const Customer& other)
	{
		logCall("Copy assignment operator: Castomer");
		name = other.name;
		return *this;
	}

	std::string getName() const
	{
		return name;
	}

	void setName(const std::string& inName)
	{
		name = inName;
	}

private:
	std::string name;
};

class PriorityCustomer : public Customer
{
public:
	PriorityCustomer() : Customer(), priority(0) {}

	explicit PriorityCustomer(const std::string& inName, const int inPriority) : priority(inPriority), Customer(inName) {}

	PriorityCustomer(const PriorityCustomer& other) : PriorityCustomer(other.getName(), other.priority)
	{
		logCall("Copy constructor: PriorityCustomer");
	}

	PriorityCustomer& operator=(const PriorityCustomer& other)
	{
		logCall("Copy assignment operator: PriorityCustomer");
		setName(other.getName());
		priority = other.priority;
		return *this;
	}

	void printInfo()
	{
		std::cout << getName() << " " << priority << std::endl;
	}

private:
	int priority;
};

class SecondPriorityCustomer : public Customer
{
public:
	SecondPriorityCustomer() : Customer(), priority(0) {}

	explicit SecondPriorityCustomer(const int inPriority) : priority(inPriority) {}

	//в примере из книги вызывается : Customer(other)      тут---V

	SecondPriorityCustomer(const SecondPriorityCustomer& other) : SecondPriorityCustomer(other.priority)
	{
		logCall("Copy constructor: SecondPriorityCustomer");
	}

	SecondPriorityCustomer& operator=(const SecondPriorityCustomer& other)
	{
		logCall("Copy assignment operator: SecondPriorityCustomer");
		Customer::operator=(other);
		priority = other.priority;
		return *this;
	}

	void printInfo()
	{
		std::cout << getName() << " " << priority << std::endl;
	}

private:
	int priority;
};

int main(int argc, char* argv[])
{
	PriorityCustomer first("Bob", 1);
	first.printInfo();

	PriorityCustomer second(first);
	second.printInfo();

	PriorityCustomer third;
	third = second;
	third.printInfo();

	SecondPriorityCustomer first2(2);
	first2.setName("Mark");
	first2.printInfo();

	SecondPriorityCustomer second2(first2);
	second2.printInfo();

	SecondPriorityCustomer third2;
	second2.setName("Toto");
	third2 = second2;
	third2.printInfo();

	return 0;
}
