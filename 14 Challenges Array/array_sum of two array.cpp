#include<iostream>
using namespace std ;

void arraysum(int m[], int n[], int large, int low, int sum[])
{
	int carry = 0; 
	//cout << "large and small " << large << " " << low ;
		
	for(int i =large-1, j=low-1; i>=0 || j>=0; i--, j--)
	{
		
					if(j>=0)
					{
						//cout << endl << "i and j " << i << " " << j << " "  << "m[i] " << m[i] << "n[j]  " << n[j] ;
						//cout << endl << " m[i] + n[j] "<< m[i] + n[j]  ;
						sum[i]=n[j]+m[i]+carry;
						carry=(sum[i])/10;
						sum[i]=(sum[i])%10;
						//cout << " carry " << carry << " s[i] " << sum[i] << endl;
					}
					else
					{
						//cout << " else part ";
						sum[i]=m[i]+carry;
						carry=(sum[i])/10;
						sum[i]=(sum[i])%10;
					}


	}

	if(carry != 0 )
		cout <<  carry << ", ";

	for(int i = 0; i < large; ++i)
	 {
	 	cout << sum[i] << ", ";
	 } 
	 cout << "END"; 
}
int main()
{
	int m[1000], n[1000], sum[1000]; 
	int m1 , n1;

	cin >> m1;

	for (int i = 0; i < m1; ++i)
	{
		cin >> m[i];
	}

	cin >> n1;

	for (int i = 0; i < n1; ++i)
	{
		cin >> n[i];
	}

	if(m1>n1)
		arraysum(m, n, m1, n1, sum ); // loop from 0 -> m1 
	else
		arraysum(n,m , n1, m1, sum); // loop from 0 -> n1; also when m == n;


		return 0; 



}