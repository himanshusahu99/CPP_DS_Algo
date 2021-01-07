#include<iostream>
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

int count(node* root)
{
    if(root == NULL)
    {
        return 0; 
    }

    return 1 + count(root->left) + count(root->right);
}

int height(node*root)
{
    if(root == NULL)
        return 0; 

    int ls = height(root->left); 
    int rs = height(root->right); 

    return max(ls, rs) + 1; 
}

class Pair{
    public:
        int height;
        int diameter;
};

Pair fastDiameter(node*root){
    Pair p;
    if(root==NULL){
        p.diameter = p.height = 0;
        return p;
    }
    //Otherwise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height,right.height) + 1;
    p.diameter = max(left.height+right.height, max(left.diameter,right.diameter));
    return p;
}



int main()
{
    node* root = buildnode(); 

    Pair p = fastDiameter(root);
    cout<<p.height<<endl;
    cout<<p.diameter<<endl;

    return 0; 
}