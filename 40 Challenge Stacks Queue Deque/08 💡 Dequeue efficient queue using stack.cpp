#include<iostream>
#include<stack>
using namespace std;
class queue{
	stack<int>s1,s2;
	public:
	void enqueue(int data){
		
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
        s2.push(data);
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
	}
	int dequeue(){
		int d=s1.top();
		if(s1.empty()){
			exit(0);
		}
		s1.pop();
		return d;
	}
};
int main() {
	queue q;
	int n;
    cin>>n;
	for(int i=0;i<n;i++){
		q.enqueue(i);
	}
	for(int i=0;i<n;i++){
		cout<<q.dequeue()<<" ";
	}
	return 0;
}