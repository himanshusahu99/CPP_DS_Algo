#include<iostream>
#include<climits>
using namespace std;

int findmax(int N){

	int a, result=INT_MIN;
	for(int i = 0; i<N; i++)
	{
		cin >> a;
		result = max(result, a);
	} 

	return result;

}

int main()
{

	 long long int N;

	 
	 
	 cin >> N;

	 int a[N];
	 


	int result = 0;

	cout << findmax(N);

	return 0;

}