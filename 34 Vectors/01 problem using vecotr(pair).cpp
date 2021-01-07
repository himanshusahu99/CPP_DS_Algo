#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//compute minimum distance from the given coordinate

bool comparator(pair<int ,int >p, pair<int , int> q)
{
	int d1 = p.first*p.first + p.second*p.second; 
	int d2 = q.first*q.first + q.second*q.second;

	//if min distance is same then sort acc to first coordinate 
	if(d1 == d2 )
		return p.first < q.first;

	
	return d1 < d2; 
}

int main()
{
	int n; 
	cin >> n;

	vector<pair<int,int>> v ;
	for(int i = 0; i<n; i++)
	{
		int x ,y ;
		cin >> x >> y; 

		v.push_back(make_pair(x,y)); 
	}


	sort(v.begin(), v.end(), comparator);   

	for(auto p : v)
		 cout << p.first << " " << p.second << endl ;


		return 0; 




}