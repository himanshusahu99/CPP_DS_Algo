#include<iostream>
using namespace std;

void replacePi(char *a, int i )
{

 	//base case; 
 	if(a[i] == '\0' or a[i+1] == '\0')
 	{
 		return; 
 	}

 	if(a[i] == 'p' and a[i+1] == 'i')
 	{
 		int j = i+2 ; // a[i] = p , a[i+1] = i ; so  j = i+2; 

 		while(a[j] != '\0')
 			j++ ; // finding the total char to shift; 

 		// sifting the array 
 		while(j >= i+2)
 		{
 			a[j+2] = a[j]; 
 			j--; 
 		}

 		//replacing the pi with 3.14
 		a[i]= '3';
 		a[i+1] = '.';
 		a[i+2] = '1';
 		a[i+3] = '4';

 		//calling finction after replacing 4 chars 
 		replacePi(a, i+4); 

 	}

 	else
 		replacePi(a, i+1); 


 	return ; 

}	


int main()
{
	char a[100];
	cin >> a; 

	replacePi(a, 0); 

	cout << a ; 

	return 0; 

}