#include<iostream>
#include<climits>
using namespace std;

bool IsPossible(int arr[] , int n, int m ,int mid)
{
	int studentUsed = 1;
	int page = 0; 

	//cout << "mid " << mid << endl;

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

int findpages(int arr[], int n ,int m )
{
	int sum=0;


	if(n<m)
		return -1;

	for (int i = 0; i < n; ++i)
	{
		//cout << arr[i] << " " ;
		sum += arr[i];
	}

	int s = arr[n-1];
	int e = sum;
	int ans = INT_MAX;
	//cout<< "sum " << sum << endl;


	while(s<=e)
	{
		int mid = (s+e)/2;
		//cout << "inside findpages " << mid << endl; 
		if(IsPossible(arr, n , m , mid))
		{
			ans = min(ans, mid);
			e= mid-1;

		}
		else
			s = mid+1;
		
	}

	return ans;

}



int main()
{
	int t ;

	cin >> t; 
	int n ,m;

	
	while(t--)
		{
			cin >> n >> m;
			int arr[n];
			for (int i = 0; i < n; ++i)
			{
				cin >> arr[i];
			}
	

	


		cout << findpages(arr , n ,m ) << endl; 
	}
	}

