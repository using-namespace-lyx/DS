#include<bits/stdc++.h>
using namespace std;

void bfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &visited)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=1;
    int row,col,del_row,del_col,new_row,new_col;
    int n=grid.size(),m=grid[0].size();

    while(!q.empty())
    {
        row=q.front().first;
        col=q.front().second;
        q.pop();

        for(del_row=-1;del_row<=1;del_row++)
        {
            for(del_col=-1;del_col<=1;del_col++)
            {
                new_row=row+del_row;
                new_col=col+del_col;

                if(!visited[new_row][new_col] && ( new_row>=0 && new_row < n) && (new_col>=0 && new_col< m) && visited[new_row][new_col]==1)
                {
                    visited[new_row][new_col]=1;
                    q.push({new_row, new_col});
                }

            }

        }


    }


}



int count_islands(vector<vector<int>> grid)
{
    int n=grid.size();
    int m=grid[0].size();
    int count=0;
    vector<vector<int>> visited(n,vector<int>(m,0));
    int row,col;
    for(row=0;row<n;row++)
    {
        for(col=0;col<m;col++)
        {
            if(grid[row][col]==1 && !visited[row][col])
            {
                bfs(row,col,grid,visited);
                count++;
            }
        }
    }

    return count;
}