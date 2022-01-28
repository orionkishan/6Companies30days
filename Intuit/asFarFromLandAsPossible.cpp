class Solution {
public:
int maxDistance(vector<vector<int>>& grid) {

    int m=grid.size();
    int n=grid[0].size();
    
    vector<vector<int>>dp(m,vector<int>(n,1e6));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                dp[i][j]=0;
            } 
        }     
    }
    
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                if(i-1>=0){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                }
                
                if(j-1>=0){
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                }   
            }
        }
    }
    
    
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){      
             if(grid[i][j]==0){
                if(i+1<m){
                    dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
                }
                
                if(j+1<n){
                    dp[i][j]=min(dp[i][j],dp[i][j+1]+1);
                }
            }
        }
    }
    
    
    int maxi=INT_MIN;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                maxi=max(maxi,dp[i][j]);
            }   
        }   
    }
    
    if(maxi<0 || maxi>=1e6){
        return -1;
    }
    
    
    return maxi;
    

}
};