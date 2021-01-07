#include<iostream>
using namespace std;

   
// Returns factorial of n 
int fact(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 
  
int nCr(int n, int r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
 

int fun(int n)
{
	//base cases 
	if(n == 0 or n==1)
		return 1; 
	if(n  == 2 ) 
		return 2 ;
 	
 	return 1*fun(n-1) +nCr(n-1, 1)*fun(n-2); 

}


int main()
{
	//enter number of people
	int n;

	cin >> n;

	cout << fun(n); 

	return 0; 

}