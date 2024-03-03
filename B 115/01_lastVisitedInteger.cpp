#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> lastVisitedIntegers(vector<string> &words)
{
    int n = words.size();
    vector<int> nums_reverse;
    int k = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (words[i] == "prev")
        {
            k++;
            if (k > nums_reverse.size())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(nums_reverse[k - 1]);
            }
        }
        else
        {
            k = 0;
            nums_reverse.push_back(stoi(words[i]));
            reverse(nums_reverse.begin(), nums_reverse.end());
        }
    }
    return ans;
}
int main()
{
    vector<string> words = {"prev","prev","94","56","prev","32","prev","prev","prev"};
    for (auto i : lastVisitedIntegers(words))
    {
        cout << i << " ";
    }
    return 0;
}