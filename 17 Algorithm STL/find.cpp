#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[] = {1,2,3,14,51,6,7};

	int n = sizeof(a)/sizeof(a[0]);

	int k ;

	cin >> k;

	auto  it  = find(a, a+n, k); //returns address

	int index = it - a;		// let it == arr+2  so arr+2-arr = 2 ; which is index
	if(index == n);
		cout << "Not Found ";

	else
		cout << "Found";

	return 0;

}