#include<iostream>
using namespace std;

int lastOccur(int *arr, int n , int key)
{
	//base case
	if(n==0)
		return -1 ;

	int index = lastOccur(arr+1, n-1, key);
	if(index == -1)
	{
		if(arr[0] == key)
			return 0; 
		else
			return -1 ;

	}

	return index + 1; 
}



int main()
{
	int n; 

	cin >> n; 

	int arr[n];
	for(int i = 0 ; i<n; i++)
	{
		cin >> arr[i]

	}


	int key;

	cin >> key ; 

	cout << lastOccur(arr, n, key) << endl;
	

	return 0; 
}