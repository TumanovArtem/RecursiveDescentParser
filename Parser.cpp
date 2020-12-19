#include "Parser.h"
#include <iostream>

using namespace std;

Parser::Parser(string s)
{
	str = s;
	counter = 0;
}

Parser::~Parser()
{

}

string Parser::parse_token()
{
	int code = int(this->str[this->counter]);
	++this->counter;
	string digit = "";

	//Digit
	if ((code > 47) && (code < 58))
	{
		digit = this->str[this->counter-1];
		while ((code > 47) && (code < 58))
		{
			code = int(this->str[this->counter]);
			if ((code > 47) && (code < 58))
			{
				digit += this->str[this->counter];
				++this->counter;
			}
		}
		return digit;
	}

	//Open bracket
	if (code == 40)
	{
		return "(";
	}

	//Close bracket
	if (code == 41)
	{
		return ")";
	}

	//Plus
	if (code == 43)
	{
		return "+";
	}

	//Minus
	if (code == 45)
	{
		return "-";
	}

	return "";

}

Expression* Parser::parse()
{
	string operation;
	Expression* left_exp;
	Expression* right_exp;

	left_exp = this->parse_expression();

	for (;;)
	{
		operation = this->parse_token();
		if (operation == "(")
			throw runtime_error("Unexpected " + operation);
		//Случай, когда выражение состоит только из левого операнда
		if ((operation == ")") || (operation == ""))
		{
			--this->counter;
			return left_exp;
		}

		right_exp = this->parse_expression();
		left_exp = new Expression(operation, left_exp, right_exp);
	}
}

Expression* Parser::parse_expression()
{
	Expression* exp;

	string token = this->parse_token();
	if (token == "")
		throw runtime_error("Unexpected token");
	//Ищем число
	if ((token[0] > 47) && (token[0] < 58))
	{
		exp = new Expression(token);
		return exp;
	}

	//Унарная функция
	if ((token == "+") || (token == "-"))
	{
		exp = new Expression(token, this->parse_expression());
		return exp;
	}

	//Бинарная функция
	if (token == "(")
	{
		exp = this->parse();
		if (parse_token() != ")")
			throw runtime_error("Expected )");
		return exp;
	}
	
	throw runtime_error("Unexpected symbol");
}