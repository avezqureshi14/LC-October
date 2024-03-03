#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void isMatch(int key, unordered_map<int, int> &map)
{
    if (map.find(key) != map.end())
    {
        map[key]--;
        map.erase(key);
    }
}

void doCheck(int key, unordered_map<int, int> &map, bool &flag)
{
    for (auto i : map)
    {
        if (i.second != 0)
        {
            return;
        }
    }
    flag = false;
}

int minOperations(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == k)
    {
        return k;
    }
    int count = 0;
    unordered_map<int, int> map;
    bool flag = true;
    for (int i = 1; i <= k; i++)
    {
        map[i]++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        isMatch(nums[i], map);
        if (flag == true)
        {
            count++;
        }
        doCheck(nums[i], map, flag);
    }
    return count;
}

//simple solution
int minOperationsII(vector<int> &nums, int k)
{
    int n = nums.size();
    set<int> values;
    int moves = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        moves++;
        if (nums[i] <= k)
        {
            values.insert(nums[i]);
        }
        if (values.size() == k)
        {
            return moves;
        }
    }
    return 0;
}

int main()
{
    vector<int> nums = {3, 2, 5, 3, 1};
    int k = 3;
    cout << minOperations(nums, k);
    return 0;
}