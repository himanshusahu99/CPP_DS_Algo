#include<iostream>
using namespace std;

int fastRecursion(int a, int n )
{
	if(n==0)
		return 1; 

	int smaller_problem =  fastRecursion(a , n/2);
	smaller_problem *= smaller_problem; 

	if(n & 1)
		smaller_problem *= a; 

	return smaller_problem; 



}


int main()
{
	int a, n; 
	cin >> a >> n; 

	cout << fastRecursion(a, n); 
}