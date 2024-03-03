#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxDigit(int num)
{
    int maxi = INT_MIN;
    while (num != 0)
    {
        int digit = num % 10;
        maxi = max(maxi, digit);
        num = num / 10;
    }
    return maxi;
}

int maxPairSum(vector<int> &nums)
{
    int n = nums.size();
    int maxSum = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int n1 = maxDigit(nums[i]);
            int n2 = maxDigit(nums[j]);
            if (n1 == n2)
            {
                maxSum = max(maxSum, nums[i] + nums[j]);
            }
        }
    }
    return maxSum;
}
int main()
{
    vector<int>nums = {1,2,3,4};
    cout<<maxPairSum(nums);
    return 0;
}