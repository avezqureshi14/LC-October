#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minChanges(string s)
{
    int n = s.length();
    int zerCnt = 0;
    int oneCnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            zerCnt++;
            cout<<"z = "<<zerCnt<<endl;
        }
        if (s[i] == '1')
        {
            oneCnt++;
            cout<<"one = "<<oneCnt<<endl;
        }
        cout<<i<<" = i "<<i+1<<" = i+1 "<<(i + 1) % 2<<" = i + 1 % 2 "<<endl; 
        if ((i + 1) % 2 == 0)
        {
            if (oneCnt % 2 == 0 || zerCnt % 2 == 0)
            {
                ans = ans + 0;
            }
            else
            {
                ans = ans + 1;
            }
            
            oneCnt = 0;
            zerCnt = 0;
        }
    }
    return ans;
}
int main()
{
    string s = "1001";
    cout << minChanges(s);
    return 0;
}