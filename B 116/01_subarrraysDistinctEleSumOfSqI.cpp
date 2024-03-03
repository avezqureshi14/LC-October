#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int sumCounts(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    int ans = 0;
    set<int>st;
    for (int i = 0; i < n ; i++)
    {
        for (int j = i; j < n; j++)
        {
            st.insert(nums[j]);  
            int n = st.size(); 
            ans = ans + (n*n);
        }
        st.clear();
    }
    
    return ans;
}
int main()
{
    vector<int>nums = {1,1};
    cout<<sumCounts(nums);
    return 0;
}