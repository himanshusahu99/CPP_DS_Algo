#include<iostream>
using namespace std;

int main()
{
	int  n;
	cout << "Enter array size " <<endl;

	cin >> n;
	int a[7];
	int precomputing[7];
	int curr_sum = 0;

	int max_sum = 0;

	int left = -1;
	int right = -1;

	cout << "enter array element " <<endl;

	cin >> a[0];

	precomputing[0] = a[0];

	for(int i = 1; i< n; i++)
	{
		cin >> a[i];

		precomputing[i] = precomputing[i-1] + a[i];
	}

	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){

			int curr_sum = precomputing[j] - precomputing[i-1];

				if(curr_sum > max_sum){
									
					max_sum = curr_sum;

					left = i;
					right = j;

				}

		}

		
	}


	cout << endl << "Maximum Subarray is " << max_sum ;

 	cout << endl << "And Subarray is " << endl;

 	for (int i = left; i <= right; ++i)
 	{
 		cout << a[i] << ", " ;
 	}
	return 0;


}