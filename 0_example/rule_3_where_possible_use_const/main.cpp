#include <iostream>
#include <vector>

// 2
class Rational
{
public:
	Rational(const int& inValue = 0) : value(inValue) {}
	int getValue() const
	{
		return value;
	}

private:
	int value;
};

const Rational operator*(const Rational& rValue, const Rational& lValue)
{
	return Rational(rValue.getValue() * lValue.getValue());
}

// 3
class TextBook
{
public:
	explicit TextBook(const std::string& inText = "") : text(inText) {}

	char& operator[](std::size_t position)
	{
		std::cout << "Not constant []." << std::endl;
		return text[position];
	}

	const char& operator[](std::size_t position) const
	{
		std::cout << "Constant []." << std::endl;
		return text[position];
	}


private:
	std::string text;
};

// 4

class CTextBlock
{
public:
	explicit CTextBlock(const char* inText);

private:
	char* pText;

	mutable std::size_t textLength;  //��� ������-����� ������ ����� ���� ��������������,
	mutable bool lengthIsValid;  //���� � ����������� �������� ������
};

int main(int argc, char* argv[])
{
	// 3
	int greeting = 2;

	int* p1 = &greeting;        //������������� ���������, ������������� ������
	const int* p2 = &greeting;  //������������� ���������, ����������� ������
	int* const p3 = &greeting;  //����������� ���������, ������������� ������
	const int* const p4 = &greeting;  //����������� ���������, ����������� ������

	std::vector<int> vec = {1, 2, 3};
	const std::vector<int>::iterator iterator1 = vec.begin();      //����������� ���������
	std::vector<int>::const_iterator iterator2 = vec.begin() + 1;  //��������� �� ���������

	*iterator1 + 10;
	//++iterator1; //error

	//*iterator2 += 10; //error
	++iterator2;

	std::cout << *iterator1 << " " << *iterator2 << std::endl;  // 1 3

	// 2

	Rational first(10);
	Rational second = 20;
	Rational thrid = first * second;

	std::cout << thrid.getValue() << std::endl;             // 200
	std::cout << (first * second).getValue() << std::endl;  // 200

	// 3

	TextBook text1("0123456789");
	const TextBook text2("abcd");

	std::cout << text1[4] << std::endl;
	std::cout << text2[2] << std::endl;

	// std::cout << text1[11] << std::endl; //error

	return 0;
}
