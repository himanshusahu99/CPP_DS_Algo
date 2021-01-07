#include<iostream>
using namespace std;

int main()
{
	int min, max, step, cel;

	cin >> min >> max >> step;

	for(int i = min; i<=max; i+=step)
	{
		cel = ( 5*(i-32 ))/9;

		cout << i << " " << cel << endl;

	}

	return 0; 
}