#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minOperationsII(vector<int> &nums)
{
    unordered_map<int, int> map;

    int count = 0;
    for (auto i : nums)
    {
        map[i]++;
    }
    for (auto i : map)
    {
        if (i.second < 2)
        {
            return -1;
        }
        if (i.second % 3 == 0)
        {
            int value = i.second / 3;
            count = count + value;
        }
        else if (i.second % 2 == 0)
        {
            int value = i.second / 2;
            count = count + value;
        }
        else if (i.second > 3)
        {
            int value = i.second;
            value = value - 3;
            count++;
            while (value != 0 || value != 1)
            {
                if (i.second % 3 == 0)
                {
                    int value = i.second / 3;
                    count = count + value;
                }
                else if (i.second % 2 == 0)
                {
                    int value = i.second / 2;
                    count = count + value;
                }
            }
        }
    }

    for (auto i : map)
    {
        cout << i.first << " " << i.second << endl;
    }
    return count;
}

int minOperations(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto i : nums)
    {
        mp[i]++;
    }
    int cnt = 0;
    for (auto i : mp)
    {
        if (i.second == 1)
        {
            return -1;
        }
        else if (i.second % 3 == 0)
        {
            // for 0
            cnt = cnt + (i.second / 3);
        }
        else
        {
            // for 1,2
            cnt = cnt + (i.second / 3) + 1;
        }
    }
    return cnt;
}

int main()
{
    vector<int> nums = {14, 12, 14, 14, 12, 14, 14, 12, 12, 12, 12, 14, 14, 12, 14, 14, 14, 12, 12};
    cout << minOperations(nums);
    return 0;
}