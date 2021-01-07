#include<iostream>
#include<climits>
using namespace std;

bool isPossible(int *arr, int n, int m , int mid)
{
	int studentUsed = 1;
	int page = 0; 

	for (int i = 0; i < n; ++i)
	{
		if(page + arr[i] >mid)
		{
			studentUsed++;
			page = arr[i];
			if(studentUsed > m)
			{
				return false;	
			}

		}
		else
			page += arr[i];
	}
	return true;
}

int bookallocation(int arr[] , int n, int m)
{
	int ans = INT_MAX;
	int s = arr[n-1];

	int sum = 0 ; 
	//cout << sum; 
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
	}

	int e = sum;

	
	while(s <= e)
	{
		int mid = (s+e)/2;

		//cout << "mid " << mid << endl; 

		if(isPossible(arr, n, m, mid))
		{
			ans = min(ans, mid);
			e= mid - 1;
		}

		else
			s= mid + 1; 
		
	}

	return ans;
}

int main()
{
	int t; 
	cin >> t;


	int n , m;


	while(t--)
	{
		cin >> n >> m; 
		int arr[n];

		for (int i = 0; i < n; ++i)
			{
				cin >> arr[i];
			}
			
		

		 
		cout << bookallocation(arr, n, m) << endl; 

	}

	return 0 ;
}