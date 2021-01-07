#include<iostream>
using namespace std;

int main ()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{

		for (int j = 1; j <= i; ++j)
		{
			
			if(i<=1)
				cout << "1";
			else
			{
				cout << i << " ";

				for(int k = 1 ; k <= (i-2); k++ )
					cout << "0 ";

				cout << i;

				break;
			}
		
		
	}
	cout << endl;
		


}
return 0;	

	
}