#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
ll a[1000005], pre[1000005];

int main()
{

	int t;
	
	int n; 
	cin >> t ;

	while(t--)
	{
		cin >> n; 
		memset(pre, 0, sizeof(pre));
		
		pre[0] = 1;
		int sum = 0;
		for(int i =0; i<n; i++)
		{
			cin >> a[i];
			sum += a[i];
			sum %= n;
			sum = (sum+n)%n;
			pre[sum]++;
		}

		//cout <<" pre = " ; 
	/*	for(int i = 0; i<n+1; i++)
		{
			cout << pre[i] << " " ; 
		}
*/
		//cout << endl;
		ll ans = 0;
		for(int i = 0; i<n; i++)
		{
			ll m = pre[i];
			ans += m*(m-1)/2;
		}

		cout << ans << endl;
	}


	return 0;

}