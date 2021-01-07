#include <bits/stdc++.h>
using namespace std;
#define ll long long
char out[10000000];
int k=0;
void delete_cons_dub(string s,int i){
    // Base Case

    if(s[i]=='\0') {
        out[k]='\0';   
        return ;
    }
    // Rec Case

    int j=i;
    out[k++]=s[i];

    while(s[j]==s[i]){
        j++;
    }

    delete_cons_dub(s,j);

}


int main() {
    string s;
    cin>>s;

    delete_cons_dub(s,0);
    cout<<out<<endl;
}
