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


/* 	this function runs on O(N^2) time :- one N for rec case and one N for while loop(gooing from last node to fisrt node ) 

 node* rec_revereOrder_1(node*head)
{
 	//base case 
 	if(head == NULL or head->next == NULL )
 	{
 		return head; 
 	}

 	//rec case 

 	node* small_head = rec_revereOrder_1(head->next); 

 	node* temp = head; 
 	while(temp->next != NULL)
 	{
 		temp= temp->next; 
 	}

 	temp->next = head;
 	head->next = NULL; 

 	return small_head; 

}*/

node* rec_revereOrder_2(node*head) // this recursive case takes O(N) time; 
{
 	//base case 
 	if(head == NULL or head->next == NULL )
 	{
 		return head; 
 	}

 	//rec case 

 	node* small_head = rec_revereOrder_1(head->next); 

 	node* temp = head; 
 	
 	temp = head->next; 
 	temp->next = head; // you can replace temp with head->next and delete the previous line ; 
 	head->next = NULL;





 	return small_head; 

}

int main()
{

	node* head ;
	cin >> head; 
	cout << head << endl; 

	head = rec_revereOrder_2(head);

	cout << head ; 


}