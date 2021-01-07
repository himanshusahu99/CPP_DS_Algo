#include<iostream>
#include<climits>
using namespace std;

int main()
{
	int n =3, m=3;

	int a[n][m]= 	{-2, -4, -5, -3, 4, 5,-1, 3, 4 };



	int result = INT_MIN;

	for(int i = 0; i<n; i++)
	{
		for(int j =0; j < m; j++)
		{
			result = max(result, a[i][j]);
			cout << "col and row " <<  i <<" " <<   j << " " << result << " | ";
		}
		cout <<endl; 
	}
}