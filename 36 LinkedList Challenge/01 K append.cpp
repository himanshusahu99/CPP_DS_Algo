#include<iostream>
using namespace std; 

class node
{
public:

	int data;
	node* next; 

	node(int data)
	{
		this->data = data;
		next = NULL; 
	}


}; 




void insertAtTail(node*&head, int data )
{
	if(head == NULL)
	{
		head = new node(data);
		return ;
	}

	node* temp = head; 
	node* d = new node(data); 

	while(temp ->next != NULL)
	{
		temp = temp->next; 
	}

	temp->next = d; 

}

void print(node*head)
{
	while(head != NULL)
	{
		cout << head->data << " "; 
		head = head->next; 
	}
}

void take_input(node*&head) // return type is pointer to node 
{
	
	int d; 
	cin >> d; 	
	insertAtTail(head, d); 


	 

}

ostream& operator<<(ostream &os, node*head)
{
	print(head);
	return os ;
	
}	

istream& operator>>(istream &is, node*&head)
{
	take_input(head);
	return is; 
}

node* kthpoint(node*head, int pos)
{
	node* fastX = head; 
	 node*slowX = head; 

	 int cnt =1 ; // take fast2x two steps until cnt reaches to the pos;  
	 while(cnt <= pos)
	 {
	 	fastX = fastX->next;
	 	  
	 	cnt++;  
	 }

	 //cout << cnt; 

	 // then takes single takes and slowX is the ans ; 
	 while( fastX->next != NULL )
	 {
	 	fastX = fastX->next;  
	 	slowX = slowX->next; 
	 }

	 return slowX; 

}

void insertAthead(node*&head, int data )
{
	if(head == NULL )
	{
		head = new node(data); 

	}

	node* temp = new node(data); 
	temp->next = head;
	head = temp; 
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
	int n; 
	cin >> n; 

	node* head = NULL ; 

	for(int i =0; i<n; i++)
	{
		cin >> head; 
	}

	//cout << head; 

	int k ;  

	cin >> k ;  

	/*
	1. If k == n, then simply just reverse  and return; 
	2. if k>n, then k = k%n; 
	*/ 

	// if k==n 
	if(n==k)
	{
		revereOrder(head);
		cout << head; 
		return 0;  
	}

	// if k>n 
	else if(k>n)
	{
		k = k%n; 
	}

	// taking the pre of last k node 
	node* pre_of_k_th_node = kthpoint(head, k); 


	//pointing the last kth node(from where we need to take that ar front) 
	node*temp  = pre_of_k_th_node->next; 

	// seperating temp from the original LL
	pre_of_k_th_node->next = NULL; 

	// creating copy of temp; 
	node* copy = temp; 

	// run loop till pointer points last node of temp LL 
	while(copy->next != NULL)
	{
		copy= copy ->next; 
	}

	// node last ndoe of temp ll will point head of original LL;  
	copy->next = head; 

	// changing head to the temp 
	head = temp; 
	

	cout << head; 

	return 0; 
}
