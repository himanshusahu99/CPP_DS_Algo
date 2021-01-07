#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

vector<int> primes; 
bitset<1000000> p; 



void primeSieve()
{
	p.set();//setting all bit 1 1 1 1 1 1
	p[0] = p[1] = 0 ;

		//Sieve
	for(long long int i = 2; i<=1000000; i++ )
	{
		if(p[i])
		{
			primes.push_back(i); 
			for(long long int j = i*i; j<=1000000; j+=i)
			{
				p[j]=0;
			}
		}
	}

}

bool isPrime(long long int number)
{
	if(number <= 1000000) // n < 10^6
	{
		return p[number] == 1? true : false;    
	}

	else
		for(long long int i = number ; primes[i] * (long long)primes[i] <= number; i++ )
		{
			if (number % primes[i] == 0)
				return false;

		}

	return true;  
}


int main()
{
	long long int number;

	cin >> number;

	//cout << number; 
	if(isPrime(100000007) )
		cout << "Prime Number ";
	else
		cout << "Not a Prime Number";

}