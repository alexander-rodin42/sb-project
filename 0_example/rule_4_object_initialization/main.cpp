#include <iostream>
#include <string>
#include <list>

class PhoneNumber
{
};

class ABEntry
{
public:
	ABEntry() : theName(), theAddress(), thePhones(), numTimesConsulted(0) {}

private:
	std::string theName;
	std::string theAddress;
	std::list<PhoneNumber> thePhones;
	int numTimesConsulted;
};

int main(int argc, char* argv[])
{
	return 0;
}
