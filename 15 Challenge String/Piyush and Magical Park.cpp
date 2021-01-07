#include<iostream>
using namespace std;

void Piyush_and_Magical_Park(char a[][100], int m, int n, int k, int s ){


	bool success = true;

	for(int i =0; i<m; i++){
		for(int j =0; j<n; j++){

			if(s<k){
				success = false;
				break;
			}


			else if(a[i][j] == '*'){
				s+=5;
			}

			else if(a[i][j] == '.'){
				s-=2;
			}
			else
				break;

			if(j != n-1)
				s--;
		}
	}

	if(success){
			cout << "Yes"<< endl;;
			cout << s; 
		}

	else
		cout << "No";




}


int main()
{
	int k,s,m,n;
	char park[100][100];
	// m,n = size of the grid 
	// s = current strength 
	// k = minimumn strength 

	cin >> m >> n >> k >> s;

	for (int i = 0; i < m; ++i)
	{
		for(int j = 0; j<n; j++)
			cin >> park[i][j];
	}
	
	Piyush_and_Magical_Park(park , m,n,k,s);

	return 0;


}