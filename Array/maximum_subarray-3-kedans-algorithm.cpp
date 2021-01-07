#include<iostream>
using namespace std;

int main()
{
	int  n;
	cout << "Enter array size " <<endl;

	cin >> n;
	int a[7];
	
	int curr_sum = 0;

	int max_sum = 0;

	int left = -1;
	int right = -1;

	cout << "enter array element " <<endl;

	cin >> a[0];

	int cs =0 ;
	int ms = 0; 


	for(int i = 1; i< n; i++)
	{
		cin >> a[i];

	}

	for(int i=0; i<n; i++){

		cs = cs + a[i];

		if(cs <=0)
			cs = 0;

		ms = max(cs, ms);
		
		
	}


	cout << endl << "Maximum Subarray is " << ms ;

 	cout << endl << "And Subarray is " << endl;

 	for (int i = left; i <= right; ++i)
 	{
 		cout << a[i] << ", " ;
 	}
	return 0;


}