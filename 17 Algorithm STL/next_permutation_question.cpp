#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--){
		int k;
		cin >> k;
		int a[k];
		
			for (int i = 0; i < k; ++i)
			{
				cin >> a[i];
			}


				int n = sizeof(a)/sizeof(a[0]);
				
				
			
				//next_permutation gives just bigger number after arranging the array element 
			
				next_permutation(a, a+n);
			
				for(auto x:a)
					cout << x <<" ";

				cout << endl;
		
	}

	/*cout << endl;
	next_permutation(v.begin(), v.end());

	for(auto x:v)
		cout << x <<" ";
*/

}