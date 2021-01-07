#include<iostream>
using namespace std;

int main()
{
	int n , no;

	cin >> n ;

	while(n-- )
	{
		cin >> no;
		int ans = 0; 
		while(no  > 0 )
		{
			no = no & (no-1);
			ans++; 
		}

		cout << ans << endl; 
	}

	return 0; 
}