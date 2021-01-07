#include<iostream>
using namespace std;
int binarySearch(int *arr, int number, int s , int e)
{
	//cout << s << " s" << endl << "e " << e  << endl; 
	if(e >= s)
	{
		int mid = (s+e)/2;
		//cout << mid; 
		if(arr[mid] == number)
			return mid;			
		else if (arr[mid] > number)
			return binarySearch(arr, number, s, mid-1);

		else
			return binarySearch(arr, number, mid+1, e);

	}
	
	
	return -1; 
}


int main()
{
	int arr[] = {11,12,13,14,15};
	int n =5 ;

	int number;

	cin >> number;
	
	;
	int index = binarySearch(arr, number, 0, n-1);

	cout << index ;
}