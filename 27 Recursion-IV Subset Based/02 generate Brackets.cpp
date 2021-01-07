#include<iostream>
using namespace std;

void generate_Brackets(char *out, int n , int idx, int open, int close)
{
	//base case 
	if(idx == 2*n)
	{
		out[idx] = '\0';
		cout << out << endl; 
		return; 
	}

	//rec case 
	// 2 options
	if(open < n)
	{
		out[idx] = '(';
		generate_Brackets(out, n, idx+1 , open +1 , close);
	}

	if(close < open)
	{
		out[idx] = ')';
		generate_Brackets(out,n, idx+1, open, close + 1 );
	}

	return; 


}

int main()
{
	int n; 
	cin >> n;

	char out[10];
	int idx = 0 ; 

	generate_Brackets(out , n , idx, 0, 0);

	return 0; 

}