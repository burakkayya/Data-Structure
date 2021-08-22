#include <string> 
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

///----------------------------------------------------------------------------------
/// Given an expression in infix-notation, converts it to a string in post-fix notation 
/// 
string Infix2Postfix(string &s) {
	string result="";
	string temp;
	temp = s;
	string new_s = "";
	int i = 0;
	while (temp[i] != '\0') {

		if (temp[i] == ' ') {
			i++;
			continue;
		}
		new_s += temp[i];
		i++;
	}
	
	i = 0;
	int flag = 0;
	stack<char> str;
	while (i<new_s.length()) {
		flag = 0;
		while (new_s[i] != '+' && new_s[i] != '-' && new_s[i] != '*' && new_s[i] != '/' && new_s[i] != ' ' && new_s[i] != '(' && new_s[i] != ')' &&new_s[i] != '\0') {
			
			result += new_s[i];
			i++;
			flag++;
		}
		if (flag != 0) {
			
			result += " ";
		}
		if (str.empty()) {
			str.push(new_s[i]);
		}
		else {
			if (new_s[i] == '+') {
				while (!str.empty()) {
					if (str.top() != '(') {
					
						result += str.top();
						result += " ";
						str.pop();
					}
					else
						break;
				}
				str.push(new_s[i]);
			}
			else if (new_s[i] == '-') {
				while (!str.empty()) {
					if (str.top() != '(' && str.top() != '+') {
					
						result += str.top();
						result += " ";
						str.pop();
					}
					else
						break;
				}
				str.push(new_s[i]);
			}

			else if (new_s[i] == '/') {
				while (!str.empty()) {
					if (str.top() != '(' && str.top() != '+' && str.top() != '-') {
					
						result += str.top();
						result += " ";
						str.pop();
					}
					else
						break;
				}
				str.push(new_s[i]);
			}

			else if (new_s[i] == '*') {
				while (!str.empty()) {
					if (str.top() != '(' && str.top() != '+' && str.top() != '-' && str.top() != '/') {
					
						result += str.top();
						result += " ";
						str.pop();
					}
					else
						break;
				}
				str.push(new_s[i]);
			}
			else if (new_s[i] == '(') {
				str.push(new_s[i]);
			}
			else if (new_s[i] == ')') {
				while (str.top() != '(') {
					
					result += str.top();
					result += " ";
					str.pop();
				}
				str.pop();
			}

		}

		i++;
	}
	while (!str.empty()) {

		
		result += str.top();
		result += " ";
		str.pop();

	}

	

	return result;
} // end-Infix2Postfix

///----------------------------------------------------------------------------------
/// Given a string in post-fix notation, evaluates it and returns the result
/// 
int EvaluatePostfixExpression(string& s) {
	stack<int> str;
	string t="";
	int number;
	int i = 0,j,flag,flag2;
	int temp1, temp2;
	while (s[i] != '\0') {
		flag = 0;
		flag2 = 0;
		while (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != ' ') {
			t += s[i];
			i++;
			flag2++;
		}
		if (flag2 != 0) {
			number=stoi(t);
			str.push(number);
			t = "";
		}
		
			if (s[i] == '*') {
				temp1 = str.top();
				str.pop();
				temp2 = str.top();
				str.pop();
				temp1 *= temp2;
				flag = 1;
			}
			else if (s[i] == '+') {
				temp1 = str.top();
				str.pop();
				temp2 = str.top();
				str.pop();
				temp1 += temp2;
				flag = 1;
			}
			else if (s[i] == '-') {
				temp1 = str.top();
				str.pop();
				temp2 = str.top();
				str.pop();
				temp1 = temp2-temp1;
				flag = 1;
			}
			else if (s[i] == '/') {
				temp1 = str.top();
				str.pop();
				temp2 = str.top();
				str.pop();
				temp1 = temp2/temp1;
				flag = 1;
			}
			if(flag==1)
			str.push(temp1);
		
		i++;
	}


	return str.top();
} // end-EvaluatePostfixExpression
