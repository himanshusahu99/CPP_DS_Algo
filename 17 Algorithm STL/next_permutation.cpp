#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int a[] = {11,12,13,14,15};

	// rotate around a index
	int n = sizeof(a)/sizeof(a[0]);
	
	vector<int> v{1,2,3};

	//next_permutation gives just bigger number after arranging the array element 

	next_permutation(v.begin(), v.end());

	for(auto x:v)
		cout << x <<" ";


	cout << endl;
	next_permutation(v.begin(), v.end());

	for(auto x:v)
		cout << x <<" ";


}