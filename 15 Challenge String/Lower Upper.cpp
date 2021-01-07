#include<iostream>
using namespace std;

void chartect_type(char s)
{
	if(s >= 'A' and s<= 'Z')
		cout << "UPPERCASE";
	else if(s >= 'a' and s <= 'z')
		cout << "lowercase";

	else
		cout << "Invalid";
}

int main()
{
	char s;

	s;
	cin >> s;

	chartect_type(s);
	return 0;
}