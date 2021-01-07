#include<iostream>
using namespace std;

int main()
{
	char ch;
	int n1, n2;

	cin >> ch;

	while(ch != 'X' and ch != 'x')
	{

		

		switch(ch)
		{
			case '+':
			cin >> n1 >> n2;
			cout << n1 + n2 << endl;
			break;

			case '-':
			cin >> n1 >> n2;
			cout << n1-n2 << endl;
			break;

			case '*':
			cin >> n1 >> n2;
			cout << n1*n2 << endl;
			break;

			case '/':
			cin >> n1 >> n2;
			cout << n1/n2 << endl;
			break;

			case '%':
			cin >> n1 >> n2;
			cout << n1%n2 << endl;
			break;

			default:
			cout << "Invalid operation. Try again." << endl;
			break;
		}

		cin >> ch;
	}
	
	return 0;
}