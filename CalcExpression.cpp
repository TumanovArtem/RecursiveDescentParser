#include <iostream>
#include <string>
#include "Parser.h"
#include "Expression.h"

using namespace std;

string str = "";
Parser* parser;
Expression* expr;
int main()
{
	for (;;) {

		cin >> str;
		parser = new Parser(str);
		expr = parser->parse();
		cout << expr->eval();
	}
	return 0;
}