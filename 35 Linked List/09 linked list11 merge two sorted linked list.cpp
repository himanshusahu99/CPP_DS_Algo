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

node* merger_two_linkedlist(node*a , node*b)
{
	if(a == NULL)
		return b; 
	if(b == NULL)
		return a ;

	node* temp;

	if(a->data  < b->data)
	{
		temp = a; 
		temp->next = merger_two_linkedlist(a->next, b);
	} 

	else
	{
		temp = b; 
		temp->next = merger_two_linkedlist(a, b->next); 
	}

	return temp ; 



}


int main()
{

  	cout << "input in reverse order to get desired result " << endl << endl; 
	cout << "Enter nodes data and -1 to exit" << endl; 
	node* head ;
	node* head2 ;
	cin >> head; 

	cout << "Enter second nodes data and -1 to exit " << endl; 
	cin >> head2; 

	node* sorted_node = merger_two_linkedlist(head, head2); 

	cout << sorted_node << endl;  
	return 0;  


}