#include<iostream>
#include<cstring>
using namespace std;

void character_formatting(char *str,  int i)
{

	if(str[i] == '\0')
		return; 

	if(str[i] == str[i+1])
	{
		
		

		for(int j = strlen(str); j>i; j--)
		{
			str[j] = str[j-1]; 
		}

		str[i+1] = '*'; 



		character_formatting(str, i+2); 
	}

	character_formatting(str, i+1); 
}


int main()
{
	char str[10001];
	cin >> str; 

	character_formatting(str, 0); // 0 - index zero

	cout << str; 

	return 0; 
}