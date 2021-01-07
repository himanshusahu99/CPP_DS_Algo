#include<iostream>
using namespace std;

int main()
{
	int n;
	
	cin >> n; 
	//maxsum(n);

	int t ,cs =0, ms=0;
	int a[n];	
		while(n--) {
		cin >> t;
		cs =0, ms=0;
		//cout << endl << "t=  " <<t ;
		for(int i =0 ; i<t; i++){
			cin >> a[i];
			cs = cs + a[i];
			if(cs<0)
				cs = 0;
			ms = max(cs , ms); 
			//cout << "inner while : " ;  
		}
		cout << ms << endl;
	}

return 0;

}