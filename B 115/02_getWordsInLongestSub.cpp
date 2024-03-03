#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<string> getWordsInLongestSubsequence(int n, vector<string> &words, vector<int> &groups)
{
    vector<string>ans;
    ans.push_back(words[0]);
    for (int j = 0; j < n-1; j++)
    {
        if (groups[j] != groups[j+1])
        {
            ans.push_back(words[j+1]);
        }
    }
    return ans;
}
int main()
{
    vector<string> words = {"a", "b", "c", "d"};
    vector<int> groups = {1, 0, 1, 1};
    int n = groups.size();
    for (auto i : getWordsInLongestSubsequence(n, words, groups))
    {
        cout << i << " ";
    }
    return 0;
}