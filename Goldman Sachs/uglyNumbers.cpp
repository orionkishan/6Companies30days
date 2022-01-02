// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    
	    vector<ull> dp(n,0);
	    dp[0] =1;
	    
        // varibles to point to index
        // whose value is to by multiplied
        // by 2,3 and 5 respectively
	    int two = 0;
	    int three = 0;
	    int five = 0;
	    
	    for(int i = 1;i<n;i+=1)
	    {
	        dp[i] = min(dp[two]*2,min(dp[three]*3,dp[five]*5));
	        
	        if(dp[i]==dp[two]*2)
	            two+=1;
	           
	        if(dp[i]==dp[three]*3)
	            three+=1;
	        
	        if(dp[i]==dp[five]*5)
	            five+=1;
	        
	    }
	    
	    return dp[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends