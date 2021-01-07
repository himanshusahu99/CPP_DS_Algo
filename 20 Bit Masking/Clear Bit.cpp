#include <iostream>
using namespace std;

int main()
{
	int n;

	cout << "Enter your number "; 
		cin >>n ;
	
	int i ;
	cout << "Enter position you want(start from zero) " ; 
	cin >> i ; 

	int mask  = ~(1 << i);

	int ans = n & mask;

	cout << "Number after setting the i'th bit "  << ans << endl;

	return 0; 


}