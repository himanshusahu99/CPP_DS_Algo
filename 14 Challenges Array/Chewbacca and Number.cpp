#include<iostream>
#include<climits>
using namespace std;

int main()
{
	string n;

	cin >> n;

	string o(n);
	for(auto& digit : n ){
		if(digit> '4' ){
			digit = '9' - digit + '0' ;
		}
	}

	if(n.front() == '0')
		n.front() = '9';

	

	if(n<o)
		cout << n;
	else
	cout << o;  
	return 0;	

	
}