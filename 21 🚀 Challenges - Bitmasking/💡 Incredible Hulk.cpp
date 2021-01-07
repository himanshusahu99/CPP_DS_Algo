#include<iostream>
using namespace std;

int main()
{
	int t , no ; 

	cin >> t ; 

	while(t--)
	{
		cin >> no ; 
		int ans = 0; 
		while(no > 0)
		{
			no = (no & (no-1));
			ans++;
		}

		cout << ans << endl; 
	}

	return 0 ; 


}