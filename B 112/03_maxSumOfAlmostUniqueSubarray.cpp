#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long maxSum(vector<int> &nums, int m, int k)
{
    int i = 0;
    int j = 0;
    long long maxSum = 0;
    long long sum = 0;
    int n = nums.size();
    unordered_map<int, int> map;
    while (j < n)
    {
        sum = sum + nums[j];
        map[nums[j]]++;
        if (j - i + 1 == k)
        {
            if (map.size() == m || map.size() > m)
            {
                maxSum = max(maxSum, sum);
            }
            sum = sum - nums[i];
            map[nums[i]]--;
            if (map[nums[i]] == 0)
            {
                map.erase(nums[i]);
            }
            i++;
        }
        j++;
    }
    return maxSum;
}
int main()
{

    return 0;
}