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

	for(int i = 0; i< n; i++)
	{
		cin >> a[i];
	}

	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){

			int curr_sum = 0;
			for(int k = i; k<=j; k++)
				{
					cout << a[k] << ",";
					curr_sum = curr_sum + a[k];
				}

				if(curr_sum > max_sum){
									
					max_sum = curr_sum;

					left = i;
					right = j;

				}

			cout << endl;
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