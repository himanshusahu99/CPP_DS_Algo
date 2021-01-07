#include<iostream>
using namespace std;

int partition(int arr[], int s, int e )
{
	int i = s-1; 
	int j = s ;
	int pivot = arr[e]; // taknig last element as a pivot 

	for(; j <= e-1;  ) // lase element is pivot so loop is upto e-1 ;
	{
		//merge intto smaller region 
		if(arr[j] <= pivot)
		{
			i++; 
			swap(arr[i], arr[j]);
		}

		//merge into larger region 
		j = j + 1; 
	}

	// place the pivot element in the correct position 
	swap(arr[i+1], arr[e]); 

	return i+1; 


}
void quicksort(int arr[], int s, int e  )
{
	// base case 
	if(s >= e)
	{
		return; 
	}

	//recursive case 
	int p = partition(arr, s, e); 

	//left part 
	quicksort(arr, s , p-1);

	//right part
	quicksort(arr, p+1 , e );
}

int main()
{
	int arr[] = {6,2,4,1,7,3,5};

	int s = 0 ;
	int e = sizeof(arr)/sizeof(int);

	quicksort(arr, s, e) ;

	for(int x :arr)
		cout << x << " " ; 


	return 0; 
}