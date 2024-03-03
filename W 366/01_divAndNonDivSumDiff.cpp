#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int differenceOfSums(int n, int m)
{
    vector<int> n1;
    vector<int> n2;
    for (int i = 1; i <= n; i++)
    {
        if (i % m != 0)
        {
            n1.push_back(i);
        }
        if (i % m == 0)
        {
            n2.push_back(i);
        }
    }
    int num1 = 0;
    int num2 = 0;
    for (auto i : n1)
    {
        num1 = num1 + i;
    }
    for (auto i : n2)
    {
        num2 = num2 + i;
    }
    return num1 - num2;
}i
int main()
{

    return 0;
}