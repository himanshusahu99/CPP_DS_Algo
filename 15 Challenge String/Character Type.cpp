#include<iostream>
using namespace std;

void chartect_type(char s)
{
	if(s >= 'A' and s<= 'Z')
		cout << 'U';
	else if(s >= 'a' and s <= 'z')
		cout << 'L';

	else
		cout << 'I';
}

int main()
{
	char s;

	s;
	cin >> s;

	chartect_type(s);
	return 0;
}