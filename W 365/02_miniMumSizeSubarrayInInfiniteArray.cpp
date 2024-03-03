#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minSizeSubarrayII(vector<int> &nums, int target)
{
    // this will pass all the test cases except one
    int size = nums.size();
    long long n = size * 2 * 1000;
    int i = 0;
    int j = 0;
    int sum = 0;
    int mini = INT_MAX;
    while (j < n)
    {
        if (sum == target)
        {
            mini = min(mini, j - i);
        }
        sum += nums[j % size];
        while (sum > target)
        {
            sum = sum - nums[i % size];
            i++;
        }
        j++;
    }
    if (mini != INT_MAX)
    {
        return mini;
    }
    else
    {
        return -1;
    }
}

int minSizeSubarray(vector<int> &nums, int target)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0L);
    long sum = 0;
    int n = nums.size();
    int k = target / totalSum;
    int result = n;
    target = target % totalSum;
    
    if(target == 0){
        return k * n;
    }
    unordered_map<long, int> dp{{0L, -1}};
    for (int i = 0; i < 2 * n; ++i)
    {
        sum = sum + nums[i % n];
        if (dp.count(sum-target))
        {
            result = min(result,i - dp[sum-target]);
        }
        dp[sum] = i;
    }
    return result < n ? result + k * n : -1;
}

int main()
{
    vector<int> nums = {2, 4, 6, 8};
    int target = 3;
    // cout << minSizeSubarray(nums, target);
    cout << 5 % 6;
    return 0;
}