#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minOperations(vector<int> &nums, int target)
{
    long long sum = 0;
    int maxi = INT_MIN;
    for(auto i : nums){
        sum = sum + i;
        maxi = max(maxi,i);
    }
    if (sum < target)
    {
        return -1;
    }
    sum = sum - maxi;
    int count = 0;
    int lastOps = maxi;
    while (maxi != 0)
    {
        lastOps = lastOps / 2;
        count++;
        for (int i = 0; i < 2; i++)
        {
            sum = sum + lastOps;
            if (sum == target)
            {
                return count;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int>nums = {1,32,1,2};
    int target = 12;
    cout<<minOperations(nums,target);
    return 0;
}