#include<iostream>
#include<queue>
#include<stack>
using namespace std;
 int cur_level= 0,level=1;
class  node{
public:
	int data;
	node* right;
    node* left;
	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};
node* buildtree(){
	int d;
	cin>>d;
	node*root=new node(d);
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
	node*f=q.front();
	q.pop();
	int c1,c2;
	cin>>c1>>c2;
	if(c1!=-1){
	f->left=new node(c1);
	q.push(f->left);
	}
	if(c2!=-1){
	f->right=new node(c2);
	q.push(f->right);
	}
	}
	return root;
}

void print(node *root){
	if(root==NULL)
		return;

	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}

node* build(){
    int d;
    cin>>d;
    if(d==-1)
    return NULL;
    
    node *root= new node(d);

    root->left=build();
    root->right=build();

    return root;
}


void rightview(node* root, int cur_level, int *level){

	if(root==NULL)
		return;
	if(*level<cur_level){
		cout<<root->data<<" ";
		*level=cur_level;
		
        
		
	}
    rightview(root->right, cur_level+1, level);
    rightview(root->left,cur_level+1,level);
}
int main(int argc, char const *argv[])
{
	node *root= buildtree();
    // build function for -1 type
    //node *root= build();
	//print(root);
    //cout<<endl;
    //zigzac(root);
    //cout<<endl;
   // bottomView(root);
   int level =0;
    rightview(root, 1, &level );

	return 0;
}