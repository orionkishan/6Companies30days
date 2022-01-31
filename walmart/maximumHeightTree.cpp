// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int height(int N){
        // code here
        // int ans = 0;
        // int dots =0;
        // int i =1;
        // while(true)
        // {
        //     dots+=i;
        //     if(dots>N)
        //         break;
            
        //     i+=1;
        // }
        
        // return i-1;
        
        return (-1 +(int)sqrt(1+8*N))/2;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.height(N)<<endl;
    }
    return 0;
}  // } Driver Code Ends