class Solution {
public:
    int n;
    int findCircleNum(vector<vector<int>>& grid) {
        
        n=grid.size();
        vector<bool> visited(n,false);
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {   
                visited[i]=true;
                dfs(grid,visited,i);
                count+=1;
                
            }            
            
            
        }
        
        return count;
        
        
    }
    
    void dfs(vector<vector<int>> &grid,vector<bool> &v,int i)
    {
        
        v[i]=true;
        
        for(int j=0;j<n;j++)
        {
            if(grid[i][j] and !v[j])
                dfs(grid,v,j);
        }
        
        
    }
};