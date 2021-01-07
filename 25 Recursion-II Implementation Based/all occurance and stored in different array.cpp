#include<iostream>
using namespace std;

int storedArr(int *arr, int n, int key, int i , int j , int *out)
{
	if(i==n)
		return j ; // denotes count of element in the array

	if(arr[i] == key)
	{
		out[j] = i;
		return storedArr(arr, n, key , i+1, j+1, out);
	}

	return storedArr(arr, n, key , i+1, j, out);
}

void allOccu(int *arr, int n, int i , int key)
{
	// base  case 
	if(i==n)
		return ; 
	if(arr[i] == key)
		cout << i << ", "; 

	allOccu(arr, n, i+1, key);
}


int main()
{
	int arr[] = {1,2,3,4,45,32,7,323,23,23,7}; 

	int n = sizeof(arr)/sizeof(arr[0]);
	int key = 7;

	// printing all the occurance in array 
	allOccu(arr,n, 0, key );
	cout << endl ;


	// storing occurance indexes in output array
	int out[1000]; 

	int no_of_element = storedArr(arr ,n, key, 0, 0, out); // will get the value of j 


	for(int i = 0; i<no_of_element; i++)
		cout << out[i] << ", "; 


	 return 0; 
}