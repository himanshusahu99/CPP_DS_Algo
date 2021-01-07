#include<iostream>
using namespace std;

void readlines(char a[], int n , char delim){

	int i=0;
	char s;
	s= cin.get();
	while(s != delim){
		a[i] = s;
		i++;

		if(i == (n-1))
			break;

		s = cin.get();
	}

	a[i] = '\0';

	return;

}




int main()
{

	int n;
	cout << "Enter your size " << endl;

	cin >> n;

	char a[10];
	cout << "Enter terminator character ";

	char delim;
	cin >> delim ; 
	cin.get();

	readlines(a,n,delim);
	cout << a ;

	return 0;


}