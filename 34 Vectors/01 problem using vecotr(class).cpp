#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Car {

public:
	string name ; 
	int x ,y ;

	Car()
	{

	}

	Car(string name, int x ,int y )
	{
		this->name = name ;
		this->x = x;
		this->y =y ;
	}

	//return dist from the origin of a class 
	int dist()
	{
		return x*x+y*y; 
	}

};

bool comp(Car A, Car B)
{
	int d1 = A.dist(); 
	int d2 = B.dist(); 

	//if distance is same 
	if(d1==d2)
		return A.name.length() < B.name.length(); 

	return d1 < d2; 

}



int main()
{
	int n ;
	cin >> n;

	vector<Car> c; 

	for(int  i = 0; i<n; i++ )
	{
		string name;
		int x ,y ; 

		cin >> name >> x >> y; 
		Car temp(name , x , y ); 

		c.push_back(temp); 
	}


	//now sorting 
	sort(c.begin(),c.end(), comp);

	for(auto p:c)
	{
		cout << p.name << " " << p.x << " " << p.y << " distance = " << p.dist() << endl; 
	} 

}