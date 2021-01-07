#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

bool isPossible(int arr[], int n , int total_painters , int mid)
{

	int curre_board = 0; 
	int current_pntr = 1; 

	for (int i = 0; i < n; ++i)
	{
		if(curre_board + arr[i] < mid){
			current_pntr++;
			curre_board = arr[i];

			if(current_pntr >total_painters)
			{
				return false;
			}
		}

		else
			curre_board += arr[i];
	}


	return true; 
}


int sum(int arr[], int n)
{
	int ans = 0 ;
	return accumulate(arr, arr+n, ans);
}

int main()
{
	int total_painters;
	int no_of_boards;

	cin >> total_painters;
	cin >> no_of_boards;

	int arr[no_of_boards];
	
	for (int i = 0; i < no_of_boards; ++i)
	{
		/* code */
	
		cin >> arr[i];
	}

	int s = *max_element(arr, arr+no_of_boards);

	int e = sum(arr, no_of_boards) ;
		
	int ans = 0 ;

	while(s<=e)
	{
		int mid = (s+e)/2;

		if(isPossible(arr, no_of_boards,total_painters,mid))
		{
			ans = mid;;
			e = mid -1 ;
		}
		else
			s = mid + 1; 

	}

	cout << "ans " << ans; 	return 0; 

}