#include<iostream>
using namespace std;
#define ll long long

void PrimeSieve(int *p, int n )
{
	p[2] =1 ;
	p[0] = p[1] = 0;

	for(ll i = 3; i<n; i+=2)
		p[i] = 1;

	for(ll i = 3; i<n; i+=2)
	{
		if(p[i]==1)
		{
			for(ll j = i*i; j<n; j += i)
				p[j] = 0; 
		}
	}


	
}
	
int main()
{
	int n = 1000005;
	int p[1000005] = {0};
	PrimeSieve(p , n);
	int countPrimes[1000005] = {0};
	

	for(ll i=1; i<n; i++)
	{
		countPrimes[i] = countPrimes[i-1] + p[i];
	}



	int t;

	cin >> t; 
	while(t--)
	{	
		int a ,b;

		cin >> a >> b;

		cout <<  countPrimes[b]- countPrimes[a-1] << endl; 
	}
}