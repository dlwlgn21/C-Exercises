#include <iostream>
#include "Exercises.h"
void GetPerfectNumberBeetween1And500()
{
	const int END = 500;
	for (int i = 2; i <= END; ++i)
	{
		int res = 0;
		for (int j = 1; j < i; ++j)
		{
			if (res == i && j == i - 1) 
			{
				std::cout << "Perfect Number is " << res << std::endl;
				break;
			}
			if (i % j == 0) 
			{
				res += j;
			}
		}
	}
}
