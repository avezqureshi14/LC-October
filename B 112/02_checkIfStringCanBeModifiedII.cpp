#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool canBeEqualII(string &s1, string &s2)
{
    int n = s1.length();

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < n)
        {
            if (s1[i] != s2[i])
            {
                int value = j - i;
                if (value % 2 == 0)
                {
                    swap(s1[i], s1[j]);
                    if (s1[i] != s2[i])
                    {
                        swap(s1[i], s1[j]);
                    }
                }
            }
            j++;
        }
    }
    if (s1 == s2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// if in our both the strings if a character in the string s1 is a even position and the same character in s2 is at even position and vice versa
// then those strings can be made equal by swapping

bool areElementsEqual(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

bool checkStrings(string s1, string s2)
{
    int n = s1.length();
    string temp1 = "";
    string temp2 = "";
    for (int i = 0; i < n; i += 2)
    {
        temp1.push_back(s1[i]);
        temp2.push_back(s2[i]);
    }
    if (!areElementsEqual(temp1, temp2))
    {
        return false;
    }
    temp1.clear();
    temp2.clear();
    for (int i = 1; i < n; i += 2)
    {
        temp1.push_back(s1[i]);
        temp2.push_back(s2[i]);
    }
    if (!areElementsEqual(temp1, temp2))
    {
        return false;
    }
    return true;
}

int main()
{
    string s1 = "abe";
    string s2 = "bea";
    cout << checkStrings(s1, s2);
    return 0;
}