#include<iostream>
using namespace std;

void generate_subset(char *in, char *out, int i,int j )
{

	//base case 
	if(in[i] == '\0')
	{
		out[j] = '\0';
		cout << out << endl;
		return; 
	}

	//recursive case 
	//including current char 
		out[j] = in[i]; 
	generate_subset(in, out, i+1, j+1);

	//excluding current char
	generate_subset(in, out, i+1, j); 

}


int main()
{

	char input[] = "abc";
	char output[10];

	generate_subset(input, output, 0, 0 ); 

	return  0 ;



}