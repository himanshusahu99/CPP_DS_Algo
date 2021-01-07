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
	int arr[] = {2,6,1,4,7,9,10, 11, 12,7, 13};

	int n = sizeof(arr)/sizeof(arr[0]);

	int key = 7;

	cout << lastOccur(arr, n, key) << endl;
	

	return 0; 
}