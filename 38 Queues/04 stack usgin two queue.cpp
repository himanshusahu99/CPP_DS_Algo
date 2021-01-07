#include<iostream>
#include<queue>
using namespace std;

template<typename T>

class stack
{
	queue<T> q1, q2; 
public:
	 
	 void push(T data)
	 {
	 	q1.push(data); 
	 }

	 void pop()
	 {
		
		//pop() = remove the last added from the q1 


	 	//check if queue q1 is not empty
		
		if(q1.empty())
		{
			return; 
		}	 		

		// Steps
	 	// copy n-1 element in the q2
	 	while(q1.size() > 1)
	 	{
	 		T element = q1.front(); 
	 		q2.push(element);
	 		q1.pop(); 
	 	}

	 	// now only 1 elements left in the queue(that is last added element )
	 	//remove the last element 
	 	q1.pop();

	 	//swap the names of q1, q2
	 	swap(q1, q2); 

	 }

	 T top()
	 {
	 	// top() = return last added element 

	 	while(q1.size() > 1)
	 	{
	 		T element = q1.front(); 
	 		q2.push(element); 
	 		q1.pop(); 
	 	}

	 	// 1 element in the queue
	 	T element = q1.front(); 
	 	q1.pop();
	 	q2.push(element); 

	 	swap(q1, q2); 

	 	return element; 
	 }

	 bool size()
	 {
	 	return q1.size() + q2.size(); 
	 }

	 bool empty()
	 {
	 	return size()==0; 
	 }

};


int main()
{
	stack<int> s; 
	s.push(1); 
	s.push(2); 
	s.push(3); 
	s.push(4);
	s.push(5);

	s.pop();
	s.pop(); 
	s.push(6); 

	while(!s.empty())
	{
		cout << s.top() << " ";  
		s.pop(); 
	} 

}