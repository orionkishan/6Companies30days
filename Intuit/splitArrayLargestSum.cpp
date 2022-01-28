class Solution {
public:

    int n;
    int splitArray(vector<int>& nums, int m) {

        n =nums.size();
        vector<vector<int>> dp(1001,vector<int>(51,-1));
        vector<int> ps(n,0);
        ps[0]=nums[0];
        for(int i=1;i<n;i+=1)
            ps[i]=ps[i-1]+nums[i];

        return recur(ps,m,0,dp);
        
     
    }
    
    int recur(vector<int> &ps,int m,int i,vector<vector<int>> &dp)
    {   
        if(i>=n)
            return INT_MAX;
        if(m==1)
        {   
            if(i)
                return ps[n-1]-ps[i-1];
            else
                return ps[n-1];

        }
        
        if(dp[i][m]!=-1)
            return dp[i][m];
        
        int mn = INT_MAX;
        for(int l=i;l<n;l+=1)
        {   
            int curr=0;
            if(i!=0)
                curr=ps[l]-ps[i-1];
            else 
                curr=ps[l];

            mn=min(mn,max(curr,recur(ps,m-1,l+1,dp)));
        }
        
        
        return dp[i][m]=mn;
        

    }
};