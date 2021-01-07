#include<iostream>
using namespace std;
bool findcowlace(int a[], int n , int cow, int mid)
{
	int last_posi = a[0];
	int cnt = 1;

	for(int i = 1 ; i<n; i++)
	{
		if(a[i]-last_posi >= mid)
		{
			last_posi = a[i];
			cnt++;
		}

		if(cnt==cow)
		{
			return true;
		}

	}

	return false;
}

int main()
{
	int a[] = {1,2,4,8,9};
	int n = 5 ;

	int cow = 3;

	int s = 0;
	int e = a[n-1]-a[0];
	int ans = 0; 
	while(s <= e)
	{
		 int mid = (s+e)/2;

		 bool cow_posi = findcowlace(a, n, cow, mid);
		 if(cow_posi)
		 {
		 		ans = mid;
		 	s= mid + 1;
		 }
		 else
		 	e= mid -1 ;

	}

	cout << "Maximm position is " << ans << endl;
	return 0; 

}