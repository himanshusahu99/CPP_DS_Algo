#include<iostream>
using namespace std;

int findelement(int *arr, int n , int key)
{
	if(n == 0)
		return -1; 
	if(arr[0] == key)	
		return 0 ;

	int index  = findelement( arr+1, n-1, key);

	if(index == -1)
		return -1;

	return index+1; 
}


/// basic for loop as recursive funtion 

int Basic_loop_for_findig_element(int *arr, int n, int key, int i)
{
	if(i==n)
		return -1 ;

	if(arr[i] == key)
		return i ;

	return Basic_loop_for_findig_element(arr, n, key, i+1 );
}

int main()
{
	int arr[] = {2,6,1,4,7,9,3,7};

	int n = sizeof(arr)/sizeof(arr[0]);

	int key = 7;

	cout << findelement(arr, n, key) << endl;
	cout << Basic_loop_for_findig_element(arr, n, key, 0); 

	return 0; 
}