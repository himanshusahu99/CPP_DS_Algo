#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int left = -1; 
    unordered_map<char , int> last_occurance;
    int max_len = 0; 

    for(int right = 0; right < s.size(); right++)
    {
        if(last_occurance.find(s[right]) != last_occurance.end() and last_occurance[s[right]] > left)
            left = last_occurance[s[right]];

        max_len = max((right - left), max_len);
        last_occurance[s[right]] = right;  
    }

    return max_len; 
}



int main()
{
    string s; /// = "abcabcd";

    cin >> s; 

  cout <<lengthOfLongestSubstring(s);
}