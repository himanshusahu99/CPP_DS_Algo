#include<iostream>
using namespace std;

char number[11][10] = {"zero", "one", "two","three","four","five","six","seven","eight","nine","ten"}; 

void spell(int n)
{
	//base case 
	if(n==0)
		return ; 


	spell(n/10); 
	int digit = n%10;

	cout << number[digit]; 
}

int main()
{
	int n;

	cin >> n;

	spell(n); 


}