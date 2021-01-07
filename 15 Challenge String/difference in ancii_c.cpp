#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;

	getline(cin, s);

	char t = s[0];

	cout << t;

	for(int i =1; i<s.length(); i++)
	{
		char a = s[i];
		cout << a-t;
		cout << s[i];
		t=s[i];
	}

		return 0; 


}