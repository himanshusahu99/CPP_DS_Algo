#include<iostream>
using namespace std;

void insertionsort(int a[], int n)
{

	for(int i = 0; i<n; i++){

		int e = a[i];
		int j = i-1;

		while(j>=0 and a[j] > e)
		{
			a[j+1] = a[j];
			j--;
		}

		a[j+1] = e;


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

	insertionsort(a, 5);

	for (int i = 0; i < 5; ++i)
		cout << a[i] << ", " ;
	{
		/* code */
	}

	return 0;
}