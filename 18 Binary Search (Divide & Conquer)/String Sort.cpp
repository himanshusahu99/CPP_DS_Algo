#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool sorting(string s, string j)
{
	int counter = 1 ; 
	int i = 0; 
	
	if( s[i] == j[i])
	{
		i++;
		while(s[i] == j[i])
		{	
			i++;
			counter++;
		}
	
		if(counter >=2 )
		{
			return s.length() > j.length()	; 
	
		}
	}


		return s <  j; 


}

int main()
{
	int n;

	cin >> n; 

	cin.get();

	string s[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}

	sort(s, s+n, sorting); 

	for(auto x : s)
		cout << x << endl; 

}