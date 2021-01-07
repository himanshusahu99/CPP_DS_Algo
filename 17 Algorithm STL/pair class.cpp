#include<iostream>
using namespace std;

int main()
{
	pair<int,char> p;

	// first approach
	p.first = 10; 
	p.second = 'c';

	cout << p.first << " " << p.second  << endl;; 

	//another way 

	pair<int, char> p3(p);

	cout << p3.first << " " << p3.second << endl;

	// another way 
	pair<int, string> p4  = make_pair(100, "Sahu");

	cout << p4.first << " " << p4.second << endl;


	// we can also make array of pair , vecotr of pair , pair of pair 

	pair<pair<int,int>, string> car ;

	car.first.first = 11;
	car.first.second = 14;

	car.second = "Audi";

	cout << car.first.first << " " << car.first.second << " " << car.second << endl;

	return 0;    
}