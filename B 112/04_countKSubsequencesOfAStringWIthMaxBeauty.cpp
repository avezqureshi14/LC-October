#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findBeauty(string &ds, unordered_map<char, int> &count, vector<int> &beauty)
{
    int n = ds.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + count[ds[i]];
    }
    beauty.push_back(sum);
}

bool checkds(string &ds, int k)
{
    if (ds.size() != k)
    {
        return false;
    }
    unordered_map<char, int> mp;
    for (auto i : ds)
    {
        mp[i]++;
    }
    return mp.size() == k;
}

void solve(int index, string &s, int k, string &ds, unordered_map<char, int> &count, vector<int> &beauty)
{
    if (index == s.length())
    {
        if (checkds(ds, k))
        {
            findBeauty(ds, count, beauty);
        }
        return;
    }

    ds.push_back(s[index]);
    solve(index + 1, s, k, ds, count, beauty);
    ds.pop_back();
    solve(index + 1, s, k, ds, count, beauty);
}

int countMax(vector<int> &beauty)
{
    int maxi = INT_MIN;
    int count = 0;
    for (auto i : beauty)
    {
        maxi = max(maxi, i);
    }
    for (auto i : beauty)
    {
        if (i == maxi)
        {
            count++;
        }
    }
    return count;
}

int countKSubsequencesWithMaxBeauty(string s, int k)
{
    int index = 0;
    string ds;
    vector<int> beauty;
    unordered_map<char, int> count;
    for (auto i : s)
    {
        count[i]++;
    }
    solve(index, s, k, ds, count, beauty);

    return countMax(beauty);
}
int main()
{
    string s = "bcca";
    int k = 2;
    cout<<countKSubsequencesWithMaxBeauty(s, k);
    return 0;
}