#include<iostream>
using namespace std;

int first_occurence(int a[], int n , int k)
{
	//cout << k << " " << n << " " ;
	int  s = 0;
	int e = n-1;

	int ans  = -1;
	
	while(s<=e){
		int mid = (s+e)/2;
		
		if(a[mid] == k)
		{
			ans = mid;
			e = mid-1;

		}

		else if( a[mid] > k )
			e = mid-1;
		else
			s= mid+1;

	}

	return ans ;
}

int last_occurence(int a[], int n , int k)
{
	//cout << k << " " << n << " " ;
	int  s = 0;
	int e = n-1;

	int ans  = -1;
	
	while(s<=e){
		int mid = (s+e)/2;
		
		if(a[mid] == k)
		{
			ans = mid;
			s = mid+1;

		}

		else if( a[mid] > k )
			e = mid-1;
		else
			s= mid+1;

	}

	return ans ;
}


int main()
{
	int a[] = {1,2,3,4,4,4,4,4,5,6,7};

	int n = sizeof(a)/sizeof(int);

	cout << "Enter Your Number "; 
	int key ;
	cin >> key; 	

	cout << "Lower Bound "<<first_occurence(a,n,key) << endl ;
	cout << "Upper Bound "<<last_occurence(a,n, key);

	return 0; 
}