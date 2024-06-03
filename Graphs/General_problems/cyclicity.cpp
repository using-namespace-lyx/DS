#include<bits/stdc++.h>
using namespace std;

bool check_cyclicity_via_bfs_traversal(int n, vector<vector<int>> adj_list)
{
    int i,front_element,connected_components_count=0;
    vector<int> bfs,parent(n,-1);
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
                    parent[neighbour]=front_element;

                }

                else
                {
                    if(neighbour!=parent[front_element])
                        return true;

                }
                

            }
        }
        
        }
    }

    return false;
}