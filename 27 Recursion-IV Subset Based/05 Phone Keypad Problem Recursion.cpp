#include<iostream>
using namespace std;

char keypad[][10] = {"", ".+@$", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS","TUV", "WXYZ"}; 

void genereate_names(char *in, char *out , int i, int j )// i for input and j for output
{

	//base case 
	if(in[i] == '\0')
	{
		out[j] = '\0';
		cout << out << endl;

		return; 
	}

	//rec case 
	int digit = in[i] - '0';
	
	if(digit == 0 )
	{
		genereate_names(in, out , i+1, j);
	}

	for(int k = 0; keypad[digit][k] != '\0'; k++)
	{
		out[j] = keypad[digit][k]; 
		//fill the ramaining parts 
		genereate_names(in, out, i+1, j+1);	
	}

}


int main()
{
	char in[100]; 
	cin >> in;

	char out[100];


	genereate_names(in, out, 0 , 0);

	return  0;  





}