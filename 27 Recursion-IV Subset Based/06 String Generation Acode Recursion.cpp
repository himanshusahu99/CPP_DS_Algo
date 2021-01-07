#include<iostream>
using namespace std;

/*

A = 1 
B = 2 
C = 3 
D = 4 	
.
.
.
.
Z = 26
*/
void generate_strings(char *in, char *out, int i, int j)
{
	//base case
	if(in[i] == '\0')
	{
		out[j] = '\0';
		cout << out << endl ; 
		return;
	}

	//rec case 
	
	//one digit at a time 
	int digit = in[i] - '0'; 
	//changing digit into character 

	char ch = digit + ' A' - 1; 
	//cout << ch << endl; 
	out[j] = ch; 
	generate_strings(in , out , i+1, j+1);


	//two digits a time
	if(in[i+1] != '\0')
	{
		int secondDigit = in[i+1] - '0' ;
		int no  = digit*10 + secondDigit; // converting into two digit number 
	
		if(secondDigit <= 26)
		{
			ch = no + 'A' - 1;
			//cout << ch << endl; 
			out[j] = ch ; 
			generate_strings(in, out, i+2, j+1);  
	
		} 
	}

	return ; 



}


int main()
{
	char in[100];
	cin >> in ;

	char out[100];

	generate_strings(in, out, 0, 0);

	return 0; 

}