#include<iostream>
using namespace std;

bool IsPossible(int n , int m , int x, int y, int mid)
{
	//cout << endl << " inside bool " << mid*x << " " <<  m + y ; 
	if((mid * x) <= m + ((n - mid) * y) )
		return true;
	else
		return false;
}

int main()
{

	int n,m,x,y;
	cin>> n >> m >> x >> y;

	int s = 0;
	int e = n;
	int ans = 0;

	while(s<=e)
	{
		int mid = (s+e)/2;
		//cout << "s and e " << s << " " << e  << " ";
		//cout << " in main while mid =  " << mid <<  endl;

		if(IsPossible( n,  m , x , y, mid) == true)
		{	
			ans = mid;
			//cout  << " inside if ans =  " << ans << endl; 
			s = mid+1;
		}
		else
			e = mid - 1;
	}

	cout << "ans  " << ans ;

	return 0; 




	return 0;
}