#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>> &adj_list, vector<bool> &visited, vector<int> &dfs_list)
{
    visited[node]=true;
    dfs_list.push_back(node);

    for(auto neighbour:adj_list[node])
    {
        if(!visited[neighbour])
        dfs(neighbour,adj_list,visited,dfs_list);
    }
}

vector<int> dfs_traversal(int n,vector<vector<int>> adj_list)
{
    int i;
    vector<bool> visited(n,false);
    vector<int> dfs_list;
    for(i=0;i<n;i++)
    {   if(!visited[i])
        dfs(i,adj_list,visited,dfs_list);

    }

    return dfs_list;
}