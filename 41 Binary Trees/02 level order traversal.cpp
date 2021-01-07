#include<iostream>
using namespace std;

/*
	
	input  = 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 

	output = 
			   8 
	10   					3	 
 1 			6 		 				14 
  		9 		7 				13 



*/ 

class node{
public:
	int data ;
	node* left; 
	node* right; 

	node(int d )
	{
		data = d ;
		left = NULL; 
		right = NULL; 
	}
};

node* buildnode()
{
	int d ; 
	cin >> d; 


	if(d== -1 )
		return NULL; 

	node* root = new node(d); 
	root->left = buildnode(); 
	root->right  = buildnode ();

	return root;  
}


void print(node* root)
{
	if(root == NULL)
		return; 

	cout << root->data; 
	print(root->left); 
	print(root->right);  
}

int height(node*root)
{
	if(root == NULL)
		return 0; 

	int ls = height(root->left); 
	int rs = height(root->right); 

	return max(ls, rs) + 1; 
}

void printKthlevel(node*root, int k )
{
	if(root == NULL)
		return; 

	if(k==1)
		{
			cout << root->data << " ";
			return; 

		}
	printKthlevel(root->left, k-1); 
	printKthlevel(root->right, k-1); 
	
	return; 


}


void printAll_level(node*root)
{
	if(root == NULL)
		return; 

	int H = height(root); 

	for(int i = 1; i<=H; i++)
	{
		printKthlevel(root, i); 
		cout << endl; 
	}

	return; 



}

int main()
{
	node* root = buildnode(); 
	// print(root);
	// cout << endl; 

	printAll_level(root); 
}