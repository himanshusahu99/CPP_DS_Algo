#include<iostream>
using namespace std;
void merge(int arr[] , int s, int e )
{
	int mid = (s+e)/2;
	int i= s;//poin the start index of first part
	int j = mid+1;//points the start index of second part
	int k= s; // poin the start index of temp arr 
	int temp[100]; // will store sorted merged part in temp part then copy  

	while(i <= mid and j <= e)
	{
		if(arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++]= arr[j++];

	}		

	// if any element left in that divided array 
	while(i <= mid)
		temp[k++] = arr[i++];

	while(j<=e)
		temp[k++] = arr[j++];

	// copying the merged sorted array in original array 
	for(int i = s; i <= e ; i++)
		arr[i] = temp[i]; 


}



void mergesort(int arr[], int s, int e )
{
	//base case (0 or 1 element)
	if(s >= e )
		return ; 

	// follow the steps
	//1. divide 

	int mid = (s+e)/2;

	//recursively calling the mergesort fucntion; 

	mergesort(arr, s , mid);
	mergesort(arr, mid + 1, e); 

	// 2. sorting and merging wil; work in merge function 
	merge(arr, s ,e);  


}


int main()
{
	int arr[] = {46,234,47,213,45,32,1,2,4,90,6,5};
	int n = sizeof(arr)/sizeof(arr[0]);

	int s = 0 ; 
	int e = n-1; 
	mergesort(arr, s , n-1);

	for(int x : arr)
		cout << x << ", "; 

	return 0; 


}