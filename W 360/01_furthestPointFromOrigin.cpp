#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int furthestDistanceFromOrigin(string moves)
{
    int lcount = 0;
    int rcount = 0;
    int n = moves.size();
    for (int i = 0; i < n; i++)
    {
        if (moves[i] == 'L')
        {
            lcount++;
        }
        if (moves[i] == 'R')
        {
            rcount++;
        }
    }
    int ans = 0;
    if (lcount >= rcount)
    {
        ans = lcount;
        ans = ans - rcount;
    }
    else
    {
        ans = rcount;
        ans = ans - lcount;
    }

    return abs(ans + (n - ans));
}
int main()
{
    string moves = "L_RL__R";
    cout << furthestDistanceFromOrigin(moves);
    return 0;
}