#include<iostream>
#include<algorithm>
using namespace std;

bool comparator(int a, int b){
	 // b = money

	//cout  << a << " " << b << endl;
	return a<=b;
}

int main()
{
	int coins[] = {1,2,5,50,100,200,500,2000};

	int money = 12000;

	int n = sizeof(coins)/sizeof(coins[0]);

	
	while(money >0)
	{
		auto lb = lower_bound(coins, coins + n , money,comparator ) - coins-1;
	 
	 
	 	cout << coins[lb] << ", " ;
	 
	 	money -= coins[lb];
	 } 
}