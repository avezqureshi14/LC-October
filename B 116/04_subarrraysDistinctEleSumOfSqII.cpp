#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<vector<int>>&ans, vector<int>&ds, vector<int>&nums)
{
    if (index == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    ds.push_back(nums[index]);
    solve(index+1,ans,ds,nums);
    ds.pop_back();
    solve(index+1,ans,ds,nums);
}
int sumCounts(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    map<int,int>mp;
    for (int i = 1; i <= n; i++)
    {
        int j = 0;
        while (j < n)
        {
            mp[nums[j]]++;
            if (j-i+1 == i)
            {
                int size = mp.size();
                ans = ans + (size*size);
                cout<<i<<" = i"<<endl;
                for(auto i : mp){
                    cout<<i.first<<" "<<i.second<<endl;
                }
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
    }
    
    return ans;
}
int main()
{
    vector<int>nums = {1,2,1};
    sumCounts(nums);
    return 0;
}