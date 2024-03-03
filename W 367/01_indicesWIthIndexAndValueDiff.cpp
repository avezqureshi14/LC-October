#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
{
    int n = nums.size();
    vector<int>ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (abs(i-j) >= indexDifference && abs(nums[i]-nums[j] >= valueDifference))
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}
int main()
{
    vector<int>nums = {1,2,3};
    int indexDiff = 2;
    int valueDiff = 4;
    for(auto i : findIndices(nums,indexDiff,valueDiff)){
        cout<<i<<" ";
    }
    return 0;
}