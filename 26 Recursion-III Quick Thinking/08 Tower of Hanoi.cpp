#include<iostream>
using namespace std;

void move(int n , char src, char helper, char dest)
{
	if(n==0)
		return; 

	move(n-1, src, dest, helper);
	cout << " move " << n << " from " << src << " to " << dest << endl; // shifting one disk need not recursion onply print statments 
	move(n-1, helper, src, dest); 
}


int main()
{
	// enter number of disks 
	int n ;
	cin >> n ; 

	 move(n, 'A', 'B', 'C'); 
	return 0; 


}