#include<iostream>
using namespace std;

int cnt  = 0 ;
void generate_subset(char *in, char *out, int i,int j )
{

	//base case 
	if(in[i] == '\0')
	{
		out[j] = '\0';
		cout << out << " ";
		
		cnt++; 
		return; 
	}

	//recursive case 
	//excluding current char
	generate_subset(in, out, i+1, j); 
	//including current char 
		out[j] = in[i]; 
	generate_subset(in, out, i+1, j+1);


}


int main()
{

	char input[1001];
	cin >> input; 
	char output[10];

	generate_subset(input, output, 0, 0 ); 

	cout << endl << cnt; 

	return  0 ;



}