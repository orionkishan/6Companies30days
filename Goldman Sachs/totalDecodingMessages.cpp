// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string s){
		// Code here
		int n=s.length();
        if(s[0]=='0')
            return 0;
        if(n<=1)
            return 1;
        
        vector<int> dp(n,0);
        dp[0]=1;
        dp[1]=0;
        
        if((s[0]-'0')*10+(s[1]-'0')<=26)
        {
            if(s[1]=='0')
                dp[1]=1;
            else
                dp[1]+=2;
        }
        
        else
        {
            if(s[1]!='0')
                dp[1]=1;
            else
                return 0;
        }
        
        for(int i=2;i<n;i+=1)
        {
            int x=0,y=0;
            
            if(s[i-1]!='0' and ((s[i-1]-'0')*10+s[i]-'0')<=26)
            {
                x=dp[i-2];
            }
            
            if(s[i]!='0')
                y=dp[i-1];
            
            dp[i]=(x+y)%1000000007;
            
            
        }
        
        return dp.back();
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends