// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<char> st;
        
        for(int i = 0;i<s.length();i+=1)
        {
            if(s[i]==']')
            {
                string temp = "";
                
                while(!st.empty() and st.top()!='[')
                {
                    temp = st.top() + temp;
                    st.pop();
                }
                
                st.pop();
                
                string times = "";
                while(!st.empty() and st.top()>='0' and st.top()<='9'){
                    times = st.top() + times;
                    st.pop();
                    
                }                    
                
                string r = "";
                for(int i =0;i<stoi(times);i+=1)
                {
                    r+=temp;
                }
                for(int i = 0;i<r.length();i+=1)
                    st.push(r[i]);
                
            }
            
            else
                st.push(s[i]);
            
            
            
        }
        
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends