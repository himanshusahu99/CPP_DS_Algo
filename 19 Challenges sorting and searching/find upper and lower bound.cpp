#include<iostream>
using namespace std;

int upper(int arr[], int n, int q)
{
	int s = 0; 
	int e = n-1;

	int ans = -1; 

	while(s <= e)
	{
		int mid = (s+e)/2;

		if(arr[mid] == q )
		{
			ans = mid;
			s= s+1; 
		}

		else if(arr[mid] < q)
		{
			s  = s+1; 
		}

		else
			e = e-1; 
	}

	return ans; 
}


int lower(int arr[], int n, int q )
{
	int s = 0; 
	int e = n-1; 
	int ans = -1; 

	while(s <= e )
	{
		int mid = (s+e)/2;
		if(arr[mid] == q)
		{
			ans = mid;
			e = e-1;
		}

		else if( q < arr[mid] )
		{
			e = mid -1;
		}

		else
			s= s+1; 
	}

	return ans; 
}


int main()
{
	int n;
	cin >> n ; 


	int arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int t ;
	cin >> t ;

	int q; 
	while(t--)
	{
		cin >> q; 	
		cout << lower(arr, n ,q) << " " << upper(arr, n,q) << endl ;
	}
	return 0; 


}