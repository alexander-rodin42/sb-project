#include <iostream>

class Uncopyable
{
public:
	Uncopyable() = default;
	~Uncopyable() = default;
	Uncopyable(const Uncopyable&) = delete;
	Uncopyable& operator=(const Uncopyable&) = delete;

private:
	/*Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);*/
};

class HomeForSale : private Uncopyable
{
};

int main(int argc, char* argv[])
{
	HomeForSale a();
	// HomeForSale b(a); //error
	HomeForSale b();
	// a = b; //error

	return 0;
}
