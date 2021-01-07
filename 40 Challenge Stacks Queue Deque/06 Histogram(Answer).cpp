For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle. If we calculate such area for every bar ‘x’ and find the maximum of all areas, our task is done. How to calculate area with ‘x’ as smallest bar? We need to know index of the first smaller (smaller than ‘x’) bar on left of ‘x’ and index of first smaller bar on right of ‘x’. Let us call these indexes as ‘left index’ and ‘right index’ respectively. We traverse all bars from left to right, maintain a stack of bars. Every bar is pushed to stack once. A bar is popped from stack when a bar of smaller height is seen. When a bar is popped, we calculate the area with the popped bar as smallest bar. How do we get left and right indexes of the popped bar – the current index tells us the ‘right index’ and index of previous item in stack is the ‘left index’. Following is the complete algorithm.

Algo
1) Create an empty stack.
2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.
……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).
3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.

Java Code

import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        long[] arr = new long[scn.nextInt()];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextLong();
        }

        long maxArea = 0;
        long pArea = 0;

        Stack stack = new Stack();

        int i = 0;
        while (i < arr.length) {

            if (stack.isEmpty() || arr[i] > arr[stack.peek()]) {
                stack.push(i);
                i++;
            }

            else {
                int idx = stack.pop();
                long x = arr[idx];

                int R = i;

                if (stack.isEmpty()) {
                    pArea = R * x;
                } else {
                    int L = stack.peek();
                    pArea = (R - L - 1) * x;
                }

                if (pArea > maxArea) {
                    maxArea = pArea;
                }

            }

        }

        while (!stack.isEmpty()) {

            long x = arr[stack.pop()];

            int R = i;

            if (stack.isEmpty()) {
                pArea = R * x;
            } else {
                int L = stack.peek();
                pArea = (R - L - 1) * x;
            }

            if (pArea > maxArea) {
                maxArea = pArea;
            }

        }

        System.out.println(maxArea);

    }
}


C++ Code

long long int maxHistogramArea(vector<long long int> &a)
{
    stack<long long int> s;
    long long int maxArea = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(i);
        }
        else
        {
            while (!s.empty() && a[i] < a[s.top()])
            {
                long long int x = s.top();
                s.pop();
                long long int area = 0;
                if (s.empty())
                    area = a[x] * i;
                else
                    area = a[x] * (i - s.top() - 1);
                maxArea = max(area, maxArea);
            }
            s.push(i);
        }
    }
    while (!s.empty())
    {
        long long int area = 0;
        long long int x = s.top();
        s.pop();
        if (s.empty())
        {
            area = a[x] * n;
        }
        else
        {
            area = a[x] * (n - x);
        }

        maxArea = max(area, maxArea);
    }

    return maxArea;
}
Python Code
class Solution:
    def largestRectangleArea(self, a) -> int:
        if len(a)==0:
            return 0
        stack = []
        maxArea = 0
        n = len(a)
        for i in range(len(a)):
            while len(stack)>0 and a[i]<a[stack[-1]]:
                x = stack[-1]
                stack.pop()
                if len(stack)==0:
                    area = a[x]*i
                else:
                    area = a[x]*(i-stack[-1]-1)
                maxArea = max(maxArea, area)

            stack.append(i)

        while len(stack)>0:
            area,x = 0, stack[-1]
            stack.pop()
            if len(stack)==0:
                area = a[x]*n
            else:
                area = a[x]*(n-stack[-1]-1)
            maxArea = max(maxArea, area)

        return maxArea


s = Solution()
n = input()
arr = [int(x) for x in input().split()]
ans = s.largestRectangleArea(arr)
print(ans)