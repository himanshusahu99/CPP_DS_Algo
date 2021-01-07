#include<iostream>
using namespace std;
#define ll long long

int main()
{
	ll primes[] = {2,3,5,7,11,13,17,19};

	

	ll t ;
	cin >> t ;
	ll subset_length = (1 << 8 ) -1 ; 	

	while(t--){
		
		ll n ;
		cin >> n; 
		
		ll ans  = 0; 
	
		for (ll i =1; i <= subset_length; i++)
		{
			ll denom = 1; 
			ll setbits = __builtin_popcount(i); 
			
			ll k = i;
			ll j = 0 ; 
			while(k>0)
			{
				if(k & 1)
				{
					//cout << primes[j] << " " ;
					denom *= primes[j];	

				}
				k= k>>1;
				j++;
			}

			/* for(ll j=0; j<=7; j++)
				{
					if(i & (1<<j)
					denom *= primes[j];
				}
			

			*/

			
	
			if(setbits&1)
				ans += (n)/denom; 
			else
				ans -= (n)/denom; 
	
		}
		cout << ans << endl ; 
	}
	

	return 0; 
}