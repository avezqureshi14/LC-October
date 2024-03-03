#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// length must be shortest
// value must be smallest of that string
string shortestBeautifulSubstring(string s, int k)
{
    int i = 0;
    int j = 0;
    int n = s.length();
    int count = 0;
    string ans = "";
    while (j < n)
    {
        if (s[j] == '1')
        {
            count++;
        }
        if (count == k)
        {
            while (i < n && count == k)
            {
                string s1 = s.substr(i, j - i + 1);
                if (ans.size() == 0 || s1.size() < ans.size())
                {
                    ans = s1;
                }
                else if (ans.size() == s1.size())
                {
                    ans = min(ans, s1);
                }
                if (s[i] == '1')
                {
                    count--;
                }
                i++;                
            }
        }
        j++;
    }
    return ans;
}
int main()
{
    string s = "100011001";
    int k = 3;
    cout<<shortestBeautifulSubstring(s,k);
    return 0;
}