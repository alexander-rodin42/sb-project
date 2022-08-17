#include <iostream>

class MyClass
{
public:
	MyClass() : firstValue(0), secondValue(0) {}
	MyClass(const int inFirstValue, const int inSecondValue) : firstValue(inFirstValue), secondValue(inSecondValue) {}

	MyClass(const MyClass& other) : firstValue(other.firstValue), secondValue(other.secondValue) {}

	MyClass& operator=(const MyClass& other)
	{
		firstValue = other.firstValue;
		secondValue = other.secondValue;
		return *this;
	}

	MyClass& operator+=(const MyClass& other)
	{
		firstValue += other.firstValue;
		secondValue += other.secondValue;
		return *this;
	}

	MyClass& operator-=(const MyClass& other)
	{
		firstValue -= other.firstValue;
		secondValue -= other.secondValue;
		return *this;
	}

	MyClass& operator*=(const MyClass& other)
	{
		firstValue *= other.firstValue;
		secondValue *= other.secondValue;
		return *this;
	}

	MyClass& operator/=(const MyClass& other)
	{
		firstValue /= other.firstValue;
		secondValue /= other.secondValue;
		return *this;
	}

	MyClass& operator%=(const MyClass& other)
	{
		firstValue %= other.firstValue;
		secondValue %= other.secondValue;
		return *this;
	}

	int getFirst() const
	{
		return firstValue;
	}

	int getSecond() const
	{
		return secondValue;
	}

private:
	int firstValue;
	int secondValue;
};

int main(int argc, char* argv[])
{
	MyClass a(3, 1);
	std::cout << "a(3, 1) : " << a.getFirst() << ", " << a.getSecond() << std::endl;
	MyClass b = {2, 3};
	std::cout << "b = {2, 3} : " << b.getFirst() << ", " << b.getSecond() << std::endl;
	MyClass c;
	std::cout << "c : " << c.getFirst() << ", " << c.getSecond() << std::endl;

	c = b;
	std::cout << "c = b : " << c.getFirst() << ", " << c.getSecond() << std::endl;
	c += a;
	std::cout << "c += a : " << c.getFirst() << ", " << c.getSecond() << std::endl;
	c *= b;
	std::cout << "c *= b : " << c.getFirst() << ", " << c.getSecond() << std::endl;
	c %= a;
	std::cout << "c %= a : " << c.getFirst() << ", " << c.getSecond() << std::endl;

	c = c;
	std::cout << "c = c : " << c.getFirst() << ", " << c.getSecond() << std::endl;

	return 0;
}
