#include<iostream>
using namespace std;
 
// insertion at head (Not at the tail )
//------------------- 
//In deletion, use pass by reference 

class node{
	public:
			int data; 
			node*next ; // pointer to the next node 

			node(int d)     {
				data=d; 
				next=NULL;
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

int length(node*head)
{
	int cnt =0 ; 
	while(head != NULL)
	{
		head = head->next;
		cnt++; 
	}

	return cnt++; 
}

void insertAttail(node*head ,int d )
{
	if(head == NULL)
		{
			insertAthead(head , d );
			return ; 
		} 

	node *tail = head; //creating tail pointer to point last element 

	while(tail->next != NULL)
	{
		tail = tail->next; 
	}


	node *temp = new node(d); 
	tail->next = temp ; 
	return;



}
void insertAtmiddle(node*&head , int d , int pos)
{
	if(head == NULL)
		{
			insertAthead(head, d);
			return; 
			 }
	if(pos>length(head))
	{
		insertAttail(head, d); 
		return; 
	}

	else{
		//taking p-1 jump for p 
		int jump = 1; 

		node* temp = head ; // creating copy of head for traversal 
		while(jump<=pos-1)
		{
			temp = temp->next; 
			jump++; 
		}

		node *n = new node(d);
		n->next = temp->next; 

		temp->next = n ;
		return ;   

	}

}

void deleteHead(node*&head)//pointing to the reference 
{
	if(head == NULL)
		return;

	node*temp = head->next;
	delete head; 
	head = temp; 
}

void deleteAtmiddle(node*&head, int key) // passing by reference  
{
	if(head->data == key)
	{
		deleteHead(head);
		return; 
	}
	node*prev;
	node *n;     
		while(n->data != key)
	{
		prev = head; //storing the prev node address 
		n = n->next; //storing the key node address

	}

	prev->next = n->next;
	delete n;  

}

void deleteAttail(node*&head) // passing by reference 
{
	node*p = head;
	while((p->next)->next != NULL) // p->next->next = p is currently at prev node of last node 
	{
		p = p->next;
	}

	node *temp = p->next; // head->node = last node 
	temp->next = NULL; 
	delete temp; 



}

bool search(node*head, int key)
{

	while(head != NULL)
	{
		if(head->data == key)
			return true; 

		head = head->next; 
	}

	return false; 
}
void print(node*head) // passing a pointer by valude// changes will not affect the original head pointer 
{
	while(head != NULL )
	{
		cout << head->data << " "; 
		head = head->next; 

	}
}


int main()
{
	node*head = NULL; 
	insertAthead(head, 1);
	insertAthead(head, 2);
	insertAthead(head, 3);
	insertAthead(head, 4);
	insertAtmiddle(head, 10,2 );
	insertAttail(head, 40); 


	print(head);

	cout << endl ; 

	deleteHead(head);
	deleteAtmiddle(head, 3); 
	deleteAttail(head);

	insertAttail(head, 100); 

	print(head); 

	cout << endl ; 

	if(search(head, 100))
	{
		cout << "Element is found " << endl; 
	}
	else
		cout << "Not found " << endl ; 

}