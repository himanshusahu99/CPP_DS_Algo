#include<iostream>
using namespace std;

int main()
{
	int n, no; 
	cin >> n;

	int a[64] = {0}; 
	for (int i = 0; i < n; ++i)
	{
		cin >> no ; 
		int j = 0; 
		while(no > 0 )
		{
			int last_bit = (no & 1 );

			a[j] = a[j] + last_bit; 
			no >>= 1; 
			j++; 
		}
	}

	//iterating trhough the array 

int ans =0 ;
int p = 1 ;
	for (int i = 0; i < 64; ++i)
	{
		a[i] %= 3; 
		ans = ans + a[i] * p;
		p = p*2;
	}

	cout << ans ; 
}