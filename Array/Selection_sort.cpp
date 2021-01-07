#include<iostream>
using namespace std;


void selectionsort(int a[], int n){
	for (int i = 0; i < n-1; ++i)
	{
		int midd = i;
		for (int j = i; j < n; ++j)
		{
			
			if(a[j] <a[midd] )
				midd = j;

		}

		swap(a[i], a[midd]);
	}

	
}


int main()
{

	int a[5];

	for (int i = 0; i < 5; ++i)
	{
		 cin >> a[i];
	}

selectionsort(a,5);

for(int i =0; i<5; i++)
	cout << a[i] << ", ";

	return 0;
}