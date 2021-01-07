
#include <iostream>
#include <cstring>
using namespace std;

string keypad[] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz"};

string table[] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

void phoneKeypad(string inp, string out)
{
    //Base case
    if (inp.size() == 0)
    {

        for(int i =0; i<11; i++)
        {
                size_t found = table[i].find(out);
                if (found != string::npos) 
                    cout << table[i] << endl;  
        }

        return;
    }

    //Rec case
    int r = inp[0] - '0';
    for (unsigned int k = 0; k < keypad[r].length(); k++)
    {
        char ch = keypad[r][k];
        phoneKeypad(inp.substr(1), out + ch);
    }
}
int main()
{
    string input;
    cin >> input;

    phoneKeypad(input, "");
    return 0;
}