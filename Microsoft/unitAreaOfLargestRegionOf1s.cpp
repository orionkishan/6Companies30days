// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int m;
    int n;
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i+=1)
        {
            for(int j = 0;j<n;j+=1)
            {
                if(grid[i][j])
                {
                    int count=0;
                    dfs(i,j,grid,count);
                    ans=max(ans,count);
                }
                
            }
        }
        
        return ans;
        
    }
    
    void dfs(int i,int j,vector<vector<int>> &grid,int& count)
    {
        if(i>=m or i<0 or j>=n or j<0)
            return;
            
        if(!grid[i][j])
            return;
        
        count+=1;
        grid[i][j]=0;
        for(auto p:dir)
            dfs(i+p.first,j+p.second,grid,count);
        
        
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends