#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long minSum(vector<int> &nums1, vector<int> &nums2)
{
    int sum1 = 0;
    int sum2 = 0;
    bool zero1 = false;
    bool zero2 = false;
    for (int i = 0; i < nums1.size(); i++)
    {
        
    }
    
    for (auto i : nums1)
    {
        if (i == 0)
        {
            sum1 = sum1 + 1;
            zero1 = true;
        }
        else
        {
            sum1 = sum1 + i;
        }
    }
    for (auto i : nums2)
    {
        if (i == 0)
        {
            sum2 = sum2 + 1;
            zero2 = true;
        }
        else
        {
            sum2 = sum2 + i;
        }
    }
    if (sum1 < sum2 && zero1 == false || sum1 > sum2 && zero2 == false)
    {
        return -1;
    }
    else
    {
        return max(sum1, sum2);
    }
}
int main()
{
    vector<int>nums1 = {3,2,0,1,0};
    vector<int>nums2 = {6,5,0};
    cout<<minSum(nums1,nums2);
    return 0;
}