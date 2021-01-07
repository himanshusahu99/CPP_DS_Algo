#include<iostream>
#include<vector>
using namespace std;
#define ll long long int 

vector<ll> primeSieve(ll *p, ll n )
{
	p[0] = p[1] = 0; 
	p[2] = 1;

	//marking all odd number as prime
	for(ll i = 3; i<n; i += 2 )
		p[i] = 1; 

	//Seive
	for(ll i =3 ; i<n; i += 2)
	{
		if(p[i]==1)
		{
			for(ll j = i*i; j<n; j += i )
				p[j] = 0; 
		}
	}


	std::vector<ll> primes;
	for(ll i =0; i<n; i++)
	{
		if(p[i] == 1 )
			primes.push_back(i);
	}

	return primes; 
}


int main()
{
	ll n; 
	cin >> n; 

	ll precal[1000000] = {0};
	vector<ll> primes = primeSieve(precal, 1000000); 

	cout << primes[n-1]; 

	return  0;

}