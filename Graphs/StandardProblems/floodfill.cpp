#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &ans,vector<vector<int>> &visited, int initial_color,int newColor)
    {
        int n=ans.size(),m=ans[0].size(),new_row,new_col;
        visited[row][col]=1;
        ans[row][col]=newColor;
        vector<pair<int,int>> directions={{0,-1},{0,1},{-1,0},{1,0}};
        
        for(auto direction:directions)
    {
        new_row=row+direction.first;
        new_col=col+direction.second;

        if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && !visited[new_row][new_col] && ans[new_row][new_col]==initial_color)
        {
            dfs(new_row,new_col,ans,visited,initial_color,newColor);
        }
    }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>> & image, int sr, int sc, int newColor) {
      
        int initial_color=image[sr][sc];
        vector<vector<int>> ans=image;
        int n=image.size(),m=image[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        
        dfs(sr,sc,ans,visited,initial_color,newColor);
        
        return ans;
    }
};