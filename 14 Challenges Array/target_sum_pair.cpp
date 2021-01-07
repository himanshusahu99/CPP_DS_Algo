#include<iostream>
#include<algorithm>
using namespace std;

void findsum(int *a, int n, int target){
	int i =0; 
	int  j = n-1; 
	sort(a,a+n);
	while(i<j){
		int s = a[i] + a[j];


		if(s == target)
			{
				cout << a[i] << " and " << a[j] << endl;
				i++;
				j--;
			}
		else if(s<target)
			i++;
		else
			j--;
	}
}

int main()
{
	int n;

	cin >> n;

	int a[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

 int target ;

 cin >> target;


	findsum(a,n, target);

	return 0;
}