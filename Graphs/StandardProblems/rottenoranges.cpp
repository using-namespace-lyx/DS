#include<bits/stdc++.h>
using namespace std;
class  Solution {
    public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size(),m=grid[0].size(),time=0,i,j,count=0,row,col,t,new_row,new_col,t_new,t_max=0;
        queue<pair<pair<int,int>,int>> q;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j}, time});
                }

                else if(grid[i][j]==1)
                count++;
            }
        }

        while(!q.empty())
        {
            row=q.front().first.first;
            col=q.front().first.second;
            t=q.front().second;
            t_max=max(t,t_max);
            q.pop();

            vector<pair<int,int>> directions={{0,-1},{0,1},{-1,0},{1,0}};
            for(auto direction:directions)
            {
                new_row=row+direction.first;
                new_col=col+direction.second;
                t_new=t+1;

                if(new_row>=0 && new_row<n && new_col>=0 &&new_col<m && grid[new_row][new_col]==1 )
                {
                    grid[new_row][new_col]=2;
                    q.push({{new_row,new_col},t_new});
                    count--;
                }
            }
        }

        if(count!=0)
        return -1;

        else
        return t_max;


        
    }
};