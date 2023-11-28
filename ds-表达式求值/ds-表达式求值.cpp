//题目描述
//设计一个表达式求值的程序。该程序必须可以接受包含（，）， + ， - ， * ， / ， % 和 ^ (求幂)的中缀表达式，并求出结果。如果表达式正确，则输出表达式的值，如果表达式非法，则输出错误信息。
//注意2 ^ 2 ^ 3转为后缀应为223 ^ ^
//
//操作数均转为double运算。
//
//幂运算可以直接使用pow(a, b)
//
//%, 操作数转为Int再进行计算。
//
//
//
//输入要求：
//多个表达式，每个表达式占一行。
//
//输出要求：
//对每个表达式，如果为正确表达式则输出结果（精确到小数点后两位），如果为错误表达式则输出“ERROR IN INFIX NOTATION”.
//
//
//
//样例输入输出
//样例1
//输入 :
//(2 - 4) ^ 3
//输出 :
//	-8.00
//	样例2
//	输入 :
//(3 * 5 * (4 + 8) % 2)
//输出:
//0.00
//样例3
//输入 :
//1 + 2(
//	输出 :
//	ERROR IN INFIX NOTATION

#include<iostream>
#include<stack>
#include<map>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

map<char, int> operatorPrecedence = {
	{'+', 1},
	{'-', 1},
	{'*', 2},
	{'/', 2},
	{'%', 2},
	{'^', 3}
};

// 比较两个运算符的优先级
bool hasHigherPrecedence(char op1, char op2) {
	return operatorPrecedence[op1] >= operatorPrecedence[op2];
}

//判断括号是否合法
int check_Bracket(const string& expression) {
	stack<double> myStack;

	//判断括号位置是否合法
	char prevChar = '\0';
	string Operator = "+-*/%^.";
	for (char c : expression) {

		if (Operator.find(prevChar) != string::npos)
		{
			if (c == ')')
			{
				/*cout << 1;*/
				return 1;
			}
		}

		if (prevChar == '(')
		{
			if (Operator.find(c) != string::npos)
			{
				/*cout << 2;*/
				return 1;
			}
		}

		prevChar = c;
	}
	//括号数量是否合法
	for (char c : expression) {
		if (myStack.empty()) {
			if (c == ')') {
				/*cout << 3;*/
				return 1;
			}

			if (c == '(') {
				myStack.push(c);
			}
		}
		else if (!myStack.empty()) {
			if (c == '(') {
				myStack.push(c);
			}

			if (c == ')') {
				myStack.pop();
			}
		}
	}

	if (myStack.empty()) {
		return 0;
	}
	else {
		/*cout << 4;*/
		return 1;
	}
}

//判断运算符是否合法
int check_Operator(const string& expression) {
	//是否含有非法字符
	string validCharacters = "0123456789+-*/%^().";
	string mayLeft = "0123456789)";
	string mayRight = "0123456789(";
	string Operator = "+-*/%^";

	for (char c : expression){

		if (validCharacters.find(c) == string::npos)
		{
			/*cout << 5;*/
			return 1;
		}

	}
	//判断是否有重复运算符
	char prevChar = '\0'; // 初始化为非运算符字符

	for (char c : expression) {
		// 检查当前字符是否是运算符
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '.') {
			// 如果前一个字符也是运算符，则有连续的运算符
			if (prevChar == '+' || prevChar == '-' || prevChar == '*' || prevChar == '/' || prevChar == '%' || prevChar == '^' || prevChar == '.') {
				/*cout << 6;*/
				return 1;
			}
		}

		if (Operator.find(prevChar) != string::npos)
		{
			if (mayRight.find(c) == string::npos)
			{
				/*cout << 7;*/
				return 1;
			}
		}

		if (Operator.find(c) != string::npos)
		{
			if (mayLeft.find(prevChar) == string::npos)
			{
				/*cout << 8;*/
				return 1;
			}
		}

		if (prevChar == '/')
		{
			if (c == '0')
			{
				/*cout << 9;*/
				return 1;
			}
		}

		if (c == '^')
		{
			if (prevChar == '0')
			{
				/*cout << 10;*/
				return 1;
			}
		}

		prevChar = c; // 更新前一个字符
	}

	return 0;
}

int Check(const string& expression) {

	if (check_Bracket(expression) != 0)
	{
		cout << "ERROR IN INFIX NOTATION" << endl;
		/*cout << 11;*/
		return 1;
	}

	if (check_Operator(expression) != 0)
	{
		cout << "ERROR IN INFIX NOTATION" << endl;
		/*cout << 12;*/
		return 1;
	}

	return 0;
}

//中缀改为后缀
string convert_Stack(const string& expression) {
	stack<char> operatorStack;
	string postfixExpression = "";
	string multiDigitNumber = "";  // 用于累积多位数字符
	bool isAccumulating = false;  // 表示是否正在累积多位数

	for (char c : expression) {
		if (isdigit(c) || c == '.') {
			multiDigitNumber += c;
			isAccumulating = true;
		}
		else if (isAccumulating) {
			postfixExpression += multiDigitNumber + ' ';  // 将多位数添加到后缀表达式
			multiDigitNumber = "";  // 重置多位数累积
			isAccumulating = false;
		}
		
		if (c == '(') {
			operatorStack.push(c);
		}
		else if (c == ')') {
			while (!operatorStack.empty() && operatorStack.top() != '(') {
				postfixExpression += operatorStack.top();
				postfixExpression += ' ';
				operatorStack.pop();
			}
			if (!operatorStack.empty() && operatorStack.top() == '(') {
				operatorStack.pop();
			}
		}
		else if (operatorPrecedence.find(c) != operatorPrecedence.end()) {
			if (!operatorStack.empty() && c == '^' && operatorStack.top() == '^')
			{
				operatorStack.push(c);
			}
			else
			{
				while (!operatorStack.empty() && operatorStack.top() != '(' && hasHigherPrecedence(operatorStack.top(), c)) {
					postfixExpression += operatorStack.top();
					postfixExpression += ' ';
					operatorStack.pop();
				}
				operatorStack.push(c);
			}
		}

	}

	if (isAccumulating) {
		postfixExpression += multiDigitNumber + ' ';  // 处理最后的多位数
	}

	while (!operatorStack.empty()) {
		postfixExpression += operatorStack.top();
		postfixExpression += ' ';
		operatorStack.pop();
	}

	return postfixExpression;
}

double evaluatePostfix(const string& postfixExpression) {
	stack<double> operandStack;

	istringstream iss(postfixExpression);
	string token;

	while (iss >> token) {
		if (isdigit(token[0])) {
			// 如果是数字，将其转换为 double 并推入操作数栈
			double operand = stod(token);
			operandStack.push(operand);
		}
		else {
			// 处理运算符
			double operand2 = operandStack.top();
			operandStack.pop();
			double operand1 = operandStack.top();
			operandStack.pop();

			if (token == "+") {
				operandStack.push(operand1 + operand2);
			}
			else if (token == "-") {
				operandStack.push(operand1 - operand2);
			}
			else if (token == "*") {
				operandStack.push(operand1 * operand2);
			}
			else if (token == "/") {
				operandStack.push(operand1 / operand2);
			}
			else if (token == "^") {
				operandStack.push(pow(operand1, operand2));
			}
			else if (token == "%") {
				operandStack.push(fmod(operand1, operand2)); // 使用 fmod 函数进行求模运算
			}
		}
	}

	// 最终栈中的元素就是计算结果
	if (!operandStack.empty()) {
		return operandStack.top();
	}
	else {
		// 如果栈为空，表示表达式无效
		throw runtime_error("ERROR IN INFIX NOTATION");
	}
}

int main() {

	string arr;
	cin >> arr;
	
	if (Check(arr) == 0)
	{
		cout << fixed << setprecision(2) << evaluatePostfix(convert_Stack(arr)) << endl;
	}

	return 0;
}