#include<iostream>
using namespace std;

void prime_Sieve(int *p, int n )
{
	//mark all odd number as a prime 
	for (int i = 3; i < n; i += 2)
	{	
		p[i] = 1;
		  
	}

	//Sieve Program 

	for(long long int i = 3; i <n; i += 2 )
	{
		//if the current is prime (not marked)
		if(p[i] == 1)
		{

			//mark all the multiple of i as not prime 
			for(long long int j = i*i; j <n; j += i)
			{
				
				p[j] = 0; 
			}
		}
		
	}


	//special case
	p[2] = 1;
	p[1] = p[0] = 0 ; 
}

int main()
{
	int n ; 
	cout << "Enter range from 0 to .....   :- "; 
	cin >> n ; 

	int p[n] = {0} ;



	prime_Sieve(p, n);

	for(int i = 0; i<n; i++)
	{
		
		if(p[i] == 1 )
			cout << i << " "; 
	}

	return 0; 
}