#include <iostream>

// 1

class GamePlayer
{
private:
	static const int NumTurns = 5;

	int sources[NumTurns];
};

class GamePlayr2
{
private:
	enum
	{
		NumTurns = 5
	};

	int siurces[NumTurns];
};

class CostEstimate
{
private:
	static const double FudgeFactor;
};

const double CostEstimate::FudgeFactor = 1.35;

// 2
// bad solution
#define CALL_WITH_MAX(a, b) ((a) > (b) ? (a) : (b))

//a good solution
template <typename T>
inline T callWithMax(const T& a, const T& b)
{
	return a > b ? a : b;
}



int main(int argc, char* argv[])
{
// 2
	int a = 5;
	int b = 0;

	CALL_WITH_MAX(++a, b);
	std::cout << "a: " << a << ", b:" << b << std::endl;
	CALL_WITH_MAX(++a, b + 10);
	std::cout << "a: " << a << ", b:" << b << std::endl;

	std::cout << callWithMax(a, b) << std::endl;

	return 0;
}
