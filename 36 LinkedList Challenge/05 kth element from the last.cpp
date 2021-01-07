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



node* take_input() // return type is pointer to node 
{
	node*head = NULL ; 
	int d; 
	cin >> d; 
	while(d != -1 ) 
	{
		insertAtTail(head, d); 
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

node* k_th_node_from_end(node*head, int pos)
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
	 while( fastX != NULL )
	 {
	 	fastX = fastX->next;  
	 	slowX = slowX->next; 
	 }

	 return slowX; 

	
}


int main()
{

	//cout << "Enter nodes data and -1 to exit " << endl; 
	node* head ;
	cin >> head; 
	//cout << head << endl; 

	//cout << " Enter the pos from the last " << endl; 
	int kth;
	cin >> kth; 

	node* Kthnode = k_th_node_from_end(head, kth); 

	cout << Kthnode->data << endl;  
	return 0;  


}