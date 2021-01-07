#include<iostream> 
#include<stack> 
using namespace std; 

#define ll long long int
ll getMaxArea(ll hist[], ll n) 
{ 
	stack<ll> s; 

	ll max_area = 0; 
	ll tp; 
	ll area_with_top; 
	ll i = 0; 
	while (i < n) 
	{ 
		if (s.empty() || hist[s.top()] <= hist[i]) 
			s.push(i++); 
		else
		{ 
			while (!s.empty() && hist[s.top()] > hist[i]) { 
	     	tp = s.top(); 
	    	s.pop(); 
	    	area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
	    	if (max_area < area_with_top) 
			max_area = area_with_top; 
	       } 
           s.push(i++);
		} 
	} 

    while (!s.empty()) { 
	    tp = s.top(); 
	    s.pop(); 
	    area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1); 
		if (max_area < area_with_top) 
		max_area = area_with_top; 
	} 

	return max_area; 
}  
int main() 
{ 
    ll n,i;
    cin>>n;
	ll hist[n];
    for(i=0;i<n;i++){
        cin>>hist[i];
    }
	cout << getMaxArea(hist, n); 
	return 0; 
} 
