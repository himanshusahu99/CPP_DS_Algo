#include<iostream>
using namespace std;

int main()
{

	int a, n;

	cin >> a >> n;

	int ans =1 ; 
	while(n > 0 )
	{
		int last_digit = n & 1;
		if(last_digit)
		{
			ans = ans * a; // multiply with current value of a 
			
		}

	
	a =  a *a; // need to multiply with a 

	
	n = n >> 1;  // remove tha last bit so that evaluate last bit	
	}

	cout << ans ; 

}