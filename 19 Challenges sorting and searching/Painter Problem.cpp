#include<iostream>
#include<algorithm>
#include<numeric>
#include<climits>
using namespace std;

bool isPossible(int boards[], int n , int painters, int time , int mid){
	
	int count_the_pianter= 1 ;
	int total_pinted = 0; 


	for(int i =0; i<n; i++)
	{
		if(boards[i] > mid)
		{
			return false;
		}

		if(total_pinted + boards[i] <= mid )
		{
			total_pinted += boards[i];
		}

		else 
		{
			count_the_pianter++;
			total_pinted = boards[i];
			if(count_the_pianter >painters)
			return false; 
		
		}

		
	}

	//cout << " true " << endl ; 
	return true; 
}


int painterProblems(int boards[], int n , int painters, int time )
{
	int s = *max_element(boards, boards+n);
	int e  = 0; 
	e =  accumulate(boards, boards+n, e);
	//cout << "e " << e << endl;
	int ans = INT_MAX;



	while(s <= e )
	{
		int mid = (s+e)/2;
		// cout << "s " << s << " e  " << e << " mid " << mid << endl ; 
		if(isPossible(boards, n, painters, time , mid)){
			 ans=  min(ans,mid);
			e = mid -1;
		}

		else
			s = mid+1;
	}

	return ans; 
}

int main()
{
	int sizeOfarray , painters , time; 
	/*
		n = size of array 
		k = no. of painters ;
		t = time taken to paint each board by the painter 
		li = size of n boards

	 */ 

	cin >> sizeOfarray >> painters >> time; 

	int boards[sizeOfarray];
	int i ;
	for ( i = 0; i < sizeOfarray; i++)
	{
		cin >> boards[i];
		
	}

	//cout <<" i " <<  i << endl; 

	int ans =  painterProblems(boards, sizeOfarray, painters, time ); 

	//cout << " ans " << ans << endl; 
	 cout<<((ans%10000003)*time)%10000003<<endl;    

	//cout << "i " << i << endl ;

	return 0;
}