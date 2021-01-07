#include<iostream>
#include<queue>
using namespace std;

/*
input 

10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1 

output 

10,
2,10,
20,1,-25,
3,4,

42 // required answer;


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

class Pair
{
public:
    int branchsum; 
    int maxsum;

    Pair()
    {
        branchsum = 0; 
        maxsum  = 0; 
    }

}; 

Pair maxSumPath(node* root)
{
    Pair p; 

    if(root == NULL)
        return p; 

    Pair left = maxSumPath(root->left); 
    Pair right = maxSumPath(root->right); 

    int op1 = root->data; 
    int op2 = left.branchsum + root->data; 
    int op3 = right.branchsum + root->data; 
    int op4 = left.branchsum + right.branchsum  + root->data; 

    int currentSum = max(op1 , max(op2 , max(op3, op4))); 

    p.branchsum = max(left.branchsum, max(right.branchsum, 0)) + root->data ;
    p.maxsum = max(left.maxsum, max(right.maxsum, currentSum)); 

    return p; 




} 


int main(){ 
    
    node* root = buildnode(); 

    bfs(root); 

    cout << endl; 
     
    cout << maxSumPath(root).maxsum << endl;  



    return 0; 

    


return 0;
}