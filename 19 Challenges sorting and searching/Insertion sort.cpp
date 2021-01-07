#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; ++i)
	{
		int key = arr[i];
		int j = i-1; 

		while(j >= 0 and arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = key;


	}

}

int main()
{
	int n; 

	cin >> n ; 
	int arr[n];

	InsertionSort(arr, n );

	

	for(int x : arr)
		cout << x << " " ;

	return 0; 
}	