class Solution {
public:
    int getMoneyAmount(int n) {
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return recur(1,n,dp);
    }
    
    int recur(int s,int e,vector<vector<int>> &dp)
    {
        if(s>=e)
            return 0;
        
        if(dp[s][e]!=-1)
            return dp[s][e];
        
        int ans = INT_MAX;
        
        for(int i =s;i<=e;i+=1)
        {
            int next = max(recur(s,i-1,dp),recur(i+1,e,dp));
            ans = min(ans,i+next);
        }
        
        return dp[s][e]=ans;
        
        
    }
};