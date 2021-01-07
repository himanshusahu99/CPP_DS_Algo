	#include<iostream>
	#include<stack>
	using namespace std;

	void insertatbottom(stack<int> &s , int x ) 
	{
		//base case 
		if(s.empty())
		{
			s.push(x); 
			return; 
		}

		//rec case; 
		int d = s.top(); 
		s.pop(); 
		insertatbottom(s, x); 
		s.push(d); 

	}
	void reverseStack(stack<int> &s )
	{
		//base case 

		if(s.empty())
		{
			return; 
		}

		//rec case 

		// pop out top and insert it to the bottom

		int x = s.top(); 
		s.pop(); 

		reverseStack(s);

		insertatbottom(s, x); 

	}

	void printStack(stack<int> s)
	{
		while(!s.empty())
		{
			cout << s.top() << " " ; 
			s.pop(); 
		}
	}

	int main()
	{
		stack<int> s; 
		s.push(1); 
		s.push(2); 
		s.push(3); 
		s.push(4); 

		cout << "before " ; 
		printStack(s);

		reverseStack(s);

		cout << "after "; 
		printStack(s); 
		


	} 