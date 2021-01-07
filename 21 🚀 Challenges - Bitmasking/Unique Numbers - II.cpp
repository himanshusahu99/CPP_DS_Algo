#include<iostream>
using namespace std;

int main(){
	int n;

	cin >> n ;
	int a[n];  
	int result = 0  ; 

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i]; 
		result = result ^ a[i] ; 
	}

	int temp = result; 
	int pos = 0 ; 

	while((temp & 1 ) != 1 )
	{
		pos++;
		temp = temp >> 1; 
	}

	int mask = (1 << pos);

	int x = 0; 
	int y = 0 ;

	for(int i = 0; i < n; i++)
	{
		if ((a[i] & mask)  > 0 )
		{
			x = x^ a[i];
		}
	}

	y = result ^ x ; 

	cout << min(x,  y) << " " << max(x ,y );


	return 0;
}