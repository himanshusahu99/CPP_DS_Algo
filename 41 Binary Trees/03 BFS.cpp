#include<iostream>
#include<queue>
using namespace std;
class node{
public:
	int data; 
	node* left; 
	node* right; 

	node(int d )
	{
		data = d;
		left  =NULL; 
		right = NULL; 
	}
};

node* buildnode()
{
	int d;

	cin >> d; 


	if(d == -1)
		return NULL;

	node* root = new node(d); 

	root->left = buildnode(); 
	root->right = buildnode(); 

	return root; 

}

void print(node* root)
{
	if(root == NULL)
		return; 


	cout << root->data << " "; 
	print(root->left); 
	print(root->right); 
	

}

void BFS(node* root)
{

 queue<node*> q; 
 q.push(root); 

 while(!q.empty())
 {
 	node* f = q.front(); 
 	cout << f->data << " "; 
 	q.pop(); 

 	if(f->left)
 		q.push(f->left); 

 	if(f->right)
 		q.push(	f->right); 
 	
 }

 return; 


}


int main()
{
	node* root = buildnode(); 
	//print(root); 

	BFS(root); 
	return 0; 

}