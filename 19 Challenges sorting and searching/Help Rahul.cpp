#include<iostream>
using namespace std;

int finde_index(int a[], int n , int k)
{
	int s =0; 
	int e = n-1;

	if(k == a[s])
		return 0; 
	else if (k == a[e])
		return n-1; 

	while(s <= e)
	{
		int mid = (s+e)/2;

		if(a[mid] == k)
			return mid;

		if(a[s] <= a[mid])
		{
			if( a[s] < k and k < a[mid] )
				e = mid -1;

			else
				s = mid+1;
				
		}

		else
		{
			if(a[mid]<k and k<a[e])
				s = mid+1; 
			else
				e= mid-1;
		}
	}

	return -1;
}


int main(){

	int n;

	cin >> n;

	int a[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int key;
	cin >> key;
	cout << finde_index(a,n,key);


	return 0; 
}