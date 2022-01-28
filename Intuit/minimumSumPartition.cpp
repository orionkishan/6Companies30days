// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:

    int ans =INT_MAX;
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    if(n==1)
	        return arr[0];
	        
	    int total = 0;
	    
	    
	    for(int i =0;i<n;i+=1)
	        total+=arr[i];
	    
	   // recur(0,arr,n,total,0,0);
	    vector<vector<int>> dp(n,vector<int>(total,0));
	    helper(arr,n,dp,total);
	    return ans;
	} 
	
	void helper(int arr[],int n, vector<vector<int>> &dp,int total)
	{
	    for(int i = 0;i<n;i+=1)
	    {
	        for(int j =1;j<total;j+=1)
	        {
	           if(arr[i]==j)
	                dp[i][j]=1;
	           else if(arr[i]>j)
	                dp[i][j]=i==0?0:dp[i-1][j];
	           else
	                dp[i][j]=i==0?0:dp[i-1][j-arr[i]] or dp[i-1][j];
	           
	        }
	     
	    }
	   
	    for(int i=1;i<total;i+=1)
	        if(dp[n-1][i])
	            ans = min(ans,abs(total-2*i));
	    
	    
	    
	}
// 	// recursive but TLE
// 	void recur(int pos,int arr[],int n,int total,int sum,int count)
// 	{
// 	    if(pos==n){
// 	       if(count!=n)
// 	        ans=min(ans,abs((total-sum)-sum));
// 	       return;
// 	    }
// 	    if(count==n)
// 	        return;
// 	    else
// 	       ans=min(ans,abs((total-sum)-sum));
	   
// 	   recur(pos+1,arr,n,total,sum+arr[pos],count+1);
// 	   recur(pos+1,arr,n,total,sum,count);
// 	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends