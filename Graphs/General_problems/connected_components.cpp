#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj_matrix)
{
    int n=adj_matrix.size();
    vector<vector<int>> adj_list(n);
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(adj_matrix[i][j]==1 && i!=j)
            {
                adj_list[i].push_back(j);
            }
        }
    }
    int front_element,connected_components_count=0;
    vector<int> bfs;
    vector<bool> visited(n,false);
    queue<int> q;

    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            q.push(i);
            visited[i]=true;
            connected_components_count++;
        

        while(! q.empty())
        {
            front_element=q.front();
            bfs.push_back(front_element);
            q.pop();

            for(auto neighbour:adj_list[front_element])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;

                }

            }
        }
        
        }
    }

    return connected_components_count;
}
};