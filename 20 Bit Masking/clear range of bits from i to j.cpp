#include <iostream>
using namespace std;

int main()
{
	int n;

	cout << "Enter your number "; 
		cin >>n ;
	
	int i ;
	cout << "Enter first position (start from zero) " ; 
	cin >> i ; 

	cout << " Enter last position (start from zero) " ;
	int j ;

	cin >> j; 

	int a = (-1 << (j+1 ));

	int b = (1 << i) -1 ;
	int mask = a | b ;  

	
	int ans = n & mask; // clearing the bit of i'th place 

	// now taking the v to the i'th  place i.e. V << i and then Perform OR 

	
	cout << "Numbe after clearing bit from " << i << " to " << j << "  :- "  << ans << endl;

	return 0; 


}