#include<iostream>
#include<queue>
using namespace std;

// not solved
 
int main()
{
	queue<char> q; 
	int freq[27] = {0 }; 

	char ch; 
	cin >> ch; 

	while(ch != '.') 
	{
		// logic will go here 
		//insert into queue and freq table 
		q.push(ch); 
		freq[ch-'a']++; 

		//query 
		while(!q.empty())
		{
			int idx = q.front() - 'a'; 
			if(freq[idx] > 1)
			{
				q.pop(); 
			}

			else
			{
				cout << q.front() << endl; 
				break; 
			}
		}

		//q is empty 

		if(!q.empty())
		{
			cout << "-1 " << endl; 
		}

		cin >> ch; 



	}





}
