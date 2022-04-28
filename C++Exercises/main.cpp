#include <iostream>
#include "Exercises.h"


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
	PrintTriangleFour();
}