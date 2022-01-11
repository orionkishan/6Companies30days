class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        // {i, j, time}
        queue<tuple<int,int,int>> q;
        
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(grid[i][j]==2)
                    q.push({i,j,0});
        }
        
        
        int ans=0;
        while(!q.empty())
        {
            auto [x,y,time]=q.front();
            q.pop();
            ans=max(time,ans);
            
            if(x+1<m and grid[x+1][y]==1)
            {
                grid[x+1][y]=2;
                q.push({x+1,y,time+1});
            }
            
            if(x-1>=0 and grid[x-1][y]==1)
            {
                grid[x-1][y]=2;
                q.push({x-1,y,time+1});
            }
            
            if(y-1>=0 and grid[x][y-1]==1)
            {
                grid[x][y-1]=2;
                q.push({x,y-1,time+1});
            }
            
            if(y+1<n and grid[x][y+1]==1)
            {
                grid[x][y+1]=2;
                q.push({x,y+1,time+1});
            }
            
    
            
        }
        

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)
                    return -1;
        
        return ans;
        
    }
};