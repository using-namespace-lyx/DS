#include<bits/stdc++.h>
using namespace std;

// Space complexity -> O(n)
// Time complexity to form a list depends on for loop which depends on input size O(m)

vector<vector<pair<int,int>>> adj_list_form(int m,int n, vector<vector<int>> edges)
{
    vector<vector<pair<int,int>>> adj_list(n+1);//Assume 1 based
    int i,input_size=edges.size(),u,v,wt;

    for(i=0;i<input_size;i++)
    {
        u=edges[i][0];
        v=edges[i][1];
        wt=edges[i][2]; //if wts given
        adj_list[u].push_back({v,wt});
        adj_list[v].push_back({u,wt});//if undirected
    }

    return adj_list;
}