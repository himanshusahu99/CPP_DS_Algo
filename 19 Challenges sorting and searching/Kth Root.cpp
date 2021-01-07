	#include<iostream>
	#include<climits>
	#include<math.h>
	using namespace std;
	#define ll long long int

	bool isPossible(ll n , ll k, ll mid)
	{
		//cout << "mid " << mid << " pow " ; 
		//cout << pow(mid , k ) << endl;
		if (pow(mid, k ) <= n)
			return true;
		else
			return false;
	}

	int findKthroot(ll n , ll k)
	{	

		ll ans  = 1; 
		//cout << "ans1   " << ans << endl ;  

		ll s = 2;// k==1 already have as a condition 
		ll e = n; 
		//cout <<"S " <<  s <<  " e " <<e <<  endl ; 
		while(s <= e)
		{	

			//cout << "s and e " << s << " " << e << endl ;
			ll mid= (s+e)/2;

			//cout << "mid "<< mid << endl; 
			if(isPossible(n,k,mid))
			{
				ans = max(mid, ans);
				s = mid +1;
			}

			else 
				e = mid - 1 ;

		}

		//cout << ans << endl;
		return ans;
	}

	int main()
	{
		int t;
		cin >> t ;
		

		ll n;
		ll k ; 
		
		while(t--)
		{
			cin >> n >> k;

			//cout << n <<" " <<  k;  
			if(k==1)
				cout <<  n ;
			else
				cout << findKthroot(n , k );

			cout << endl;
		}



	}			