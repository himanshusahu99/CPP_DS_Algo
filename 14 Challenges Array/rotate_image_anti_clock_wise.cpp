#include<iostream>
using namespace std;

void rotate_image(int a[][100] , int m , int n ){

	//reversing 

	for(int i =0 ; i<m; i++){
		int start_row = 0; 
		int endrow = m-1;
		while (start_row < endrow){
			swap(a[i][start_row],a[i][endrow]);
			start_row++;
			endrow--;
		}
	}

	// Transposing 

	for(int i =0; i<m; i++)
	{
		for(int j =0; j< n; j++)
		{
			if(i<j){
				swap(a[i][j], a[j][i]);
			}
		}
	}


	//printing 


	for(int i =0; i<m; i++)
	{
		for(int j =0; j< n; j++)
		{
							cout <<  a[i][j] << " ";
	
		}
		cout <<endl;

	}

	


}

int main()
{
	int k,s,row,col;
	int a[100][100];
	// m,n = size of the grid 
	// s = current strength 
	// k = minimumn strength 

	cin >> row ;
	col  = row; 
	int val = 1;
	for (int i = 0; i < row ; ++i)
	{
		for(int j =0; j< col ; j++){
				
				

				cin >>  a[i][j];

				
			}

	}

	rotate_image(a,row,col);

	return 0;

}