#include<iostream>
using namespace std;

char keypad[][10] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz"}; 

void genereate_names(char *in, char *out , int i, int j )// i for input and j for output
{
	//base case 
	if(in[i] == '\0')
	{
		out[j] = '\0'; 
		cout << out << endl ; 
		return; 
	}

	int digit = in[i] - '0'; 



	//rec case 
	for(int k = 0; keypad[digit][k] != '\0'; k++)
	{
		out[j] = keypad[digit][k]; 
		genereate_names(in , out, i+1, j+1); 
	}





}


int main()
{
	char in[100]; 
	cin >> in;

	char out[100] = {0};


	genereate_names(in, out, 0 , 0);

	return  0;  





}