#include<iostream>
using namespace std;

int main(){

int row, col  ;

cout << "Enter array size (row and col ) ";

cin >> row >> col;

cout << " array element : " << endl;

int val = 1 ;
int a[4][4];

for (int i = 0; i < row ; ++i)
{
	for(int j =0; j< col ; j++){
			
			a[i][j] = val;

			cout << a[i][j] << " ";

			val+=1;
		}

		cout << endl;
}

cout << endl << "Wave print is here " << endl;


for(int i = 0; i<col ; i++){

	if(i%2 == 0){
		for (int j = 0; j < row; ++j)
		{
			cout << a[j][i] << " ";
		}
	}

	else 
		for (int j = row-1 ; j >=0; --j)
		{
			cout << a[j][i] << " ";

		}

		cout << endl;
}



return 0;





}