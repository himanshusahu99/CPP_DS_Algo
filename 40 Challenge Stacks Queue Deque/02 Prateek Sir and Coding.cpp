#include <iostream>
#include<stack>

using namespace std;

int main()
{

   stack<int> s;

  int n;
  cin>>n;
  int ch;
  int x;

  for(int i=0;i<n;i++)
  {
    cin>>ch;

    if(ch==2)
    {
      cin>>x;
      s.push(x);
    }

    else
    if(ch==1)
    {
      if(!s.empty())
      {
       cout<<s.top();
       cout<<endl;
       s.pop();
      }
      else
      cout<<"No Code"<<endl;
    }

  }

    return 0;
}