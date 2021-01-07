#include<iostream>
#include<math.h>
using namespace std ;

int main()
{
	long long int n,ans=0,a;
	int r ,c=0;

	cin >> n;

	a=n;
	while(a>0)
	{
		c++;
		
		a=a/10;


	}

	
	a=n;;
	while(a>0)
	{
		r = a%10;
		ans = ans + pow(r,c);
		a=a/10;
	}

	
	if(ans == n)
		cout << "true";
	else 
		cout << "false";

	return 0;
}