#include<iostream>
using namespace std;

int FindPivotElement(int arr[], int n )
{
	int s = 0; 
	int e = n-1; 

	int ans = 0 ; 

	while(s <= e )
	{
		int mid = (s+e)/2;

		//cout << "s " << s << " e " << e << " mid " << mid << " arr[mid] " <<  arr[mid] << endl;  

		if( mid < e and	arr[mid] > arr[mid+1])
			{
				ans = mid; 
				//cout << "ans " << ans << endl ;
				return ans;  
			}
		if ( mid > s and arr[mid] < arr[mid-1])
			{
				ans = mid-1;
				//cout << " 2ans " << ans << endl;
				return ans; 
			}

		if(arr[s] >= arr[mid])
		{
			e = mid-1;
		}

		else 
		{
			s = mid+1;
		}
	}

	return ans ; 
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

	//cout << "in the main "<<arr[2] << endl ;
	cout << FindPivotElement(arr, n);

	return 0; 




}