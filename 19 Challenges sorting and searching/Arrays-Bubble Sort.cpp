#include<iostream>
using namespace std;

int main()
{
	int n; 
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n-1; ++i)
	{
		for(int j = 0; j< n-i-1; j++ )
		{
			if(arr[j] > arr[j+1])
			{
				int t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t; 
			}
		}
	}


	for(int x:arr)
		cout << x << endl	;  
}