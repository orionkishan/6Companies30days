// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    
    int minSteps(int D){
        // code here
        D=abs(D);
        int steps=0;
        long long pos=0;
        
        while(true)
        {
            steps+=1;
            pos+=steps;
            
            if(pos==D)
                return steps;
                
            else if((pos>D) and !((pos-D)%2))
                    return steps;
            
        }
        
        return 0;
    }
    
    
        
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends