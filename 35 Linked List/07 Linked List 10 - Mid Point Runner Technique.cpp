#include<iostream>
using namespace std;
// for taking inputs there is two ways 
// 1. norml void function that is insertAtHead
// 2. creating new head pointer and return that to the main 

class node{
public:
	int data;
	node* next; 

	node(int d )
	{
		data =d; 
		next= NULL; 
	}

};

void insertAthead(node*&head, int d) // Passing a pointer by reference (& is used for that ) 
{ // will affect to the original head pointer 
	if(head == NULL)
	{
		head  = new node(d);

		return ; 
	}

	node *n = new node(d); 
	n->next = head; 
	head  = n; 


}


node* take_input() // return type is pointer to node 
{
	node*head = NULL ; 
	int d; 
	cin >> d; 
	while(d != -1 ) 
	{
		insertAthead(head, d); 
		cin >> d ; 
	}

	return head; 

}

void print(node*head)
{
	while(head != NULL)
	{
		cout << head->data << " -> "; 
		head = head->next; 
	}
}

ostream& operator<<(ostream &os , node*head)
{
	print(head);
	return os ;
}

istream& operator>>(istream &is, node*&head)
{
	head = take_input();
	return is; 
}

node* mid_point_runnner(node*head)
{
	if(head == NULL or head ->next == NULL )
		return head; 


	node* fast_2x; 
	node* slow_x; 

	fast_2x = head->next; // fast will be at second pointer to ger the floor of l/2; 
	slow_x = head; 

	while( fast_2x != NULL and  fast_2x->next != NULL  )
	{
		fast_2x = fast_2x->next->next; 
		slow_x = slow_x->next; 
	}

	return slow_x; 
}


int main()
{

	node* head ;
	cin >> head; 
	cout << head << endl; 

	node* mid_point = mid_point_runnner(head); 

	cout << mid_point->data; 
	return 0;  


}