#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void createAdjList(vector<vector<int>>& adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
    }
}

int bfs(vector<vector<int>>& adjList, int n, int node)
{
    int count = 1;
    queue<int> q;
    q.push(node);
    vector<bool> visited(n, false);
    visited[node] = 1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto i : adjList[front])
        {
            if (!visited[i])
            {
                count++;
                q.push(i);
                visited[i] = 1;
            }
            else
            {
                return count;
            }
        }
    }
    return 0;
}

vector<int> countVisitedNodes(vector<int> &edges)
{
    int n = edges.size();
    vector<vector<int>> adjList(n);
    vector<int> answer;
    vector<pair<int, int>> Newedges;
    for (int i = 0; i < n; i++)
    {
        Newedges.push_back({i, edges[i]});
    }
    createAdjList(adjList, Newedges);
    for (int i = 0; i < n; i++)
    {
        int ans = bfs(adjList, n, i);
        answer.push_back(ans);
    }
    return answer;
}

int main()
{
    vector<int> edges = {1,2,3,4,0};
    for (auto i : countVisitedNodes(edges))
    {
        cout << i << " ";
    }
    return 0;
}