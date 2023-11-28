//��Ŀ����
//���һ�����ʽ��ֵ�ĳ��򡣸ó��������Խ��ܰ����������� + �� - �� * �� / �� % �� ^ (����)����׺���ʽ������������������ʽ��ȷ����������ʽ��ֵ��������ʽ�Ƿ��������������Ϣ��
//ע��2 ^ 2 ^ 3תΪ��׺ӦΪ223 ^ ^
//
//��������תΪdouble���㡣
//
//���������ֱ��ʹ��pow(a, b)
//
//%, ������תΪInt�ٽ��м��㡣
//
//
//
//����Ҫ��
//������ʽ��ÿ�����ʽռһ�С�
//
//���Ҫ��
//��ÿ�����ʽ�����Ϊ��ȷ���ʽ������������ȷ��С�������λ�������Ϊ������ʽ�������ERROR IN INFIX NOTATION��.
//
//
//
//�����������
//����1
//���� :
//(2 - 4) ^ 3
//��� :
//	-8.00
//	����2
//	���� :
//(3 * 5 * (4 + 8) % 2)
//���:
//0.00
//����3
//���� :
//1 + 2(
//	��� :
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

// �Ƚ���������������ȼ�
bool hasHigherPrecedence(char op1, char op2) {
	return operatorPrecedence[op1] >= operatorPrecedence[op2];
}

//�ж������Ƿ�Ϸ�
int check_Bracket(const string& expression) {
	stack<double> myStack;

	//�ж�����λ���Ƿ�Ϸ�
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
	//���������Ƿ�Ϸ�
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

//�ж�������Ƿ�Ϸ�
int check_Operator(const string& expression) {
	//�Ƿ��зǷ��ַ�
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
	//�ж��Ƿ����ظ������
	char prevChar = '\0'; // ��ʼ��Ϊ��������ַ�

	for (char c : expression) {
		// ��鵱ǰ�ַ��Ƿ��������
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '.') {
			// ���ǰһ���ַ�Ҳ������������������������
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

		prevChar = c; // ����ǰһ���ַ�
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

//��׺��Ϊ��׺
string convert_Stack(const string& expression) {
	stack<char> operatorStack;
	string postfixExpression = "";
	string multiDigitNumber = "";  // �����ۻ���λ���ַ�
	bool isAccumulating = false;  // ��ʾ�Ƿ������ۻ���λ��

	for (char c : expression) {
		if (isdigit(c) || c == '.') {
			multiDigitNumber += c;
			isAccumulating = true;
		}
		else if (isAccumulating) {
			postfixExpression += multiDigitNumber + ' ';  // ����λ����ӵ���׺���ʽ
			multiDigitNumber = "";  // ���ö�λ���ۻ�
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
		postfixExpression += multiDigitNumber + ' ';  // �������Ķ�λ��
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
			// ��������֣�����ת��Ϊ double �����������ջ
			double operand = stod(token);
			operandStack.push(operand);
		}
		else {
			// ���������
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
				operandStack.push(fmod(operand1, operand2)); // ʹ�� fmod ����������ģ����
			}
		}
	}

	// ����ջ�е�Ԫ�ؾ��Ǽ�����
	if (!operandStack.empty()) {
		return operandStack.top();
	}
	else {
		// ���ջΪ�գ���ʾ���ʽ��Ч
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