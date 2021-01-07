#include<iostream>
#include<cstring>
using namespace std;

void removechar(char a[]){

	int prev= 0;

	int l = strlen(a);
	if(l== 0 or l==1)
		return ;

	for(int cur = 1 ; cur < strlen(a); cur++){
			if(a[prev] != a[cur]){
				prev++;	
				a[prev] = a[cur];
				
			}
	}

	a[prev+1] = '\0';
	return ;
}


int main(){
	char a[100];

	cin.getline(a,100);

	removechar(a);
	cout << a << endl ;
}