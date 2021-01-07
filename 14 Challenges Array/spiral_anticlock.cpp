#include<iostream>
using namespace std;

void spiral_anti_clock(int a[][10], int m  , int n)
{
		int sr = 0, er = m-1;
		int sc = 0, ec = n-1;
		
		while(sr <= er and sc <= ec){
			//cout << "sr and er sc ec" << sr << er  << sc << ec << endl;
			//first col;
			for(int i = sr; i<=er; i++){
				//cout << "a["<<i<<"]["<<sc<<"] " 
				cout << a[i][sc] << ", " ;
				//cout << "i = " << i << endl; 
				
			}

			sc++;

			//bottom row 

			for(int i = sc; i<=ec; i++)
			{
				cout << a[er][i] << ", ";
			}

			er--;

			//last col 
			for(int i = er; i>=sr; i--)
			{
				cout << a[i][ec] << ", ";  
			}
			ec--;

			// first row 
			for(int i =ec; i>=sc; i--)
			{
				cout << a[sr][i] <<", ";
			}
			sr++;

		}
		cout << "END";

}

int main()
{
	int  m , n;
	int a[10][10];
	cin >> m >> n ;
	//int val =1;

	for(int i =0; i<m; i++)
	{
		for(int j =0; j<n; j++)
		{
			cin >> a[i][j];
			}
	}





	spiral_anti_clock(a, m, n );

	return 0;
}