#include <iostream>
#include <algorithm>
#include <malloc>

using namespace std;

class bigNum{
	public:
		char num[50][50]; //Max Size of integer is 10^(50*50) - 1
		bigNum add(bigNum, bigNum);
		bigNum subtract(bigNum, bigNum);
		bigNum multiply(bigNum, bigNum);
		bigNum divide(bigNum, bigNum);
		bigNum operator+(bigNum, bigNum);
		bigNum operator-(bigNum, bigNum);
		bigNum operator*(bigNum, bigNum);
		bigNum operator/(bigNum, bigNum);
		bigNum operator+=(bigNum);
		bigNum operator-=(bigNum);
		bigNum operator*=(bigNum);
		bigNum operator/=(bigNum);
}
