#include<iostream>
#include<cstring>
using namespace std;

bool ispalindrom(char a[])
{
	int i =0; 
	int j = strlen(a)-1;

	while(i<j){
		if(a[i]==a[j])
		{
			i++;
			j--;

		}

		else
			return false;
	}

	return true;
}

int main()
{

	char a[100];

	cin.getline(a,100);

	

	if(ispalindrom(a)){
		cout << "Palindrome ";}

	else
		cout << "Not a Palindrome";

return 0; 
	}

