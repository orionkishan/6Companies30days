class Solution {
public:
    vector<vector<bool>> p;
    vector<vector<bool>> a;
    int m,n;
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> ans;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        m = heights.size();
        n = heights[0].size();
        p = vector<vector<bool>>(m,vector<bool>(n,false));
        a = vector<vector<bool>>(m,vector<bool>(n,false));
        
        for(int i =0;i<m;i+=1)
        {
            dfs(heights,p,i,0);
            dfs(heights,a,i,n-1);
        }
        for(int j =0;j<n;j+=1)
        {
            dfs(heights,p,0,j);
            dfs(heights,a,m-1,j);
        }
        
        return ans;
        
    }
    
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& ocean,int i,int j)
    {

        if(ocean[i][j])
            return;
        
        ocean[i][j]=true;
        if(p[i][j] and a[i][j])
            ans.push_back({i,j});
        
        for(auto [dx,dy]:dir)
        {
            if((i+dx)>=m or (i+dx)<0 or (j+dy)>=n or (j+dy)<0)
                continue;
            
            if(heights[i][j]<=heights[i+dx][j+dy])
                dfs(heights,ocean,i+dx,j+dy);
        }
        
    }
    
    
};