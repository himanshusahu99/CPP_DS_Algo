#include <iostream>
#include <deque>
#define ll long long int
using namespace std;
int main() {
  
  ll n,k,a[100000]={};
  cin>>n;
  for(int i=0;i<n;i++){
  cin>>a[i];
  }
  cin>>k;
  deque<ll>q(k);
  ll i=0;
  for( ;i<k;i++){
  while(!q.empty() && a[i]>q.back()){
  q.pop_back();
  }
  q.push_back(i);
  }
  //cout<<a[q.front()]<<" ";
  //
    for(;i<n;i++){
        //removal
        cout<<a[q.front()]<<" ";
        while(!q.empty() && q.front()<=i-k){
        q.pop_front();
        }
        //adding
        while(!q.empty() && a[i]>=a[q.back()]){
        q.pop_back();
        }
        q.push_back(i);
            //cout<<a[q.front()]<<" ";
    }
   cout<<a[q.front()]<<" ";
    return 0;
}
