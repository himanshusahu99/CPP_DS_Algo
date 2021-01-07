#include<iostream>
#include<stack>
using namespace std;

bool isValidExpression(char* stk)
{
	stack<int> s; 
	for(int i =0; stk[i] != '\0'; i++)
	{
		if(stk[i] == '(')
			s.push(stk[i]);

		else if(stk[i] == ')')
		{
			if(s.empty() or  s.top() != '(')
				return  false;

			s.pop();
		} 
	}

	return s.empty();// return true if s is empty 



}



int main()
{
	char s[100] = "((a+b)+(c-d))"; 
	if(isValidExpression(s))
	{
		cout << "YES" << endl; 
	}

	else
		cout << "No "; 



}