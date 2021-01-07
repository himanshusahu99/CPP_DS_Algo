#include<iostream>
#include<deque>
#include<queue>
using namespace std;

int main()
{
	int n,time=0;
	cin>>n;

	queue<int> q;
	deque<int> dq;

	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		dq.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		cin>>x;
		q.push(x);
	}
	
while(!q.empty())
{
	if(q.front()==dq.front())
	{
		time++;
		q.pop();
		dq.pop_front();
	}
	else
	{
		dq.push_back(dq.front());
		dq.pop_front();
		time++;
	}
}
cout<<time;
return 0;
}