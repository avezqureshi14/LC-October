#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//there are n teams (n == cols/rows as both are same), if grid[i][j] == 1 and i != j than team i is stronger than team b, our winner team must need to be stronger than all the other teams so by taking an observation if our winner team is having n-1 times grid[i][j] == 1 then definitely it is gonna going to be the winner  

int findChampion(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[i][j] == 1)
            {
                count++;
            }
            if (count == grid.size()-1)
            {
                return i;
            }
        }
    }
    return -1;
}
int main()
{
    vector<vector<int>> grid = {{0, 0, 1}, {1, 0, 1}, {0, 0, 0}};
    cout << findChampion(grid);
    return 0;
}