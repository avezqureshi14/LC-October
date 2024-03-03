#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minimumSum(vector<int> &nums)
{
    int n = nums.size();
    int minSum = INT_MAX;
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    left[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = min(left[i - 1], nums[i]);
    }
    right[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = min(right[i + 1], nums[i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i] > left[i] && nums[i] > right[i])
        {
            int sum = nums[i] + left[i] + right[i];
            minSum = min(minSum, sum);
        }
    }
    if (minSum == INT_MAX)
    {
        return -1;
    }
    else
    {
        return minSum;
    }
}
int main()
{
    vector<int> nums = {5, 4, 8, 7, 10, 2};
    cout << minimumSum(nums);
    return 0;
}