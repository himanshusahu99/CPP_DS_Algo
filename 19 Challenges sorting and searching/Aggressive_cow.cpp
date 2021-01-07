#include<iostream>
#include<algorithm>
using namespace std;

bool isPosssible(int arr[], int n, int c, int mid )
{
	int Count_cow = 1; 
	int last_cow = arr[0]; 

 for(int i=0; i<n; i++)
	{	
		if(arr[i] - last_cow >=mid )
			{
				last_cow = arr[i];
				Count_cow++;
			}

		if(Count_cow == c)
			return true;


		

	}

	return false; 	

}


int findStall(int arr[] , int n , int c)
{
	int s = arr[0];

	int e = arr[n-1];

	int ans = 0; 



	while(s <= e)
	{
		int mid = (s+e)/2;

		if(isPosssible(arr, n , c , mid))
		{
			ans = mid;
			s = mid+1;
		}

		else
			e = mid-1;
	}

	return ans; 
}

int main(){

	int n , c ;

	cin >> n >> c; 

	int stall[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> stall[i];
	}

	sort(stall, stall+n);

	cout << findStall(stall, n , c ); 

	return 0; 


}