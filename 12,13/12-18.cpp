#include <iostream>
#include <string>
#include <vector>
#include "ImprovedStack.h"
using namespace std;

string infixToPostfix(const string& expression);
vector<string> split(const string& expression);
string makeResult(Stack<string>& numbers, Stack<string>& operators);

int main() {
	string enterString;
	cout << "Enter infix expression: ";
	getline(cin, enterString);

	cout << "Postfix expression is : " << infixToPostfix(enterString) << endl;
	return 0;
}

string infixToPostfix(const string& expression) {
	string result = "";
	Stack<string> numbers, operators;

	vector<string> tokens(split(expression));

	for (int i = 0;i < tokens.size();i++) {
		if ((tokens[i][0] == '+') || (tokens[i][0] == '-')) {
			if(!numbers.empty())
				result += numbers.pop() + " ";
			while (!operators.empty() && (operators.peek()[0] == '+' || operators.peek()[0] == '-' || operators.peek()[0] == '*' || operators.peek()[0] == '/' || operators.peek()[0] == '%' )) {
				result += makeResult(numbers, operators) + " ";
			}
			operators.push(tokens[i]);
		}
		else if ((tokens[i][0] == '*') || (tokens[i][0] == '/') || (tokens[i][0] == '%')) {
			if (!numbers.empty())
				result += numbers.pop() + " ";
			while (!operators.empty() && (operators.peek()[0] == '*' || operators.peek()[0] == '/' || operators.peek()[0] == '%')) {
				result += makeResult(numbers, operators) + " ";
			}
			operators.push(tokens[i]);
		}
		else if (tokens[i][0] == '(')
			operators.push(tokens[i]);
		else if (tokens[i][0] == ')') {
			while (operators.peek()[0] != '(') {
				result += makeResult(numbers, operators) + " ";
			}
			operators.pop();
		}
		else
			numbers.push(tokens[i]);
	}

	while (!operators.empty())
		result += makeResult(numbers, operators) + " ";

	return result;
}

vector<string> split(const string& expression) {
	vector<string> v;
	string numberString;

	for (unsigned i = 0; i < expression.length();i++) {
		if (isdigit(expression[i]))
			numberString.append(1, expression[i]);
		else {
			if (numberString.size() > 0) {
				v.push_back(numberString);
				numberString.erase();
			}

			if (!isspace(expression[i])) {
				string s;
				s.append(1, expression[i]);
				v.push_back(s);
			}
		}
	}

	if (numberString.size() > 0)
		v.push_back(numberString);

	return v;
}

string makeResult(Stack<string>& numbers, Stack<string>& operators) {
	string oper = operators.pop();
	if (!numbers.empty()) {
		string num2 = numbers.pop();
		if (!numbers.empty()) {
			string num1 = numbers.pop();
			return num1 + " " + num2 + " " + oper;
		}
		else
			return num2 + " " + oper;
	}
	return oper;
}