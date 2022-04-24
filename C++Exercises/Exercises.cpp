#include <iostream>
#include <assert.h>
#include "Exercises.h"

#define NONE (-1)
using namespace std;

void InputNumber(int& input, const char* msg)
{
	std::cout << msg << std::endl;
	std::cin >> input;
}
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

	std::cout << "reapeat count is " << repeatCount << endl;
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
	std::cout << "enter you would like to know is prime number : " << endl;
	std::cin >> input;
	assert(input >= 1);
	int measure = 0;
	bool isMeetMeasure = false;
	for (int i = 2; i <= input; ++i)
	{
		if (input % i == 0 && i != input)
		{
			std::cout << input << " is a NOT PRIME NUMBER!!" << endl;
			return;

		} 
		else if (i == input)
		{
			std::cout << input << " is a PRIME NUMBER!!!" << endl;
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
	std::cout << "enter start range : " << endl;
	std::cin >> start;
	std::cout << "enter end range : " << endl;
	std::cin >> end;
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
				std::cout << i << " is a PRIME NUMBER" << endl;
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
			std::cout << i << " ";

		}
		ctr = 0;
	}
	std::cout << "\n\n The total number of prime numbers between " << num1 << " to " << num2 << " is: " << fnd << endl;

#endif

}

void GetFactorial()
{
	int input;
	std::cout << "Input a number to find the factorial : " << endl;
	std::cin >> input;
	assert(input > 0);
	int res = 1;
	for (int i = 1; i <= input; ++i)
	{
		res *= i;
	}

	std::cout <<  input << "'s Factorial is : " << res << endl;

}

/*
8. Write a program in C++ to find the last prime number occur before the entered number.
Sample Output:
Input a number to find the last prime number occurs before the number: 50
47 is the last prime number before 50
*/
void GetLastPrimeNumber()
{
	int input;
	std::cout << "Input a number to find the last prime number occurs before the number:" << endl;
	std::cin >> input;
	
	assert(input > 0);

	int result = GetPrimeNumberRecursive(input - 1);

	(result == NONE) ? 
	std::cout << input <<" before PRIME NUMBER Dosen't exist." << endl : 
	std::cout << result << " is the last prime number before " << input << endl;

}
static int GetPrimeNumberRecursive(int input)
{
	if (input <= 1)
	{
		return NONE;
	}

	for (int i = 2; i <= input; ++i)
	{
		if (input % i == 0 && i != input)
		{
			break;
		}
		else if (i == input)
		{
			return i;
		}
		else
		{
			continue;
		}
	}
	GetPrimeNumberRecursive(input - 1);

}

/*
9. Write a program in C++ to find the Greatest Common Divisor (GCD) of two numbers. Go to the editor
Sample Output:
Input the first number: 25
Input the second number: 15
The Greatest Common Divisor is: 5
*/

void GetGreatestCommonDivisorOfTwoNumbers()
{
	int firstNum, secondNum;

	std::cout << "find the Greatest Common Divisor (GCD) of two numbers" << std::endl;
	
	std::cout << "Input the first number : " << std::endl;
	std::cin >> firstNum;
	assert(firstNum > 0);

	std::cout << "Input the second number : " << std::endl;
	std::cin >> secondNum;
	assert(secondNum > 0);
	int max, min;
	if (firstNum - secondNum > 0)
	{
		max = firstNum;
		min = secondNum;
	}
	else
	{
		max = secondNum;
		min = firstNum;
	}


	for (int i = min; i > 1; --i)
	{
		if (max % i == 0 && min % i == 0)
		{
			std::cout << max << " between " << min << " GCD is " << i << std::endl;
			return;
		}
	}

	std::cout << max << " between " << min << " GCD is NOT EXIST " << std::endl;


}
/*
10. Write a program in C++ to find the sum of digits of a given number. Go to the editor
Sample Output:
Input a number: 1234
The sum of digits of 1234 is: 10
*/
static int GetSumRecursive(int num, int& res)
{
	if (num == 0)
	{
		return 0;
	}

	res += (num % 10);
	GetSumRecursive(num / 10, res);
}

void GetSumOfDigit()
{
	int input;
	InputNumber(input, "Input Number: ");
	int res{};
	GetSumRecursive(input, res);
	std::cout << "The sum of digits of " << input << " is: [" << res << "]" << std::endl;

}

/*
11. Write a program in C++ to find the sum of the series 1 + 1/2^2 + 1/3^3 + ..+ 1/n^n. Go to the editor
Sample Output:
Input the value for nth term: 5
1/1^1 = 1
1/2^2 = 0.25
1/3^3 = 0.037037
1/4^4 = 0.00390625
1/5^5 = 0.00032
The sum of the above series is: 1.29126
*/
void GetSumOfTheSerise()
{
	int input;
	InputNumber(input, "Input the value for nth term");
	double res{};
	int multi{ 1 };
	for (int i = 1; i <= input; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			multi *= i;
		}
		res += (double)1 / multi;
		multi = 1;
	}
	
	std::cout << "The sum of the above series is: " << res << std::endl;

}
/*
12. Write a program in C++ to calculate the sum of the series (1*1) + (2*2) + (3*3) + (4*4) + (5*5) + ... + (n*n). Go to the editor
Sample Output:
Input the value for nth term: 5
1*1 = 1
2*2 = 4
3*3 = 9
4*4 = 16
5*5 = 25
The sum of the above series is: 55
*/

void GetCalculateTheSumOfTheSeries()
{
	int input;
	InputNumber(input, "Input the value for nth term :");
	int res{};
	for (int i = 1; i <= input; ++i)
	{
		res += i * i;
		std::cout << i << " * " << i << " = " << i * i << std::endl;
	}
	std::cout << "The sum of the above series is: " << res << std::endl;
}
/*
13. Write a program in C++ to calculate the series (1) + (1+2) + (1+2+3) + (1+2+3+4) + ... + (1+2+3+4+...+n). Go to the editor
Sample Output:
Input the value for nth term: 5
1 = 1
1+2 = 3
1+2+3 = 6
1+2+3+4 = 10
1+2+3+4+5 = 15
The sum of the above series is: 35
*/

void GetCalculateTheSeries()
{
	int input;
	InputNumber(input, "Input the value for nth term: ");
	int res{};
	int sum{};
	for (int i = 1; i <= input; ++i)
	{
		int j;
		for (j = 1; j <= i; ++j)
		{
			std::cout << j;
			if (j < i) 
			{
				std::cout << " + ";
			}
			res += j;
		}
		std::cout << " = " << res << std::endl;
		sum += res;
		res = 0;
	}

	std::cout << "The sum of the above series is: " << sum << std::endl;
}


