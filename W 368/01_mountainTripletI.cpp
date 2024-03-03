#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minimumSum(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int minSum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[j] > nums[i] && nums[j] > nums[k])
                {
                    sum = nums[i] + nums[j] + nums[k];
                    minSum = min(minSum, sum);
                }
            }
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
    vector<int> nums = {6,5,4,3,4,5};
    cout << minimumSum(nums);
    return 0;
}