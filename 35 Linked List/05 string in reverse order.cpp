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


void revereOrder(node*&head)
{
 	node*curr = head;
 	node* pre = NULL ; 
 	node* ne;  

 	while(curr != NULL)
 	{
 		// assigning next to temp next variable 
 		ne = curr -> next; 
 		//assging curren to point the pre ; 
 		curr->next = pre; 

 		// increament curre and ne to one step;
 		pre = curr ; 
 		curr  = ne; 
 	}
 	head = pre; ; 
}

int main()
{

	node* head ;
	cin >> head; 
	cout << head << endl; 

	revereOrder(head);

	cout << head ; 


}