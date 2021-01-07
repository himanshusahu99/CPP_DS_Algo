	#include<iostream>
	using namespace std;


void spiralprinting(int a[][7], int m , int n){

		int startrow = 0;
		int endrow = m-1;

		int startcol = 0;
		int endcol = n-1;


		//cout << "a[0][4] " << a[0][4] << endl << "beginging of the loop" << endl;
		while(startrow <= endrow and startcol <= endcol){


			// first row 
			for(int i =startcol; i<=endcol; i++)
			{
				cout <<a[startrow][i] << " ";
				//cout << endl << "For fisrt row " << i << " m";

			}

			startrow++;
			

			//cout << "startrow " <<startrow << " startrowt";

			//endcol

			for(int i =startrow; i<=endrow; i++){

				cout << a[i][endcol] << " ";
			}

			endcol--;
			
			//cout << endl;cout << "endcol " <<endcol << " startrowt";

			//Bottom Row 
			if(endrow > startrow){
				for(int i =endcol; i>= startcol; i-- ){
					cout << a[endrow][i] << " ";
				}
			}

			endrow--;


			//start col 
			if( endcol > startcol){
				for(int i = endrow; i>=startrow; i--){
					cout << a[i][startcol] << " " ;
				}
			}

			startcol++;
		


		}




	}

	int main(){

	int row, col  ;

	cout << "Enter array size (row and col ) ";

	cin >> row >> col;

	cout << " array element : " << endl;

	int val = 1 ;
	int a[7][7];

	for (int i = 0; i < row ; ++i)
	{
		for(int j =0; j< col ; j++){
				
				a[i][j] = val;

				cout << a[i][j] << " ";

				val+=1;
			}

			cout << endl;
	}

	cout << endl<< "Spiral print is here " << endl;

	spiralprinting(a,row,col);

	return 0;

	}