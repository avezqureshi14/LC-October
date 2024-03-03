#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//iss question meh apun sirf j - i = 2 agar aisa honga toh tab hi swap karne ka 
bool canBeEqual(string s1, string s2)
{
    if(s1 == s2){
        return true;
    }
    //agar starting ke doh elements equal hai, to next two pairs ko pehla swap karo
    if (s1[0] == s2[0])
    {
        swap(s1[1], s1[3]);
        if (s1 == s2)
        {
            return true;
        }
        swap(s1[0], s1[2]);
        if (s1 == s2)
        {
            return true;
        }
    }
    else
    {
        swap(s1[0], s1[2]);
        if (s1 == s2)
        {
            return true;
        }
        swap(s1[1], s1[3]);
        if (s1 == s2)
        {
            return true;
        }
    }

    return false;
}
int main()
{
    string s1 = "bnxw";
    string s2 = "bwxn";
    cout << canBeEqual(s1, s2);

    return 0;
}