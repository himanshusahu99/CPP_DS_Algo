#include<iostream>
using namespace std;
#define ll long long int
int findGCD(int a, int b)
{
	return b==0 ? a : findGCD(b , a%b);
}


int main()
{
	ll a, b;

	cin >> a >> b ;

	ll gcd  = findGCD(a, b ); 
	cout << gcd ; 

	return 0; 
}