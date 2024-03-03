#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minAbsoluteDifferenceII(vector<int> &nums, int x)
{
    int n = nums.size();
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(j-i) >= x)
            {
                mini =  min(mini,abs(nums[i]-nums[j]));
            }
        }
    }
    return mini;
}

int minAbsoluteDifference(vector<int>&nums, int x){
    int n = nums.size();
    set<int>st;
    for (int i = x; i < n; i++)
    {
        st.insert(nums[i-x]);
    }
    
}

int main()
{
    vector<int>nums = {1,2,3,4};
    int x = 3;
    cout<<minAbsoluteDifference(nums,x);
    return 0;
}