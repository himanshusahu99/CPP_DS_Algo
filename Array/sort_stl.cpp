#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a , int b){
    return a>b;
}

int main()
{

    int  a[5];

    cout << "Enter array element " << endl;
    for (int i = 0; i < 5; ++i)
    {
        cin >> a[i];

    }

    sort(a, a+5, compare);

    for (int i = 0; i < 5; ++i)
        cout << a[i] << ", " ;
    {
        /* code */
    }

    return 0;
}