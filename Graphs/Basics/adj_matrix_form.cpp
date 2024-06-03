#include<bits/stdc++.h>
using namespace std;

// Space complexity -> O(n^2)
// Time complexity to form a matrix depends on for loop which depends on input size O(m)

vector<vector<int>> form_adj_matrix(int m,int n,vector<vector<int>> edges)
{
    vector<vector<int>> adj_matrix(n+1,vector<int>(n+1,0));

    int i=0,input_size=edges.size(),u,v;

    for(i=0;i<input_size;i++)
    {
        u=edges[i][0];
        v=edges[i][1];
        adj_matrix[u][v]=1;
        adj_matrix[v][u]=1; // Only if graph is undirected 
        

    }

    return adj_matrix;
}

vector<vector<int>> form_adj_matrix_with_wt_given(int m,int n,vector<vector<int>> edges)
{
    vector<vector<int>> adj_matrix(n+1,vector<int>(n+1,0));

    int i=0,input_size=edges.size(),u,v,wt;

    for(i=0;i<input_size;i++)
    {
        u=edges[i][0];
        v=edges[i][1];
        wt=edges[i][2];
        adj_matrix[u][v]=wt;
        adj_matrix[v][u]=wt; // Only if graph is undirected 
        

    }

    return adj_matrix;
}

