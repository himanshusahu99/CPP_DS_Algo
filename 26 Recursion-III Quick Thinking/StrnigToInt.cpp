#include<iostream>
#include<string.h>
using namespace std;

int stringToInt(char a[], int n )
{
	if(n==0)
		return 0 ;

	//lase digit 
	int digit = a[n-1] - '0'; 

	int number = stringToInt(a, n-1);

	return number *10+digit; 

}


int main()
{
	char a[14];  
	cin >> a;

	int n = strlen(a); 

	int number = stringToInt(a, n); 
	cout << number;
	cout << endl << number + 1; 


}