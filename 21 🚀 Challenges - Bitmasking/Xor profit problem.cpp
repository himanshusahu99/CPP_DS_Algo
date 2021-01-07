#include<iostream>
using namespace std;

int main()
{
	int x , y; 

	cin >> x >> y ; 

	 /* 
		
		// inefficient way (generrating all the pairs ) 

	 int ans = 0; 
	for(int i = x; i <= y; i++)
	{
		for(int j = i+1; j <= y; j++)
		{
			int xor_profit = (i ^ j);
			//cout << i << " ^ " << j << " = " << xor_profit << endl;
			ans = max(ans , xor_profit);
		}
	} */

	// efficient way is to obsseve the pattern 

	// finding the MSB of x ^ y 
	// then 1 << msb; 

	int num = x ^ y; 
	int msb = 0; 
	while(num > 0)
	{
		num = num >> 1;
		msb++; // finding the MSB 
	}

	//cout << msb << endl; 
	int result = 1 << msb; 




	cout << (result) -1 ;

	return 0; 

}