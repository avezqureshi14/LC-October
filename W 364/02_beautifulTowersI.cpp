#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findPeak(vector<int> &maxHeights)
{
    int n = maxHeights.size();
    int peak = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxHeights[i] > maxHeights[peak])
        {
            peak = i;
        }
    }
    return peak;
}

long long maximumSumOfHeights(vector<int> &maxHeights)
{
    int n = maxHeights.size();
    int peak = findPeak(maxHeights);
    int i = 0;
    if (peak > 0)
    {
        i = peak - 1;
    }
    else
    {
        i = peak;
    }

    int j = 0;
    if (peak < n - 1)
    {
        j = peak + 1;
    }
    else
    {
        j = peak;
    }
    long long  sum = 0;
    while (i >= 1)
    {
        if (maxHeights[i] < maxHeights[i - 1])
        {
            maxHeights[i - 1] = maxHeights[i];
        }
        i--;
    }
    while (j <= n - 1)
    {
        if (maxHeights[j] < maxHeights[j + 1])
        {
            maxHeights[j + 1] = maxHeights[j];
        }
        j++;
    }
    for (auto i : maxHeights)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : maxHeights)
    {
        sum = sum + i;
    }

    return sum;
}
int main()
{
    vector<int> maxHeights = {3,2,5,5,2,3};
    cout << maximumSumOfHeights(maxHeights);
    return 0;
}