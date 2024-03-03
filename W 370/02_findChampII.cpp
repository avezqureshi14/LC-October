#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void prepareAdj(vector<vector<int>> edges, unordered_map<int, set<int>> &adjList)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].insert(v);
    }
}

int findChampion(int n, vector<vector<int>> &edges)
{
    unordered_map<int, set<int>> adjList;
    prepareAdj(edges, adjList);
    vector<int> indegree(n, -1);
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }
    int cnt = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == -1)
        {
            cnt++;
            ans = i;
        }
    }
    if (cnt > 1)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}
int main()
{
    // vector<vector<int>>edges = {{0,2},{1,3},{1,2}};
    vector<vector<int>>edges = {{0,1},{1,2}};
    int n = 3;
    cout<<findChampion(n,edges);
    return 0;
}