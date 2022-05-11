#include <iostream>
#include <assert.h>
#include <stack>
#include "Exercises.h"
#define NONE (-1)
using namespace std;

void InputNumber(int& input, const char* msg)
{
	std::cout << msg << std::endl;
	if (std::cin >> input)
	{

	}
	else
	{
		std::cout << "Wrong Input" << std::endl;
		assert(false);
	}
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
	assert(start < end&& start > 0);

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

	std::cout << input << "'s Factorial is : " << res << endl;

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
		std::cout << input << " before PRIME NUMBER Dosen't exist." << endl :
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
	int sum{};
	for (int i = 1; i <= input; ++i)
	{
		sum += i * i;
		std::cout << i << " * " << i << " = " << i * i << std::endl;
	}
	std::cout << "The sum of the above series is: " << sum << std::endl;
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


/*
14. Write a program in C++ to find the sum of series
1 - X^2/2! + X^4/4!-.... upto nth term.
Sample Output:
Input the value of X: 3
Input the value for nth term: 4
term 1 value is: 1
term 2 value is: -4.5
term 3 value is: 3.375
term 4 value is: -1.0125
The sum of the above series is: -1.1375
*/

void GetFindTheSumOfSeriesUPToNthTerm()
{
	int x, nthTerm;
	InputNumber(x, "Input the value of X: ");
	InputNumber(nthTerm, "Input the value for nth term: ");
	float res = 1.f;
	float sum{};
	int expo = 2;
	for (int i = 1; i <= nthTerm; ++i)
	{
		if (i % 2 == 0)
		{
			res = -res;
		}
		std::cout << "term " << i << " value is :" << res << std::endl;
		float multi = 1;
		float facto = 1;
		for (int j = 1; j <= expo; ++j)
		{
			multi *= x;
			facto *= j;
		}
		sum += res;
		res = multi / facto;
		expo += 2;
	}
	std::cout << "The sum of the above series is: " << sum << std::endl;

}

/*
15. Write a program in C++ to asked user to
input positive integers to process count, maximum, minimum, and average or terminate the process with -1.
Sample Output:
Your input is for termination. Here is the result below:
Number of positive integers is: 4
The maximum value is: 9
The minimum value is: 3
The average is 6.00


*/
void GetMaxMinAverage()
{
	int numsOfPosInt;
	int max{};
	int min{};
	float average{};
	std::cout << "Input positive integers to process count, maximum, minimum, and average or terminate the process with -1" << std::endl;

	while (std::cin >> numsOfPosInt && numsOfPosInt > 0)
	{
		std::cout << "You Must Input " << numsOfPosInt << " times" << std::endl;
		int* inputNums = new int[numsOfPosInt];
		for (int i = 0; i < numsOfPosInt; ++i)
		{
			std::cout << i + 1 << "st Input.\n" << "\tInput integer :";
			std::cin >> inputNums[i];
		}
		max = inputNums[0];
		min = inputNums[0];

		for (int i = 0; i < numsOfPosInt; ++i)
		{
			if (max < inputNums[i])
			{
				max = inputNums[i];
			}
			if (min > inputNums[i])
			{
				min = inputNums[i];
			}
			average += inputNums[i];
		}

		std::cout << "The maximum value is " << max << std::endl;
		std::cout << "The minimum value is " << min << std::endl;
		std::cout << "The average value is " << average / numsOfPosInt << std::endl;
		max = 0;
		min = 0;
		average = 0.f;
		delete[] inputNums;
		std::cout << "Input positive integers to process count, maximum, minimum, and average or terminate the process with -1" << std::endl;

	}


}


/*
16. Write a program in C++ to list non-prime numbers from 1 to an upperbound. Go to the editor
Sample Output:
Input the upperlimit: 25
The non-prime numbers are:
4 6 8 9 10 12 14 15 16 18 20 21 22 24 25

*/

void GetNonPrimeNumbers()
{

	int upperLimit;

	InputNumber(upperLimit, "Input the upperlimit: ");
	for (int i = 2; i <= upperLimit; ++i)
	{
		for (int j = 2; j <= i; ++j)
		{
			if (i % j == 0 && i != j)
			{
				std::cout << i << " ";
				break;
			}
			else if (i == j)
			{
				continue;
			}

		}
	}

#if 0
	// 정답코드
	int ult;
	cout << "\n\n List non-prime numbers from 1 to an upperbound:\n";
	cout << "----------------------------------------------------\n";
	cout << " Input the upperlimit: ";
	cin >> ult;
	cout << " The non-prime numbers are: " << endl;
	for (int num = 2; num <= ult; ++num)
	{
		int mfactor = (int)sqrt(num);
		std::cout << "mFactor" << mfactor << std::endl;
		for (int fact = 2; fact <= mfactor; ++fact)
		{
			if (num % fact == 0)
			{
				cout << num << " ";
				break;
			}
		}
	}
	cout << endl;
#endif
}

/*
17. Write a program in C++ to print a square pattern with # character.
Sample Output:
Print a pattern like square with # character:
--------------------------------------------------
Input the number of characters for a side: 4
# # # #
# # # #
# # # #
# # # #
*/
void PrintSquare()
{
	int sides;
	InputNumber(sides, "Input the number of characters for a side: ");

	for (int i = 0; i < sides; ++i)
	{
		for (int j = 0; j < sides; ++j)
		{
			std::cout << "# ";
		}
		std::cout << std::endl;
	}

}

/*
18. Write a program in C++ to display the cube of the number upto given an integer. Go to the editor
Sample Output:
Input the number of terms : 5
Number is : 1 and the cube of 1 is: 1

Number is : 2 and the cube of 2 is: 8
Number is : 3 and the cube of 3 is: 27
Number is : 4 and the cube of 4 is: 64
Number is : 5 and the cube of 5 is: 125

*/

void PrintTheCubeOfNumber()
{
	int terms;
	InputNumber(terms, "Input the number of terms : ");

	int x{};
	for (int i = 1; i <= terms; ++i)
	{
		x = i * i * i;
		std::cout << "Number is : " << i << " and the cube of " << i << " is: " << x << std::endl;
	}
}

/*
19. Write a program in C++ to display the multiplication table vertically from 1 to n. Go to the editor
Sample Output:
Input the number upto: 5
Multiplication table from 1 to 5
1x1=1 2x1=2 3x1=3 4x1=4 5x1=5
1x2=2 2x2=4 3x2=6 4x2=8 5x2=10
1x3=3 2x3=6 3x3=9 4x3=12 5x3=15
1x4=4 2x4=8 3x4=12 4x4=16 5x4=20
1x5=5 2x5=10 3x5=15 4x5=20 5x5=25
1x6=6 2x6=12 3x6=18 4x6=24 5x6=30
1x7=7 2x7=14 3x7=21 4x7=28 5x7=35
1x8=8 2x8=16 3x8=24 4x8=32 5x8=40
1x9=9 2x9=18 3x9=27 4x9=36 5x9=45
1x10=10 2x10=20 3x10=30 4x10=40 5x10=50
*/

void PrintMultiplicationVerticaly()
{
	int upto;
	InputNumber(upto, "Input the number upto: ");
	std::cout << "Multiplication table from 1 to " << upto << std::endl;

	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= upto; ++j)
		{
			std::cout << j << " X " << i << " = " << i * j << " ";
		}
		std::cout << std::endl;
	}


}
/*
20. Write a program in C++ to display the n terms of odd natural number and their sum. Go to the editor
Sample Output:
Input number of terms: 5
The odd numbers are: 1 3 5 7 9
The Sum of odd Natural Numbers upto 5 terms: 25
*/
void GetOddSum()
{
	int terms;
	InputNumber(terms, "Input number of terms: ");
	int sum{};
	// 사실 걍 std::cout << terms * terms << std::endl;
	for (int i = 1; i <= terms * 2; ++i)
	{
		int res{};
		res = 2 * i - 1;
		std::cout << res << " ";
		sum += res;
	}
	std::cout << std::endl;

	std::cout << "The Sum of odd Natural Numbers upto " << terms << " terms: " << sum << std::endl;

}

/*
21. Write a program in C++ to display the n terms of even natural number and their sum. Go to the editor
Sample Output:
Input number of terms: 5
The even numbers are: 2 4 6 8 10
The Sum of even Natural Numbers upto 5 terms: 30
*/
void GetEvenSum()
{
	int terms;
	InputNumber(terms, "Input number of terms: ");
	int sum{};
	for (int i = 1; i <= terms; ++i)
	{
		int res{};
		res = 2 * i;
		std::cout << res << " ";
		sum += res;

	}
	std::cout << std::endl;

	std::cout << "The Sum of even Natural Numbers upto " << terms << " terms: " << sum << std::endl;

}

int BinarySearchRecursive(unsigned int arry[], int lIdx, int rIdx, int value)
{
	static int count = 0;
	if (lIdx > rIdx)
	{
		return -1;
	}

	//
	int mid = (lIdx + rIdx) / 2;
	std::cout << ++count << "th enter. mid Index is " << mid << " arry[mid] is " << arry[mid] << std::endl;
	if (arry[mid] == value)
	{
		return arry[mid];
	}
	if (arry[mid] < value)
	{
		BinarySearchRecursive(arry, mid + 1, rIdx, value);
	}
	else if (arry[mid] > value)
	{
		BinarySearchRecursive(arry, lIdx, mid - 1, value);
	}

}

/*
22. Write a program in C++ to display the n terms of harmonic series and their sum.
1 + 1/2 + 1/3 + 1/4 + 1/5 ... 1/n terms
Sample Output:
Input number of terms: 5
1/1 + 1/2 + 1/3 + 1/4 + 1/5
The sum of the series upto 5 terms: 2.28333
*/

void GetHarmonicSeriesSum()
{
	int term;
	InputNumber(term, "Input number of terms: ");
	float sum{};
	for (int i = 1; i <= term; ++i)
	{
		std::cout << "1/" << i;
		if (i < term)
		{
			std::cout << " + ";
		}
		sum += static_cast<float>(1) / i;
	}
	std::cout << std::endl;
	std::cout << "The sum of the series upto " << term << " terms: " << sum << std::endl;
}

/*
23. Write a program in C++ to display the sum of the series [ 9 + 99 + 999 + 9999 ...].
Sample Output:
Input number of terms: 5
9 99 999 9999 99999
The sum of the sarise = 111105
*/
void GetNineSumOfTheSeries()
{
	int term;
	InputNumber(term, "Input number of terms: ");

	long sum{};
	long out = 10;
	for (int i = 1; i <= term; ++i)
	{
		std::cout << out - 1 << " ";
		if (i < term)
		{
			std::cout << " + ";
		}
		sum += out - 1;
		out = (out * 10);
	}
	std::cout << std::endl;
	std::cout << "The sum of the series upto " << term << " terms: " << sum << std::endl;
}
void GetNineSumOfTheSeriesAnswer()
{
	long int n, i, t = 9;
	int sum = 0;
	cout << "\n\n Display the sum of the series [ 9 + 99 + 999 + 9999 ...]\n";
	cout << "-------------------------------------------------------------\n";
	cout << " Input number of terms: ";
	cin >> n;

	for (i = 1; i <= n; i++)
	{
		sum += t;
		cout << t << "  ";
		t = t * 10 + 9;
	}
	cout << "\n The sum of the sarise = " << sum << endl;
}
/*
24. Write a program in C++ to display the sum of the series [ 1+x+x^2/2!+x^3/3!+.... ].
Sample Output:
Input the value of x: 3
Input number of terms: 5
The sum is : 16.375

*/

void GetSumOfSeriesMystery()
{
	int x, term;
	InputNumber(x, "Input the value of x: ");
	InputNumber(term, "Input number of terms: ");
	float sum = 1 + x;
	for (int i = 1; i < term - 1; ++i)
	{
		int multi = x;
		int facto = 1;
		for (int j = 1; j <= i; ++j)
		{
			multi *= x;
		}
		for (int j = 1; j <= i + 1; ++j)
		{
			facto *= j;
		}
		std::cout << i << "th " << multi << " " << facto << std::endl;
		sum += static_cast<float>(multi) / facto;

	}
	std::cout << "The sum is : " << sum;
}
void GetSumOfSeriesMysteryAnswerCode()
{
	float x, sum, no_row;
	int i, n;
	cout << "\n\n Display the sum of the series [ 1+x+x^2/2!+x^3/3!+....]\n";
	cout << "------------------------------------------------------------\n";
	cout << " Input the value of x: ";
	cin >> x;
	cout << " Input number of terms: ";
	cin >> n;
	sum = 1;
	no_row = 1;
	for (i = 1; i < n; i++)
	{
		no_row = no_row * x / (float)i;
		sum = sum + no_row;
	}
	cout << " The sum  is : " << sum << endl;
}

/*
25. Write a program in C++ to find the sum of the series [ x - x^3 + x^5 + ......].
Sample Output:
Input the value of x: 2
Input number of terms: 5
The values of series:
2
-8
32
-128
512
The sum of the series upto 5 term is: 410

*/
void GetSumOfSeriesMysteryTwo()
{
	int x, term;
	InputNumber(x, "Input the value of x: ");
	InputNumber(term, "Input number of terms: ");

	int sum{};
	int multi{ 1 };
	for (int i = 1; i <= term; ++i)
	{
		int oddTime = 2 * i - 1;
		for (int j = 0; j < oddTime; ++j)
		{
			multi *= x;
		}
		// if even
		if ((i & 0x1) == 0)
		{
			multi = -multi;
		}
		std::cout << multi << std::endl;

		sum += multi;
		multi = 1;
	}
	std::cout << "The sum of the series upto 5 term is: " << sum << std::endl;

}
void GetSumOfSeriesMysteryTwoAnswerCode()
{
	float x, sum, ctr;
	int i, n, m, mm, nn = 0;
	cout << "\n\n Display the sum of the series [ x - x^3 + x^5 + ......]\n";
	cout << "------------------------------------------------------------\n";
	cout << " Input the value of x: ";
	cin >> x;
	cout << " Input number of terms: ";
	cin >> n;
	sum = x;
	m = -1;
	cout << "The values of series:" << endl;
	cout << sum << endl;
	for (i = 1; i < n; i++) {
		ctr = (2 * i + 1);
		mm = pow(x, ctr);
		nn = mm * m;
		cout << nn << endl;
		sum = sum + nn;
		m = m * (-1);
	}
	cout << "\n The sum of the series upto " << n << " term is: " << sum << endl;
}

/*
26. Write a program in C++ to find the sum of the series 1 +11 + 111 + 1111 + .. n terms.
Sample Output:
Input number of terms: 5
1 + 11 + 111 + 1111 + 11111
The sum of the series is: 12345
*/
static int GetOneSumRecrisive(int num)
{
	if (num == 1)
	{
		return 1;
	}
	return num + GetOneSumRecrisive(num / 10);
}
void GetSumOfSeriesMysteryThree()
{
	int term;
	InputNumber(term, "Input number of terms: ");
	int times{ 1 };
	int sum{ 0 };
	/*
	for (int i = 1; i < term; ++i)
	{
		std::cout << times << std::endl;
		times *= 10;
		sum += GetOneSumRecrisive(times);
	}
	*/
	for (int i = 1; i <= term; ++i)
	{
		std::cout << times << " ";
		if (i < term)
		{
			std::cout << " + ";
		}
		sum += times;
		times = (times * 10) + 1;
	}
	std::cout << std::endl;
	std::cout << "The sum of the series is :" << sum << std::endl;
}
void GetSumOfSeriesMysteryThreeAnswerCode()
{
	int n, i, sum = 0;
	int t = 1;
	cout << "\n\n Display the sum of the series 1 +11 + 111 + 1111 + .. n terms:\n";
	cout << "-------------------------------------------------------------------\n";
	cout << " Input number of terms: ";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << t << " ";
		if (i < n)
		{
			cout << "+ ";
		}
		sum = sum + t;
		t = (t * 10) + 1;
	}
	cout << "\n The sum of the series is: " << sum << endl;
}

/*
27. Write a program in C++ to display the first n terms of Fibonacci series.
Sample Output:
Input number of terms to display: 10
Here is the Fibonacci series upto to 10 terms:
0 1 1 2 3 5 8 13 21 34
*/
static int GetFibonacciRecursive(int num)
{
	if (num == 0)
	{
		return 0;
	}
	if (num == 1)
	{
		return 1;
	}

	return GetFibonacciRecursive(num - 2) + GetFibonacciRecursive(num - 1);
}

void GetFibonacci()
{
	int term;
	InputNumber(term, "Input number of terms to display: ");
	assert(term > 0);
	int res = GetFibonacciRecursive(term - 1);

	int before, cur, tmp;
	before = 0;
	cur = 1;
	std::cout << "----------" << std::endl;
	std::cout << "Here is the Fibonacci series upto to " << term << " terms :" << std::endl;
	for (int i = 0; i < term; ++i)
	{
		tmp = cur;
		cur = before + cur;
		std::cout << before << " ";
		before = tmp;
	}
	std::cout << std::endl;


}
/*
28. Write a program in C++ to find the number and s
um of all integer between 100 and 200 which are divisible by 9.
Sample Output:
Numbers between 100 and 200, divisible by 9:
108 117 126 135 144 153 162 171 180 189 198
The sum : 1683
*/
void GetDivisibleByNineBeetween100And200()
{
	std::cout << "Numbers between 100 and 200, divisible by 9:" << std::endl;
	int min, max, sum;
	sum = 0;
	min = 9 * 12;
	max = 200;
	while (min <= max)
	{
		std::cout << min << " ";
		sum += min;
		min += 9;
	}

	std::cout << "The sum : " << sum << std::endl;
}

/*
29. Write a program in C++ to find LCM of any two numbers using HCF. Go to the editor
Sample Output:
Input 1st number for LCM: 15
Input 2nd number for LCM: 25
The LCM of 15 and 25 is: 75
*/

void GetFirstLCM()
{
	int first, second;
	InputNumber(first, "Input 1st number for LCM: ");
	InputNumber(second, "Input 2nd number for LCM: ");
	int min = (first < second) ? first : second;
	int hcf{ 1 };
	int lcm{};
	for (int i = min; i >= 1; --i)
	{
		if (first % i == 0 && second % i == 0)
		{
			hcf = i;
			break;
		}
	}

	std::cout << first << " and " << second << " LCM is " << (first * second) / hcf << std::endl;

}
void GetFirstLCMAnswer()
{
	int i, n1, n2, j, hcf = 1, lcm;
	cout << "\n\n LCM of two numbers:\n";
	cout << "------------------------\n";
	cout << " Input 1st number for LCM: ";
	cin >> n1;
	cout << " Input 2nd number for LCM: ";
	cin >> n2;
	j = (n1 < n2) ? n1 : n2;
	for (i = 1; i <= j; i++) {

		if (n1 % i == 0 && n2 % i == 0) {
			hcf = i;
		}
	}
	/* mltiplication of HCF and LCM = the multiplication of these two numbers.*/
	lcm = (n1 * n2) / hcf;
	cout << " The LCM of " << n1 << " and " << n2 << " is: " << lcm << endl;
}
/*
30. Write a program in C++ to display the number in reverse order. Go to the editor
Sample Output:
Input a number: 12345
The number in reverse order is : 54321

*/
void GetReverseOrder()
{
	int num;
	InputNumber(num, "Input a number to reverse: ");
	int cpy = num;
	int digit{};
	int cut = {};
	while (cpy != 0)
	{
		cpy /= 10;
		++digit;
	}
	cpy = num;
	std::cout << num << "'s digit is " << digit << std::endl;
	for (int i = digit; i >= 1; --i)
	{
		int power = 1;
		for (int j = 0; j < i - 1; ++j)
		{
			power *= 10;
		}
		cut += (power) * (cpy % 10);
		std::cout << power << " " << cpy % 10 << std::endl;
		cpy /= 10;

	}


	std::cout << num << " reverse order is " << cut << std::endl;

}
void GetReverseOrderAnswer()
{
	int num, r, sum = 0, t;
	cout << "\n\n Display the number in reverse order:\n";
	cout << "-----------------------------------------\n";
	cout << " Input a number: ";
	cin >> num;
	for (t = num; num != 0; num = num / 10)
	{
		r = num % 10;
		std::cout << "r = num % 10 is  " << r << std::endl;

		sum = sum * 10 + r;
		std::cout << "sum = sum * 10 + r is " << sum << std::endl;
	}
	cout << " The number in reverse order is : " << sum << endl;
}

/*
31. Write a program in C++ to find out the sum of an A.P. series. Go to the editor
Sample Output:
Input the starting number of the A.P. series: 1
Input the number of items for the A.P. series: 8
Input the common difference of A.P. series: 5
The Sum of the A.P. series are :
1 + 6 + 11 + 16 + 21 + 26 + 31 + 36 = 148
*/
void GetAritimeticProgressionSeries()
{
	int first, end, diff;
	InputNumber(first, "Input the starting number of the A.P. series: ");
	InputNumber(end, "Input the number of items for the A.P. series: ");
	InputNumber(diff, "Input the common difference of A.P. series: ");
	int sum{};
	int realFirst = first;
	std::cout << "The Sum of the A.P. series are :" << std::endl;
	for (int i = 0; i < end; ++i)
	{
		sum += first;
		std::cout << first << " ";
		if (i < end)
		{
			std::cout << " + ";
		}
		first += diff;

	}

	std::cout << " = " << sum << std::endl;
}

/*
32. Write a program in C++ to find the Sum of GP series. Go to the editor
Sample Output:
Input the starting number of the G.P. series: 3
Input the number of items for the G.P. series: 5
Input the common ratio of G.P. series: 2
The numbers for the G.P. series:
3 6 12 24 48
The Sum of the G.P. series: 93

*/

void GetGeomerticProgression()
{
	int first, end, ratio;
	InputNumber(first, "Input the starting number of the A.P. series: ");
	InputNumber(end, "Input the number of items for the A.P. series: ");
	InputNumber(ratio, "Input the common difference of A.P. series: ");
	int sum{};
	std::cout << "The numbers for the G.P series:" << std::endl;
	for (int i = 0; i < end; ++i)
	{
		sum += first;
		std::cout << first << " ";
		first *= ratio;
	}
	std::cout << std::endl;

	std::cout << "The numbers for the G.P series:" << sum << std::endl;

}
/*
33. Write a program in C++ to Check Whether a Number can be Express as Sum of Two Prime Numbers. Go to the editor
Sample Output:
Input a positive integer: 20
20 = 3 + 17
20 = 7 + 13

*/

void GetSumTwoPrimeNumber()
{
	int num;
	InputNumber(num, "Input a positive integer: ");

}


/*
34. Write a program in C++ to find the length of a string without using the library function. Go to the editor
Sample Output:
Input a string: w3resource.com
The string contains 14 number of characters.
So, the length of the string w3resource.com is:14
*/

void GetStringLength()
{
	const size_t BUFFER_LEN = 512;
	char buffer[BUFFER_LEN];
	std::cout << "input your string : ";
	std::cin >> buffer;
	char* p = buffer;
	size_t len{};
	while (*p != '\0')
	{
		++p;
		++len;
	}
	std::cout << std::endl;
	std::cout << "The string contains " << len << " number of characters." << std::endl;
	std::cout << "So, the length of the string  [" << buffer << "] is " << len << std::endl;
}

/*
35. Write a program in C++ to display the pattern like right angle triangle using an asterisk.
Sample Output:
Input number of rows: 5
*
**
***
****
*****

*/

void PrintTriangle()
{
	int rows;
	InputNumber(rows, "Input number of rows: ");

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}
/*
36. Write a program in C++ to display the pattern like right angle triangle with number. Go to the editor
Sample Output:
Input number of rows: 5
1
12
123
1234
12345
*/

void PrintTriangleTwo()
{
	int rows;
	InputNumber(rows, "Input number of rows: ");

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			std::cout << j + 1;
		}
		std::cout << std::endl;
	}
}
/*
37. Write a program in C++ to make such a pattern like right angle triangle
using number which will repeat the number for that row.
Sample Output:
  Input number of rows: 5
1
22
333
4444
55555

*/
void PrintTriangleThree()
{
	int rows;
	InputNumber(rows, "Input number of rows: ");

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			std::cout << i + 1;
		}
		std::cout << std::endl;
	}
}

/*
38. Write a program in C++ to make such a pattern like right angle triangle with number increased by 1.
Sample Output:
 Input number of rows: 4
1
2 3
4 5 6
7 8 9 10

*/

void PrintTriangleFour()
{
	int rows;
	InputNumber(rows, "Input number of rows: ");
	int count{};
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			std::cout << ++count;
		}
		std::cout << std::endl;
	}
}

/*
39. Write a program in C++ to make such a pattern like a pyramid with numbers increased by 1.
Sample Output:
 Input number of rows: 4
	   1
	  2 3
	 4 5 6
	7 8 9 10
*/

void Print39()
{

	int rows;

	InputNumber(rows, "Input Rows To Draw : ");

	int drawNum = 0;

	for (int i = 1; i <= rows; ++i)

	{

		int spaceCol = rows - i;

		int numCol = i;

		for (int j = 1; j <= spaceCol; ++j)

		{

			std::cout << " ";

		}

		for (int z = 1; z <= numCol; ++z)

		{

			std::cout << ++drawNum << " ";

		}

		std::cout << std::endl;

	}

}

void Print40()
{

	int rows;

	InputNumber(rows, "Input Number To Draw :");

	for (int i = 1; i <= rows; ++i)

	{

		int spaceCol = rows - i;

		int asterikeCol = i;

		for (int j = 0; j < spaceCol; ++j)

		{

			std::cout << " ";

		}

		for (int z = 0; z < asterikeCol; ++z)

		{

			std::cout << "*" << " ";

		}

		std::cout << std::endl;

	}

}

void Print41()
{

	int rows;

	InputNumber(rows, "Input Number To Draw :");

	int outNum{ 1 };

	for (int i = 1; i <= rows; ++i)

	{

		int spaceCol = rows - i;

		int numCol = i;

		for (int j = 0; j < spaceCol; ++j)

		{

			std::cout << " ";

		}

		for (int z = 0; z < numCol; ++z)

		{

			std::cout << outNum << " ";

		}

		std::cout << std::endl;

		++outNum;

	}

}

void Print42()
{

	int rows;

	InputNumber(rows, "Input Number To Draw :");

	for (int i = 1; i <= rows; ++i)

	{

		int spaceCol = rows - i;

		int numCol = (2 * i) - 1;

		for (int j = 0; j < spaceCol; ++j)

		{

			std::cout << " ";

		}

		for (int z = 0; z < numCol; ++z)

		{

			std::cout << "*";

		}

		std::cout << std::endl;

	}
}

/*
43. Write a program in C++ to print the Floyd's Triangle. Go to the editor
Sample Output:
 Input number of rows: 5
1
01
101
0101
10101

*/
void Print43()
{
	int rows;
	InputNumber(rows, "Input number of rows: ");
	int nums[2]{ 0, 1 };
	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if ((i & 0x1) != 0)
			{
				std::cout << nums[(j + 1) % 2];
			}
			else
			{
				std::cout << nums[j % 2];
			}
		}
		std::cout << std::endl;
	}
	/* 정답코드
	   int i,j,n,p,q;
		cout << "\n\n Print the Floyd's Triangle:\n";
		cout << "--------------------------------\n";
		cout << " Input number of rows: ";
		cin >> n;
	   for(i=1;i<=n;i++)
	   {
		 if(i%2==0)
		 { 
		 p=1;q=0;
		 }
		 else
		 { 
		 p=0;q=1;
		 }
		  for(j=1;j<=i;j++)
		 if(j%2==0)
			cout<<p;
		 else
			cout<<q;
		 cout<<endl;
	   }
	*/
}

/*
44. Write a program in C++ to display the pattern like a diamond.
Sample Output:
 Input number of rows (half of the diamond): 5

	*
   ***
  *****
 *******
*********
 *******
  *****
   ***
	*
*/
void Print44()
{
	int rows;
	InputNumber(rows, "Input number of rows (half of the diamond): ");

	for (int i = 1; i <= rows; ++i)
	{
		int spaceCol = rows - i;
		int starCol = (2 * i) - 1;
		for (int j = 0; j < spaceCol; ++j)
		{
			std::cout << " ";
		}
		for (int z = 0; z < starCol; ++z)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}
	int reverseRows = rows - 1;
	int spaceCol = 0;
	for (int i = reverseRows; i >= 1; --i)
	{
		++spaceCol;
		int starCol = (2 * i) - 1;
		for (int j = 0; j < spaceCol; ++j)
		{
			std::cout << " ";
		}
		for (int z = 0; z < starCol; ++z)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}
	/* 정답코드
		int i,j,r;
		cout << "\n\n Display the pattern like a diamond:\n";
		cout << "----------------------------------------\n";
		cout << " Input number of rows (half of the diamond): ";
		cin >> r;
		for(i=0;i<=r;i++)
		{
			for(j=1;j<=r-i;j++)
			cout<<" ";
			for(j=1;j<=2*i-1;j++)
			cout<<"*";
			cout<<endl;
	   }
	   for(i=r-1;i>=1;i--)
	   {
		 for(j=1;j<=r-i;j++)
			cout<<" ";
			for(j=1;j<=2*i-1;j++)
		   cout<<"*";
		 cout<<endl;;
	   }


	*/
}
/*
45. Write a program in C++ to display Pascal's triangle like pyramid. Go to the editor
Sample Output:
 Input number of rows: 5
		  1
		1   1
	  1   2   1
	1   3   3   1
  1   4   6   4   1



	1	5	10	10	 5	 1
  1   6	 15	  20  15  6    1
*/

void PrintPascalTriangle45()
{
	int rows;
	InputNumber(rows, "Input number of rows: ");
	int** tdArray = new int*[rows];

	for (int i = 0; i < rows; ++i)
	{
		tdArray[i] = new int[rows];
	}
	const int ONE = 1;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j > 0 && j != i)
			{
				tdArray[i][j] = tdArray[i - 1][j - 1] + tdArray[i - 1][j];
				
			}
			else
			{
				tdArray[i][j] = ONE;
			}
		}
	}
	for (int i = 0; i < rows; ++i)
	{
		int spaceCol = (rows - i) + 1;
		int outCol = i + 1;

		for (int j = 0; j < spaceCol; ++j)
		{
			std::cout << " ";
		}

		for (int z = 0; z < outCol; ++z)
		{
			std::cout << tdArray[i][z] << " ";
		}

		std::cout << std::endl;
	}

}

void PrintPascalAnswer45()
{
	int row, c = 1, blk, i, j;
	cout << "\n\n Display the Pascal's triangle:\n";
	cout << "-----------------------------------\n";
	cout << " Input number of rows: ";
	cin >> row;
	for (i = 0; i < row; i++)
	{
		for (blk = 1; blk <= row - i; blk++)
			cout << "  ";
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || i == 0)
				c = 1;
			else
				c = c * (i - j + 1) / j;
			cout << c << "   ";
		}
		cout << endl;
	}
}


/*
46. Write a program in C++ to display Pascal's triangle like right angle traingle.
Sample Output:
 Input number of rows: 7
1
1   1
1   2   1
1   3   3   1
1   4   6   4   1
1   5   10   10   5   1
1   6   15   20   15   6   1
Click me to see the sample solution
*/
void PrintPascalTriangle46()
{
	int rows;
	InputNumber(rows, "Input number of rows: ");
	int** tdArray = new int* [rows];

	for (int i = 0; i < rows; ++i)
	{
		tdArray[i] = new int[rows];
	}
	const int ONE = 1;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j > 0 && j != i)
			{
				tdArray[i][j] = tdArray[i - 1][j - 1] + tdArray[i - 1][j];

			}
			else
			{
				tdArray[i][j] = ONE;
			}
		}
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			std::cout << tdArray[i][j] << " ";
		}
		std::cout << std::endl;
	}

}

/*
47. Write a program in C++ to display such a pattern for n number of rows using number. 
Each row will contain odd numbers of number. 
The first and last number of each row will be 1 and middle column will be the row number. 
Sample Output:

 Input number of rows: 5

	1
   121
  12321
 1234321
123454321

*/

void Print47()
{
	int rows;
	InputNumber(rows, "Input number of rows: ");

	for (int i = 0; i < rows; ++i)
	{
		int spaceCol = rows - i - 1;
		int outCol = (i + 1) * 2 - 1;

		for (int j = 0; j < spaceCol; ++j)
		{
			std::cout << " ";
		}
		int midNum = (outCol / 2) + 1;
		int outNum = midNum;
		for (int z = 0; z < outCol; ++z)
		{
			if (z >= midNum)
			{
				outNum -= 1;
				std::cout << outNum;
			}
			else
			{
				std::cout << z + 1;
			}
		}

		std::cout << std::endl;
	}
}

/*
48. Write a program in C++ to display the pattern like pyramid using the alphabet.
Sample Output:
 Input the number of Letters (less than 26) in the Pyramid: 5
		A
	  A B A
	A B C B A
  A B C D C B A
A B C D E D C B A

*/

void Print48()
{
	int rows;
	InputNumber(rows, "Input the number of Letters (less than 26) in the Pyramid: ");
	assert(rows <= 26);

	for (int i = 0; i < rows; ++i)
	{
		int spaceCol = 2 * (rows - i - 1);
		for (int j = 0; j < spaceCol; ++j)
		{
			std::cout << " ";
		}

		int outCol = (2 * i) + 1;
		int half = outCol / 2;
		char outChar = 'A';
		for (int z = 0; z < outCol; ++z)
		{
			if (z >= half)
			{
				std::cout << outChar-- << " ";
			}
			else
			{
				std::cout << outChar++ << " ";
			}
		}
		std::cout << std::endl;
	}
}

/*
49. Write a program in C++ to print a pyramid of digits as shown below for n number of lines.
	1
   232
  34543
 4567654
567898765
Sample Output:
 Input the number of rows: 5
	1
   232
  34543
 4567654
567898765

*/

void Print49()
{
	int rows;
	InputNumber(rows, "Input the number of rows: ");

	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 0; j < rows - i; ++j)
		{
			std::cout << " ";
		}
		int out = i;
		int outCol = (2 * i) - 1;
		int half = outCol / 2;
		for (int z = 0; z <= half; ++z)
		{
			std::cout << out++;
		}
		if (outCol != 1)
		{
			--out;
			for (int z = half + 1; z < outCol; ++z)
			{
				std::cout << --out;
			}
		}


		std::cout << std::endl;
	}
}

/*
50. Write a program in C++ to print a pattern like highest numbers of columns appear in first row.
Sample Output:
 Input the number of rows: 5
12345
2345
345
45
5
*/

void Print50() 
{
	int rows;
	InputNumber(rows, "Input the number of rows: ");

	for (int i = 1; i <= rows; ++i)
	{
		for (int j = i; j <= rows; ++j)
		{
			std::cout << j;
		}

		std::cout << std::endl;
	}

}

/*

51. Write a program in C++ to display the pattern 
using digits with right justified and the highest columns appears in first row.
Sample Output:
 Input number of rows: 5
12345
 1234
  123
   12
	1
*/
void Print51()
{
	int rows;
	InputNumber(rows, "Input number of rows: ");

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			std::cout << " ";
		}

		for (int j = 1; j <= rows - i; ++j)
		{
			std::cout << j;
		}

		std::cout << std::endl;
	}
}


/*
52. Write a program in C++ to display the pattern
using digits with left justified and the highest columns appears in first row in descending order. 
Sample Output:
 Input number of rows: 5
5 4 3 2 1
4 3 2 1
3 2 1
2 1
1
*/
void Print52()
{
	int rows;
	InputNumber(rows, "Input number of rows: ");

	for (int i = 0; i < rows; ++i)
	{
		for (int j = rows - i; j > 0; --j)
		{
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
}


/*
53. Write a program in C++ to display the pattern 
like right angle triangle with right justified using digits.
Sample Output:
 Input number of rows: 5
	1
   21
  321
 4321
54321
*/

void Print53()
{
	int rows;
	InputNumber(rows, "Input number of rows: ");

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < rows - i - 1; ++j)
		{
			std::cout << " ";
		}
		for (int j = i + 1; j > 0; --j)
		{
			std::cout << j; 
		}
		std::cout << std::endl;

	}
}
/*
54. Write a program in C++ to display the pattern power of 2, triangle.
Sample Output:

Display the pattern like pyramid with power of 2:
------------------------------------------------------
 Input the number of rows:
				 1
			  1  2  1
		   1  2  4  2  1
        1  2  4  8  4  2  1
	 1  2  4  8  16  8  4  2  1

*/
void Print54()
{
	int rows;
	InputNumber(rows, "Input the number of rows: ");

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < 2 * (rows - i); ++j)
		{
			std::cout << " ";
		}
		int out = 1;
		int repeatCount = 2 * i + 1;
		int middleCount = repeatCount / 2;
		for (int j = 0; j < repeatCount; ++j)
		{
			if (middleCount == 0)
			{
				std::cout << out << " ";
				break;
			}
			if (j < middleCount)
			{
				std::cout << out << " ";
				out <<= 1;
			}
			else
			{
				std::cout << out << " ";
				out >>= 1;
			}
		}
		std::cout << std::endl;
	}
}
