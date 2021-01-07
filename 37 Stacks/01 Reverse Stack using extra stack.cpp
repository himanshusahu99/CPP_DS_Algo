#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int>&s1, stack<int>&s2, int n )
{
	for(int i =0; i<n; i++)
	{
		s2.push(s1.top());
		s1.pop(); 
	}
}

void reverseStack(stack<int> &s )
{
	//creating another stack 
	stack<int> s2; 

	int n = s.size(); 

	for(int i = 0; i<n; i++)
	{
		//pick the element ot another var; 
		int x = s.top(); 
		s.pop(); 

		// transfer all n-i-1 element in another array; 
		transfer(s, s2, n-i-1);

		// copy x to the original stack
		s.push(x); 

		//  transffer all elements from s2 to s; 
		transfer(s2, s, n-i-1);   
	}



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