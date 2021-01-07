#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int a[] = {11,12,13,14,15};

	// rotate around a index
	int n = sizeof(a)/sizeof(a[0]);
	rotate(a, a+2,a+n);  // rotate around 2 index of the array 

	for(int i = 0; i<n; i++)
		cout << a[i] << " ";

	//for vecotr;

	cout << endl  << "On vector : ";
	
	vector<int> v{11,12,13,14,15};

	rotate(v.begin(), v.begin()+2, v.end());

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
}