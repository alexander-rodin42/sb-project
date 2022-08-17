#include <iostream>
#include <string>

template <class T>
class NameObject
{
public:
	NameObject(std::string& name, const T& value) : objectValue(value)
	{
		nameValue = name;
	}

private:
	std::string& nameValue;
	const T objectValue;
};

int main(int argc, char* argv[])
{
	std::string a("1234");
	std::string b("5678");

	NameObject p(a, 2);
	NameObject p2(b, 40);

	// ���������� ������������� �� ���������� ����������� ����������� � �������� ������������
	// � ������ ���� ������� ������ �������� ������ ��� ����������� ������.
	// p = p2; // ������.

	return 0;
}

