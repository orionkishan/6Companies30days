// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    
    string printMinNumberForPattern(string S){
        // code here 
        int n = S.length();
        string ans="";

        // for an n length S ans will be n+1 length String
        // of numbers 1 to n+1 as all digits must be unique
        for(int i =1;i<=n+1;i+=1)
            ans+=to_string(i);
        
        // We simply need to reverse the string
        // which corresponds to sequence of 'D' chars
        for(int i =0;i<n;i+=1)
        {
            if(S[i]=='D')
            {
                int j =i+1;
                while(j<n and S[j]=='D')
                    j+=1;
                    
                reverse(ans.begin()+i,ans.begin()+j+1);
                i=j;
            }
            
        }
    
        return ans;
        
    }
    
    
    
    
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends