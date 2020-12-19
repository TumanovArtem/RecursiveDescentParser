#pragma once
#include<string>
using namespace std;

class Expression
{
public:
	Expression(string token);
	Expression(string token, Expression* left_exp);
	Expression(string token, Expression* left_exp, Expression* right_exp);

	int type; //1 - число, 2 - унарное выражение, 3 - бинарное выражение
	string token;
	Expression* left_exp;
	Expression* right_exp;
	string error;

	double eval();
};

