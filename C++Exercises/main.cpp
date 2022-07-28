#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include "Exercises.h"



// Initialization of base class
class Base {
public:
	virtual ~Base() = 0;
	// Pure virtual destructor
};
Base::~Base() // Explicit destructor call
{
	std::cout << "Pure virtual destructor is called";
}
// Initialization of derived class
class Derived : public Base {
public:
	~Derived() { std::cout << "~Derived() is executed"; }
};

void MyBubbleSort(int* arr, int len)
{
	int length = len - 1;
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			std::cout << arr[length - i] << std::endl;
		}
	}
}

int GetFactorialRecursive(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return GetFactorialRecursive(n - 1) * n;
}

int ReverseNumber(int a)
{
	int res{};
	int manip = 100;
	for (int i = 0; i < 3; ++i)
	{
		res += manip * (a % 10);
		a /= 10;
		manip /= 10;
	}
	return res;
}

static bool BinarySearchRecursiveTwo(unsigned int arry[], int lIdx, int rIdx, int value)
{
	if (lIdx > rIdx)
	{
		return false;
	}

	int mid = (lIdx + rIdx) / 2;
	if (arry[mid] == value)
	{
		return true;
	}
	else if (arry[mid] < value)
	{
		BinarySearchRecursiveTwo(arry, mid + 1, rIdx, value);
	}
	else
	{
		BinarySearchRecursiveTwo(arry, lIdx, mid - 1, value);
	}


}

static void BubbleSort(unsigned int arry[], size_t size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arry[j] > arry[j + 1])
			{
				unsigned int tmp = arry[j];
				arry[j] = arry[j + 1];
				arry[j + 1] = tmp;
			}
		}
	}

}

void PrintMax()
{
	int arr[9];
	int max;
	for (int i = 0; i < 9; ++i)
	{
		std::cin >> arr[i];
	}
	max = arr[0];
	int count{ 1 };
	for (int j = 0; j < 9; ++j)
	{
		if (max < arr[j])
		{
			max = arr[j];
			count = j + 1;
		}

	}
	std::cout << max << std::endl;
	std::cout << count << std::endl;
}

int main()
{
#if 0
	const int SIZE = 16;
	unsigned int arry[SIZE] =
	{
		2, 72, 1, 32, 27, 35, 11, 25,
		12, 15, 85, 22, 98, 9, 24, 7
	};

	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << arry[i] << " ";
	}
	std::cout << std::endl;

	BubbleSort(arry, SIZE);

	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << arry[i] << " ";
	}
	std::cout << std::endl;
	int searchNum = 99;
	bool result = BinarySearchRecursiveTwo(arry, 0, SIZE - 1, searchNum);

	std::cout << "value " << searchNum << " is In arry";
	if (result)
	{
		std::cout << " Has Value!! Has " << searchNum << std::endl;
	}
	else
	{
		std::cout << " NOT Has Value. there is NO " << searchNum << std::endl;

	}
#endif
	const int SIZE = 16;
	int arry[SIZE] =
	{
		2, 72, 1, 32, 27, 35, 11, 25,
		12, 15, 85, 22, 98, 9, 24, 7
	};

	MyBubbleSort(arry, SIZE);
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << arry[i] << " ";
	}
	std::cout << std::endl;

	Base* b = new Derived();
	delete b;
    return 0;

}

