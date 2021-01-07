#include<iostream>
#include<vector>
using namespace std;

vector<int> primes; 
int p[1000000] = {0}; 


void primeSieve(int *p)
{
	p[2] = 1;
	p[0] = p[1] = 0 ;

	//marking all odd number as prime number 
	for(int i = 3; i<1000000; i+=2)
		p[i]=1;

	//Sieve
	for(long long int i = 3; i<1000000; i+=2 )
	{
		if(p[i]==1)
		{
			for(long long int j = i*i; j<1000000; j+=i)
			{
				p[j]=0;
			}
		}
	}


	for(int i = 0; i<1000000; i++)
	{
		if(p[i] == 1 )
			primes.push_back(i);
	}



}


void divisorcount(int n, vector<int> primes)
{
	int ans = 1; 
	int i =0 ;
	int p = primes[i]; 
	
	while(p*p < n )
	{
		int cnt = 0; 
		while(n%p == 0)
		{
			cnt++;
			n=n/p;
		}

		ans = ans *(cnt+1);

	i++;
	p = primes[i];
	}

	if(n != 1)
		ans = ans *2;


	cout << ans; 
}


int main()
{
	
	primeSieve(p); 

	int number;
	cin >> number; 

	divisorcount(number, primes);
}