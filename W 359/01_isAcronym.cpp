#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isAcronym(vector<string> &words, string s)
{
    int n = words.size();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        ans.push_back(words[i][0]);
    }
    return ans == s;
}
int main()
{

    return 0;
}