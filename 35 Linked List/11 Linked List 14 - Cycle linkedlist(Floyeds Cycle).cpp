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





node* P; //pointe that says LL is cycled LL;
node* N; // N is the node from where cyled LL starts  


bool detect_cycle(node*head)
{
	node* fast_2x= head; 
	node* slow_x  = head;

	
	while(fast_2x != NULL or fast_2x->next != NULL)
	{
		fast_2x = fast_2x->next->next; 
		slow_x = slow_x->next; 

		if(fast_2x == slow_x)
		{
			P = fast_2x; 
			return true;   
		}
	} 

	return false;
}

void detect_cycle(node*&head) // pointer to reference 
{
	
	if(detect_cycle(head) )
	{
		cout << "Contains a Cycle " << endl << endl; 
		node* fast_X = P; 
		node* slow_x = head; 

		while(fast_X->next != slow_x)
		{
			fast_X = fast_X->next;
			slow_x = slow_x->next; 
		}

		fast_X->next = NULL; 

	}

	else
	{
		cout << "Not Contains a cycle; "; 
	}
		



}

int main()
{

	cout << "Enter nodes data and -1 to exit " << endl; 
	node* head ;
	
	cin >> head; 

	cout << head << endl; 

	node* sorted_node = merge_sort(head); 

	cout << sorted_node << endl;  
	return 0;  


}