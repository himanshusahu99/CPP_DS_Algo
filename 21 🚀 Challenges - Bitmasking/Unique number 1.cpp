#include<iostream>
using namespace std;

int main()
{
	int n, no;
	int a[64] = {0};
	cin >> n ; 

	for (int i = 0; i < n; ++i)
		{
			cin >> no; 
			int j = 0 ; 
			while(no >> 0)
			{
				int last_bit = (no & 1 );
				a[j] = a[j] + last_bit;
				j++; 
				no >>= 1; 
			}

			//cout << " i " << i << endl ; 
		}


	int p = 1;
	int ans = 0 ; 
	// iterating through the array;
	for(int i = 0 ; i < 64; i++)
	{
		a[i] %= 2;
		ans = ans + a[i] * p; 
		p *= 2 ; 
	} 

	cout << ans ; 

	return 0 ; 

}