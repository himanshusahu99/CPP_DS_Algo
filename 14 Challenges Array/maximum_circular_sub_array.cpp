#include<iostream>
using namespace std;

int kedans_algo(int a[], int t)
{
	int cs=0, ms = 0;
	
	for(int i =0 ; i<t; i++){
	
			cs = cs + a[i];
			if(cs<0)
				cs = 0;
			ms = max(cs , ms); 
			//cout << "inner while : " ;  
		}
		return ms;	

}

void maxsum(int a[], int t)
{
	int cum_sum = 0;

	for(int i = 0; i<t; i++)
		{
			cin >> a[i];
			cum_sum +=a[i];
		}

		//cout << "cum_sum " << cum_sum ; 

	int ked_sum = kedans_algo(a,t); 

	//cout << endl << "ked_sum " << ked_sum << endl;

	//inverting array
	for(int i = 0; i<t; i++)
		{
			a[i] = (-a[i]);
		}
	int in_ked_sum = cum_sum + kedans_algo(a,t);

	//cout << "in_ked_sum " << in_ked_sum << endl;

	cout << max(in_ked_sum, ked_sum) << endl; 
}

int main()
{


	int n;
	
	cin >> n; 
	//maxsum(n);

	int t;
	

	while(n--) {
		cin >> t;
		int a[t];
		maxsum(a,t);
	}


}