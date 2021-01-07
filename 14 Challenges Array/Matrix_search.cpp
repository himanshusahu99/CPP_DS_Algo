#include<iostream>
using namespace std;

int main()
{
	int row, col;

	//cout<< "Enter row and column " << endl ; 
	cin >> row >> col ;
	int val = 1 ;
	int a[7][7];

	//cout << "Array element are : " << endl;

	for (int i = 0; i < row ; ++i)
	{
		for(int j =0; j< col ; j++){
				
				cin >> a[i][j];// = val;

				//cout << a[i][j] << " ";

				//val+=1;
			}

			//cout << endl;
	}


	//cout << endl << endl << "Enter no to be searched : " ;
	int n;

	cin >> n;

	int i=0 ,  j= col-1, flag=0;

	

	while(n != a[i][j] ){
			
		if (n < a[i][j]){
			
			j--;
		}

		else if(n>a[i][j]){
			
			i++;

		}

		if( row < i or j < 0 )  {
			

			flag =1 ;
			break;

			
		}


	}  

	if(flag == 1 )
		cout << "0";
	else cout << "1";


	return 0;
}