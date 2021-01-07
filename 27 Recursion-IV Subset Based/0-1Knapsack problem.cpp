#include<iostream>
using namespace std;

int profit(int n , int c, int *wts, int *prices)
{
	//base case 
	if(n == 0 or c == 0)
	{
		return 0; 
	}

	//rec case 
	int ans = 0 ; 
	int include = 0 ;
	int exclude = 0 ; 

	//include
	if(wts[n-1] <= c )
	{
		include = prices[n-1] + profit(n-1, c-wts[n-1], wts, prices);
	}

	//exclude
	exclude = profit(n-1 , c, wts, prices );

	// ans 
	ans = max(include, exclude);

	return ans; 



}

int main()
{
	int weights[] = {1,2,3,5};
	int prices[] = {40, 20, 30 , 100}; 
	int n = 4 ; 
	int c = 7; // max. weight of bag 

	cout << profit(n ,c , weights, prices); 

	return 0 ;

}