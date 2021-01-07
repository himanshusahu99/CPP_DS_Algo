#include<iostream>
using namespace std;
#define ll long long
int main()
{
	ll a, b ,c;

	cin >> a >> b >> c;

	ll ans = 1; 
	while(b > 0)
	{
		int last_bit = (b & 1);
		if(last_bit)
			ans = (ans*a)%c; // multiply with current value of a 

		a = (a*a) % c ;  
		b = b>> 1;
	}

	cout << ans%c; 
}