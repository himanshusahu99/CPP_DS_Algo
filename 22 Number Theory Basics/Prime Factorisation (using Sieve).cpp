#include<iostream>
#include<vector>
using namespace std;

vector<int> PrimSieve(int *p, int n )
{
	p[2] =1 ;
	p[1]=p[0] = 0; 

	//mark all odd number as prime
	for (int i = 3; i < n; i += 2 )
	{
		p[i] = 1;
	}

	//Sieve
	for(long long int i = 3 ; i < n; i += 2 )
	{
		//mark all divisor of prime number as a zero(not prime)
		if(p[i] == 1)
		{
			for(long long int j = i*i ; j<=n; j += i )
			{
				p[j] = 0; 
			}
		}
	}

	vector<int> prime;

	for (int i = 0; i < n; ++i)
	{
		if(p[i] == 1)
			prime.push_back(i);
	}


	return prime; 
}

vector<int> Factorize(int m, vector<int> &prime)
{


	vector<int> Factor; 
	Factor.clear();

	int i = 0; 
	///cout << "printign i " << i<< endl; 
	int p = prime[0]; // p == 2 
	//cout << " printing p first time   " << p; 


	while(p*p < m )
	{
		if(m %p == 0)
		{
			Factor.push_back(p);

			while(m%p == 0 )
			{

				m = m/p ; 
			}
		}

		i++;
		p = prime[i]; 
	}

	if( m != 1 )
		Factor.push_back(m);



	return Factor; 
}

int main()
{
	int p[1000000] = {0};
	vector<int> prime = PrimSieve(p ,10000);

	
	int t;
	cin >> t;

	//cout << " t " << t << endl;
	
	while(t--)
	{
		int no; 
		cin >> no; 
		//cout << "inside main " << no << endl ;
		
		vector<int> factor = Factorize(no, prime);
		//cout << " after in main no " << no; 
		for(auto f: factor)
			cout << f << endl; 
	} 


	return 0; 

}