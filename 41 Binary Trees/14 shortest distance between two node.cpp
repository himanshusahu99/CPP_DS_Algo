#include<iostream>
#include<queue>
using namespace std;

/*
input 

10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1 
1 4 

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


int search(node*root, int key , int level)
{
    if(root==NULL)
        return -1;

    if(root->data == key)
        return level; 

    int left = search(root->left, key, level+1); 
    
    if(left != -1)
        return left; 

    return search(root->right, key, level+1);
}

int finddistacne(node* root, int a, int b)
{
    node* lca_node = findLCA(root, a, b); 

    int l1 = search(root, a, 0);
    int l2 = search(root, b, 0); 

    return l1+l2; 



}



int main(){ 
    
    node* root = buildnode(); 

    //bfs(root); 

    //cout << endl; 
    
    int a , b; 
    cin >> a >> b; 

    cout << finddistacne(root, a , b);  
     



    return 0; 

    


return 0;
}