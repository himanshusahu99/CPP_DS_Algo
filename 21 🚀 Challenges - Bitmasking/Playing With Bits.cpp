#include<iostream>
using namespace std;



int main()
{

	int q , a , b;

	cin >> q ;
	while(q--)
	{
		cin >> a >> b ;
		int ans = 0;
	//	cout << "a " << a << " b" << b<< endl ;

		for(int i = a ; i<=b ; i++)
		{
			int temp = i ; 
			while(temp  > 0 )
				{
					temp = (temp & (temp-1));
					ans++;
				}
				//cout << " i " << i << " q  " << q << endl;
		}
		cout << ans << endl ; 
	}


return 0 ;
}