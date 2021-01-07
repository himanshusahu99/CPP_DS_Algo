#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[]  = {11,12,12,12,12,13,14,15,16 };

	int n = sizeof(a)/sizeof(a[0]);

	int k ;

	cin >> k ; 
	bool b  = binary_search(a,a+n, k); // binaray_search returns 0 or 1;

	if(b)
		cout<< "Present in the array ";

	else
		cout << "Not present "; 

	//lower bound  and upper bound 

	auto lb = lower_bound(a, a+n, k); // returns first address of number >= than k

	cout << endl << "lower bound " << lb-a; 

	auto ub = upper_bound(a, a+n, k);//return first address of number > than k
	cout << endl << "lower bound " << ub-a;

	// frequency of k in arr = up-lb
	/* 
		if k = 12;
		then lb = 1;
		and	ub = 5;

		then freq  = up-lb = 4;  		
	*/

	
	/* we can also check for presence of number in the array 
	if(lb-a == n ) 
		cout << endl << "Not present "; 
		*/

	cout << endl << "Frequency of number " << ub-lb << endl;
	

	return 0; 

}