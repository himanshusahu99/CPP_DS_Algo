#include<iostream>
using namespace std;
class node
{
  public:
    int data;
    node*left;
    node* right;
    
    node(int d)
    {
      data = d;
      left = NULL;
      right= NULL;
    }
};
int sum = 0;
node* buildtree()
{
  int d,num;
  cin>>d;
  node* root = new node(d);
  cin>>num;
  if(num==2)
  {
    root->left = buildtree();
    root->right = buildtree();
  }
  else if(num==1)
    root->left = buildtree();
  return root;
}
void sumAtlevelK(node* root,int k)
{
  if(root==NULL)
    return;
  if(k==0)
    sum+=root->data;
  if(k<1)
    return;
  
  sumAtlevelK(root->left,k-1);
  sumAtlevelK(root->right,k-1);
}
int main() {
  node* root = buildtree();
  int k;cin>>k;
  sumAtlevelK(root,k);
  cout<<sum;
	return 0;
}