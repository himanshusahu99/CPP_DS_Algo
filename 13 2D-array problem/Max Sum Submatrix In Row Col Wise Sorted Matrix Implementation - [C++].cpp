#include<iostream>
#include<climits>
using namespace std;


int countNoOfSubMatrix_Row_wise(int **arr, int n , int m){


	//suffix col sum
	for(int col = n-1 ; col>=0; col--)
	{
		
		for(int row = m-2 ; row>=0; row--){
			arr[col][row] += arr[col][row+1];
			
		}
		
	} 




	// suffix row sum;

	for(int row = n-1; row >=0; row--){
		for(int col = m-2; col >=0; col--){
			arr[col][row] +=arr [col+1][row];

		}
	}


	for(int i = 0; i<n; i++)
	{
		for(int j =0; j < m; j++)
		{
			cout <<  arr[i][j] << " ";
		}
		cout << endl;
	}

	int result = INT_MIN;

	cout << "result " << result << endl;
	for(int i = 0; i<n; i++)
	{
		for(int j =0; j < m; j++)
		{
			result = max(result, arr[i][j]);
			cout << "col and row " <<  i <<" " <<   j << " " << result << " | ";
		}
		cout <<endl; 
	}


	return result; 
}

int main()
{
	int n , m ;

	cin >> n >> m;

	int **arr = new int*[n];

	for(int i = 0; i<n; i++)
	{
		arr[i] = new int[m];
	}

	for(int i = 0; i<n; i++)
	{
		for(int j =0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << endl <<endl << "sum "<< countNoOfSubMatrix_Row_wise(arr, n, m);

	return 0; 


}