#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void Change(string &s)
{
	s[0] = 'O'; 
	s[3] = 'K'; 
}

int main()
{
	string str = "ram"; 
	char d[] = "ram"; 

	Change(str); 
cout << str << endl ;
	cout << str.length() << endl ;
	cout << strlen(d) << endl ; 

	return 0; 

}