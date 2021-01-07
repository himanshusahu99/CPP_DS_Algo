#include<iostream>
using namespace std;

void prime_Sieve(int *p)
{
	//marking all odd number as a prime 
	for(int i = 3; i < 1000000; i+=2)
		p[i] = 1;

	//Sieve
	for(long long int i = 3 ; i<1000000; i+=2)
	{
		if(p[i] == 1)
		{
			for (long long int j  = i*i; j < 1000000; j+=i)
			{
				p[j] = 0; 
			}
		}
	}

	//special cases
	p[2] = 1 ;
	p[1] = p[0] = 0 ; 
}


int main()
{
	int p[1000000] = {0};

	prime_Sieve(p);

	int precoompute[1000000] = {0};

	for (int i = 1; i < 1000000; ++i)
	{
		precoompute[i] = precoompute[i-1] + p[i]; 
	}

	int q;

	cin >> q;

	int a, b ; 
	while(q--)
	{
		cin >> a >> b ; 

		cout << precoompute[b] - precoompute[a-1] << endl; 
	}

	return 0; 
}
