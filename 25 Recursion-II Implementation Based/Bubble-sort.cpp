#include<iostream>
using namespace std;


void bubblesort(int *arr, int n, int j)
{
	if(n == 1)
		return;
	if(j == (n-1))
		return bubblesort(arr, n-1, 0);

	if(arr[j] > arr[j + 1])
		swap(arr[j], arr[j+1]);

	return bubblesort(arr, n, j+1);

}


int main()
{
	int arr[] = {12,34,11,90,32};
	int n = sizeof(arr)/sizeof(arr[0]);

	bubblesort(arr, n, 0);
	for(int x : arr)
		cout << x << ", ";

	return 0; 




}
