#include<iostream>
using namespace std;


void bibblesort(int a[], int n )
{

	for(int i=0; i<n; i++)
	{
		for(int j = 0; j<=(n-1-i); j++)
		{
			if(a[j] > a[j+1])
				swap(a[j], a[j+1]);
		}
	}



}


int main()
{

	int  a[5];

	cout << "Enter array element " << endl;
	for (int i = 0; i < 5; ++i)
	{
		cin >> a[i];

	}

	bibblesort(a, 5);

	for (int i = 0; i < 5; ++i)
		cout << a[i] << ", " ;
	{
		/* code */
	}

	return 0;
}