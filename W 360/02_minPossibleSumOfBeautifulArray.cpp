#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 10000007;

bool check(vector<int>check,int target){

    if (check.size() < 2)
    {
        return true;
    }
    for (int i = 0; i < check.size(); i++)
    {
        for (int j = i + 1; j < check.size(); j++)
        {
            if (check[i] + check[j] == target)
            {
                return false;
            }
        }
    }
    return true;
}

int minimumPossibleSuII(int n, int target){
    vector<int>nums;
    for (int i = 1; i < INT_MAX; i++)
    {
        nums.push_back(i);
        if (!check(nums,target))
        {
            nums.pop_back();
        }
        if (nums.size() == n)
        {
            break;
        }
    }
    int sum = 0;
    for(auto i : nums){
        sum = sum%MOD + i%MOD;
    }
    return sum%MOD;
}

long long minimumPossibleSum(int n, int target){
    set<int>st;
    int i = 0;
    int num = 1;
    vector<int>nums;
    long long sum = 0;
    while (i < n)
    {
        if (!st.count(target-num))
        {
            nums.push_back(num);
            sum = sum + num;
            i++;
        }
        num++;        
    }

    return sum%MOD;
}

int main()
{
    int n = 2;
    int target = 3;
    cout<<minimumPossibleSum(n,target);
    return 0;
}