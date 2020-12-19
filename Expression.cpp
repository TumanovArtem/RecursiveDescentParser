#include "Expression.h"
#include <stdlib.h>

Expression::Expression(string t)
{
	type = 1;
	token = t;
	error = "";
}

Expression::Expression(string t, Expression* l)
{
	type = 2;
	token = t;
	left_exp = l;
	error = "";
}

Expression::Expression(string t, Expression* l, Expression* r)
{
	type = 3;
	token = t;
	left_exp = l;
	right_exp = r;
	error = "";
}

double Expression::eval()
{
	double result, left_operand, right_operand;
	result = 0;
	if (this->type == 3)
	{
		left_operand = left_exp->eval();
		right_operand = right_exp->eval();
		if (this->token == "+")
			result = left_operand + right_operand;
		if (this->token == "-")
			result = left_operand - right_operand;
	}

	if (this->type == 2)
	{
		if (this->token == "-")
			result = stod(this->left_exp->token); //Число содержится в токене left_exp, т.к. expression.type == 1

		if (this->token == "+")
			result = stod(this->left_exp->token); //Число содержится в токене left_exp, т.к. expression.type == 1
	}

	if (this->type == 1)
		result = stod(this->token);

	return result;
}

