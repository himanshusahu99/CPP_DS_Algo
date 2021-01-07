#include<iostream>
using namespace std;

int main()
{
	int n;

	cin >> n; 

	int i =2 ;
	int arr[100000] = {0};
	arr[0] = 1;
	int len = 1; 
	int  x = 0; 


	while(i<=n){

		x = 0; 
		int num = 0; 
		while(x<len)
		{
			arr[x] = arr[x] * i + num;
			num  = arr[x]/10;
			arr[x] = arr[x]%10;
			x++; 
		}

		while(num != 0)
		{
			arr[len] = num%10;
			num = num/10;
			len++;
		}
		i++;

	}

	while(len--)
	{
		cout << arr[len];
	}

	return 0; 
}