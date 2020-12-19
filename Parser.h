#pragma once
#include "Expression.h"
#include <string>

using namespace std;

class Parser
{
public:

	int counter;
	string str;

	Parser(string str);

	string parse_token();
	Expression* parse();
	Expression* parse_expression();

	~Parser();
};
