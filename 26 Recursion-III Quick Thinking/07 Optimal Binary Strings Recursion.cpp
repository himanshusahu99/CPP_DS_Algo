#include<iostream>
using namespace std;

int fun(int n )
{
	// base case i.e 00 01 10 (11 can not possible bcs no concecutinve ones )
	if(n == 0)
		return 0; 
	if(n == 1)
		return 2;
	if(n == 2)
		return 3; 


	return fun(n-1) + fun(n-2);
}


int main()
{
	// enter length of string 
	int n; 
	cin >> n; 

	cout << fun(n);

	return 0; 



}