#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long minIncrementOperationsII(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    int maxi = 0;
    long long cnt = 0;
    while (j < n)
    {
        if (nums[j] > nums[maxi])
        {
            maxi = j;
        }
        if (j - i + 1 >= 3)
        {
            if (nums[maxi] < k)
            {
                cnt = cnt + (k - nums[maxi]);
                nums[maxi] = nums[maxi] + (k - maxi);
            }
            cout << maxi << "=maxi " << i << "=i" << endl;
            if (maxi <= i)
            {
                maxi = i + 1;
            }
            i++;
        }
        j++;
    }
    return cnt;
}

long long recursive(vector<int> &nums, int n, int k)
{
    if (n < 0)
    {
        return 0;
    }

    if (nums[n] < k)
    {
        int include = (k - nums[n]) + recursive(nums, n - 1, k);
        int exclude = recursive(nums, n - 1, k);
        return min(include, exclude);
    }
    else
    {
        return recursive(nums, n - 1, k);
    }
}

long long minIncrementOperations(vector<int> &nums, int k)
{
    int n = nums.size();
    return recursive(nums, n - 1, k);
}


int main()
{
    vector<int> nums = {0,1,3,3};
    int k = 5;
    cout << minIncrementOperations(nums, k);

    return 0;
}