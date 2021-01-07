#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

bool IfPossible(int arr[] , int n, int parata, int mid)
{
	//n == total cooks;
	int current_cook = 0 ;
	int total_parata = 0;
	int time_taken = 0; 
	int i = 1; 
	
	while(total_parata < parata){
		time_taken += (i*arr[current_cook]);
		
		if(time_taken>mid){
					
			current_cook++;
			time_taken = 0; 
			i = 1 ; 
		} 
		
		else{ 
			total_parata++;
			i++;
		}
		

		if(current_cook > (n-1))
			{
				//cout << endl << false << endl; 
				return false;
			}

	}

	return true;

}

int findMinTime(int arr[], int n, int parata)
{
	// n == total cooks; 
	int ans = INT_MAX;

	int min_arr = *min_element(arr, arr+n);

	//cout << "min_arr " << min_arr << "||" ; 
	int s = 0;
	int e = (parata * ((parata/min_arr)+1))/2; // time by the fastest cook 

	
	while(s <= e )
	{
		int mid = (s+e)/2;

		//cout << "s and e " << s << " " << e << "||" << endl ;
		//cout << "mid outside  " << mid << "||";
		if(IfPossible(arr,n,parata,mid))
		{
			//cout << "mid " << mid << "||";
			ans = min(ans,mid);
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
	//cin << m;
	int parata;	
	int cook ;
	int arr[100];
	while(t--){
		 
	
		cin >> parata;
	
	
		cin >> cook;
		for (int i = 0; i < cook; ++i)
		{
			cin >> arr[i];
		}
		cout << findMinTime(arr,cook,parata ) << endl;
	}
	
	//	cout << findMinTime(arr,cook,parata );

	return 0; 
}