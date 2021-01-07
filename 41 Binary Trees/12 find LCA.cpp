#include<iostream>
#include<queue>
using namespace std;

/* 
1
2
4
6
-1 -1
7 -1 -1
5
8
-1 -1
9
-1 -1
3 
-1 
-1

output = 1 3 5 9    

*/ 
/*
1 2
4
6
-1 -1
7
10
-1 -1
11 -1 -1
5
8
-1 -1
9
-1 -1
3
-1 -1

*/

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


void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

//assumtion is that both nodes are present in the array
node* findLCA(node*root, int a, int b )
{
    if(root == NULL)
        return NULL; 

    if(root->data == a or root->data == b)
        return root;

    //rec case

    node* leftans = findLCA(root->left ,a ,b); 
    node* rightans = findLCA(root->right,a , b); 

    //corner case 

    if( leftans != NULL and rightans != NULL ) 
        return root; 

    if(leftans != NULL)
        return leftans; 
    else
        return rightans; 


}


int main(){ 
    
    node* root = buildnode(); 

    bfs(root); 

    cout << endl; 
    //scond comment input 
    cout << findLCA(root, 10, 4)->data << endl; 


    return 0; 

    


return 0;
}