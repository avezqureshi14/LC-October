#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkSum(vector<int> ds, int target)
{
    int sum = 0;
    for (auto i : ds)
    {
        sum = sum + i;
    }
    if (sum == target)
    {
        return true;
    }
    return false;
}

int recursive(int index, vector<int> &nums, int n, int target, vector<vector<int>> &memo)
{
    if (target == 0)
    {
        return 0;
    }

    if (index >= n || target < 0)
    {
        return -1001;
    }

    // Check if the result is already memoized
    if (memo[index][target] != -1)
    {
        return memo[index][target];
    }

    // Include the current element in the subset
    int take = 1 + recursive(index + 1, nums, n, target-nums[index], memo);

    // Exclude the current element from the subset
    int noTake = recursive(index + 1, nums, n, target, memo);

    // Memoize the result for the current state
    memo[index][target] = max(take, noTake);
}

int lengthOfLongestSubsequence(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> memo(1001 , vector<int>(1001, -1));
    int ans = recursive(0,nums,n,target,memo);
    return ans > 0 ? ans : -1;
}


int LLS(vector<int> &nums, int n, int target, vector<vector<int>> &dp)
{
    if (n <= 0)
    {
        if (target == 0)
        {
            return 0;
        }
        return -1;
    }

    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }
    if (nums[n - 1] <= target)
    {
        int include = LLS(nums, n - 1, target - nums[n - 1], dp);
        int exclude = LLS(nums, n - 1, target, dp);
        if (include == -1)
        {
            return exclude;
        }
        dp[n][target] = max(1 + include, exclude);
        return dp[n][target];
    }
    else
    {
        dp[n][target] = LLS(nums, n - 1, target, dp);
        return dp[n][target];
    }
}

int lengthOfLongestSubsequenceII(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    int ans = LLS(nums, n, target, dp);
    return (ans == 0) ? -1 : ans;
}



int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 9;
    cout << lengthOfLongestSubsequence(nums, target);
    return 0;
}