#include <iostream>
#include <assert.h>
#include "Exercises.h"
using namespace std;
void GetPerfectNumberBeetween1And500()
{
	const int END = 500;
	int repeatCount = 0;
// My Code
#if 1
	for (int i = 2; i <= END; ++i)
	{
		++repeatCount;
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
			++repeatCount;
		}
	}

	cout << "reapeat count is " << repeatCount << endl;
#endif
	// Answer Code 
#if 0
	cout << "\n\n Find the perfect numbers between 1 and 500:\n";
	cout << "------------------------------------------------\n";
	int i = 1, u = 1, sum = 0;
	cout << "\n The perfect numbers between 1 to 500 are: \n";
	while (i <= 500)
	{
		while (u <= 500)
		{
			if (u < i)
			{
				if (i % u == 0)
					sum = sum + u;
			}
			u++;
			++repeatCount;

		}
		if (sum == i) {
			cout << i << "  " << "\n";
		}
		i++;
		u = 1;
		sum = 0;
		++repeatCount;
	}
	cout << "reapeat count is " << repeatCount << endl;

#endif 
}
void IsPrimeNumer()
{
	// 내 코드가 정답코드보다 더 복잡하지만, 반복횟수는 더 적다.
	// 뭐가 더 맞는 방법인지는... 모르겠옹
	int input;
	cout << "enter you would like to know is prime number : " << endl;
	cin >> input;
	assert(input >= 1);
	int measure = 0;
	bool isMeetMeasure = false;
	for (int i = 2; i <= input; ++i)
	{
		if (input % i == 0 && i != input)
		{
			cout << input << " is a NOT PRIME NUMBER!!" << endl;
			return;

		} else if (i == input)
		{
			cout << input << " is a PRIME NUMBER!!!" << endl;
			return;
		}
	}

	// Answer Code 
#if 0
	int num1, ctr = 0;
	cout << "\n\n Check whether a number is prime or not:\n";
	cout << "--------------------------------------------\n";
	cout << " Input a number to check prime or not: ";
	cin >> num1;
	for (int a = 1; a <= num1; a++)
	{
		if (num1 % a == 0)
		{
			ctr++;
		}
	}
	if (ctr == 2)
	{
		cout << " The entered number is a prime number. \n";
	}
	else {
		cout << " The number you entered is not a prime number. \n";
	}
#endif

}
void GetPrimenumberRange()
{
	int start, end;
	cout << "enter start range : " << endl;
	cin >> start;
	cout << "enter end range : " << endl;
	cin >> end;
	assert(start < end && start > 0);

	for (int i = start; i <= end; ++i)
	{
		for (int divisor = 2; divisor <= i; ++divisor)
		{
			if (i % divisor == 0 && divisor != i)
			{
				break;
			}
			else if (divisor == i)
			{
				cout << i << " is a PRIME NUMBER" << endl;
				break;
			}
		}
	}

	// Answer Code
#if 0
	int num1, num2;
	int fnd = 0, ctr = 0;
	cout << "\n\n Find prime number within a range:\n";
	cout << "--------------------------------------\n";
	cout << " Input number for starting range: ";
	cin >> num1;
	cout << " Input number for ending range: ";
	cin >> num2;

	cout << "\n The prime numbers between " << num1 << " and " << num2 << " are:" << endl;
	for (int i = num1; i <= num2; i++)
	{
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
				ctr++;
		}
		if (ctr == 0 && i != 1)
		{
			fnd++;
			cout << i << " ";

		}
		ctr = 0;
	}
	cout << "\n\n The total number of prime numbers between " << num1 << " to " << num2 << " is: " << fnd << endl;

#endif

}

void GetFactorial()
{
	int input;
	cout << "Input a number to find the factorial : " << endl;
	cin >> input;
	assert(input > 0);
	int res = 1;
	for (int i = 1; i <= input; ++i)
	{
		res *= i;
	}

	cout <<  input << "'s Factorial is : " << res << endl;

}

