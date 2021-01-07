#include<iostream>
using namespace std;
#define ll long long
// 1. find GCD 
// 2. then find LCM


ll findGCD(ll a , ll b)
{
	return b==0 ? a:findGCD(b, a%b);
}

ll findLCM(ll gcd, ll a, ll b)
{
	return (a*b)/gcd;
}

int main()
{
	ll a, b, gcd; 

	cin >> a >> b;

	 gcd = findGCD(a ,b);

	 cout << findLCM(gcd, a, b);
}