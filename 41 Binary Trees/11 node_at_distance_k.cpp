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

void printatleveLK(node *root, int k)
{
    if(root == NULL)
        return; 

    if(k==0)
    {
        cout << root->data << " "; 
        return; 
    }

    printatleveLK(root->left, k-1); 
    printatleveLK(root->right, k-1);

    return;
}

int ataDistanceK(node*root, node* target, int k)
{
    //base case 
    if(root == NULL)
        return -1; 

    //reach the target node
    if(root == target)
    {
        printatleveLK(target, k); 
        return 0; 
    }

    // next-step 

    // ancestors
    int DL = ataDistanceK(root->left, target, k);  
    if(DL != -1)
    {
        //again there are two cases
        //ancestors itself or goto right acncestors
        if (DL+1 == k)
        {
            cout << root->data << " "; 
        }

        else
        {
            printatleveLK(root->right, k-2-DL); 
        }

        return DL+1; 

    }

    int DR = ataDistanceK(root->right, target, k ); 
    if(DR !=-1)
    {
        if(DR+1 == k)
            cout << root->data << " "; 

        else
            printatleveLK(root->left, k-2-DR); 

        return DR+1; 
    }

    //node was not present in the left or right subtree
    return -1; 
}



int main(){ 
    
    node* root = buildnode(); 

    bfs(root); 
    node*target = root->left->left; 

    int k ; 
    cin >>k; 

//printatleveLK(target, k); 
    ataDistanceK(root, target , 2); 

    return 0; 

    


return 0;
}