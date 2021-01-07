#include<iostream>
using namespace std;

class Queue {
	int *arr; 
	int f , r , ms , cs;

public:

	Queue(int ds = 5)
	{
		arr= new int[ds];
		ms = ds ;
		cs = 0; 
		f = 0; 
		r= ms-1;  
	}

	bool empty()
	{
		return cs==0; 
	}

	bool full()
	{
		return cs == ms; 
	}

	void pop()
	{
		if(!empty())
		{
			f = (f+1)%ms; 
			cs--; 
		}
	}

	void push(int data)
	{
		if(!full())
		{
			r = (r+1)%ms; 
			arr[r] = data; 
			cs++; 
		}
	}

	int front()
	{
		return arr[f]; 
	}


}; 



int main()
{
	Queue q; 

	q.push(1); 
	q.push(2); 
	q.push(3); 
	q.push(4); 
	q.push(5);
	q.push(6); 

	q.pop(); 
	q.pop(); 

	q.push(7); 

	while(!q.empty())
	{
		cout << q.front() << " "; 
		q.pop(); 
	} 

	return 0; 



}