#include<iostream>
using namespace std;

int merge(int a[], int s, int e)
{
	int mid = (s + e )/2;
	int i = s ;
	int j = mid+1 ;
	int k = s; 
	int temp[1000]; 
	int count = 0; //corss inversion 

	while(i <= mid and j <= e)
	{
		if(a[i] <=   a[j])
		{
			temp[k++] = a[i++];
		}

		else
		{
			temp[k++] = a[j++];
			count  +=    mid + 1 -i ; 
		}
	}

	while(i <= mid)
		temp[k++] = a[i++];

	while(j <= e)
		temp[k++] = a[j++]; 


	for (int i = s; i <= e; ++i)
	{
		a[i] = temp[i]; 
	}

	return count; 
}


int inversion_sort(int arr[], int s , int e )
{
	//base case 
	if(s >= e)
		return 0; 

	//merge sort 
	int mid = (s+e)/2;

	int x = inversion_sort(arr, s, mid);
	int y = inversion_sort(arr, mid+1, e);
	int z = merge(arr, s, e ); 

	return x+y+z ; 
}

int main()
{
	//int n ;
	//cin >> n;
	int arr[] = {1,5,2,6,3,0}; 

	/*for (int i = 0; i <6 ; ++i)
	{
		cin >> arr[i]; 
	}
*/	
	int n = sizeof(arr)/sizeof(int);

	cout << inversion_sort(arr, 0 , n-1); 

	return 0; 
}