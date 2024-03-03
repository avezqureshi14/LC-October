#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long greaterThanMaxi(vector<int> &nums, vector<int> &ds, long long maxi)
{
    long long i = nums[ds[0]];
    long long j = nums[ds[1]];
    long long k = nums[ds[2]];

    long long sol = (i - j) * k;
    if (sol > maxi)
    {
        return sol;
    }
    else
    {
        return maxi;
    }
}

void solve(int index, vector<int> &ds, vector<int> &nums, long long &maxi)
{
    if (index == nums.size())
    {
        if (ds.size() == 3)
        {
            maxi = greaterThanMaxi(nums, ds, maxi);
        }
        return;
    }

    ds.push_back(index);
    solve(index + 1, ds, nums, maxi);
    ds.pop_back();
    solve(index + 1, ds, nums, maxi);
}

long long maximumTripletValue(vector<int> &nums)
{
    int index = 0;
    vector<int> ds;
    long long maxi = INT_MIN;
    solve(index, ds, nums, maxi);
    if (maxi < 0)
    {
        return 0;
    }
    else
    {
        return maxi;
    }
}
int main()
{
    vector<int> nums = {1000000, 1, 1000000};
    cout << maximumTripletValue(nums);
    return 0;
}