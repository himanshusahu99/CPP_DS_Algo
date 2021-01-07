#include <iostream>
using namespace std;

class node{
public:

	int data;
	node*left;
	node*right;

	node(int v){
		data = v;
		left = NULL;
		right = NULL;
	}
};

node* repeatRootBuild(node*root,int v){
	if(root==NULL){
		return new node(v);
	}

	if(v<=root->data){
		root->left = repeatRootBuild(root->left,v);
	}

	if(v>root->data){
		root->right = repeatRootBuild(root->right,v);
	}

	return root;

}

void prePrint(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	prePrint(root->left);
	prePrint(root->right);
	return;
}

void inprint(node*root,int k1,int k2){
	if(root==NULL){
		return;
	}

	inprint(root->left,k1,k2);
	if(root->data>=k1 && root->data<=k2){
		cout<<root->data<<" ";
	}
	inprint(root->right,k1,k2);
}

node* BuildBst(int n){
	int v;
	node*root = NULL;
	for(int i=0;i<n;i++){
		cin>>v;
		root = repeatRootBuild(root,v);
	}
	return root;
}

node* deleteInBST(node*root,int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left = deleteInBST(root->left,data);
        return root; 
    }
    else if(data==root->data){
        //Found the node to delete 3 Cases
        //1. Node with 0 children - Leaf Node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //2. Case Only 1 child
            if(root->left!=NULL && root->right==NULL){
                node* temp = root->left;
                delete root;
                return temp;
            }
            if(root->right!=NULL && root->left==NULL){
                node* temp = root->right;
                delete root;
                return temp;
            }
        //3. Case 2 children
            node *replace = root->right;
            //Find the inorder successor from right subtree
            while(replace->left!=NULL){
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = deleteInBST(root->right,replace->data);
            return root;
    }
    else{
        root->right = deleteInBST(root->right,data);
        return root;
    }

}

int main(){

	int t;
	cin>>t;
	for(int g=0;g<t;g++)
    {
        int n,m;
		cin>>n;
		node*root = BuildBst(n);
		cin>>m;
		int*a = new int[m];
		for(int i=0;i<m;i++){
			cin>>a[i];
			root = deleteInBST(root,a[i]);
		}
		prePrint(root); 
        cout<<endl;  //change
	}
	return 0;
}