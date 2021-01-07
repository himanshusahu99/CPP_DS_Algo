Editorial
X
Approach
The Idea is to Store the Calling order in Queue and the ideal order in an Array.
Then compare front element of the queue with the ideal order.
If it matches then increment the time and remove the element.
Else, Dequeue the element and enqueue it again.
The loop will run till the queue is consumed totally.
Java Code

  public static void func(LinkedList q, int n, int[] arr) throws Exception {
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (q.getFirst() == arr[j]) {
                ans++;
                q.removeFirst();
            } else {
                while (q.getFirst() != arr[j]) {
                    int var = q.getFirst();
                    q.addLast(var);
                    q.removeFirst();
                    ans++;
                }
                ans++;
                q.removeFirst();
            }

        }
        System.out.println(ans);

    }
    
C++ Code

#include <bits/stdc++.h>
using namespace std;

int importanceOfTime(queue<int> &q, const vector<int> &arr)
{
    //arr is the ideal order
    //q is the calling order
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (q.front() == arr[i])
        {
            ans++;
            q.pop();
        }
        else
        {
            while (q.front() != arr[i])
            {
                int var = q.front();
                q.push(var);
                q.pop();
                ans++;
            }
            ans++;
            q.pop();
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << importanceOfTime(q, v);

    return 0;
}