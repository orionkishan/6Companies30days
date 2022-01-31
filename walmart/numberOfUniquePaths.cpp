// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>> mat(a,vector<int>(b,0));
        
        for(int i=0;i<a;i+=1)
            mat[i][0]=1;
        for(int i=0;i<b;i+=1)
            mat[0][i]=1;
            
        for(int i=1;i<a;i+=1)
            for(int j=1;j<b;j+=1)
                mat[i][j]+=mat[i-1][j]+mat[i][j-1];
        
        return mat[a-1][b-1];
    }
    
    
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends