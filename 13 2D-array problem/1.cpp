#include<iostream>
using namespace std;

int main()
{
	int a[2][2];
	

	int n;
	cin >> n;
	int sum = 0;

	for(int i= 0; i<n; i++)
	{
		for(int j =0; j<n; j++)
			{
				a[i][j] = 1;
				cout << a[i][j] << " ";
			}
	} 

	for (int li = 0; li < n; ++li)
	{
		for(int lj= 0; lj<n; lj++)
		{
			for(int bi = li+1; bi <n; bi++)
			{
				for(int bj = lj+1; bj < n; bj++)
				{
					for(int i=li; i<bi; i++)
					{
						for(int j = lj ; j<bj; j++)
						{
							sum = sum + 1;
						}
					}
				}
			}
		}		
	}

	cout <<endl << sum << endl ;
}