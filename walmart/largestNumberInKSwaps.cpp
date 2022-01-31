// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       string ans=str;
       recur(str,0,k,ans);
       return ans;
    }
    
    void recur(string &str,int pos,int k,string &ans)
    {
        if(!k){
            return;
        }
        char m = str[pos];
        for(int i =pos+1;i<str.length();i+=1)
        {
            m=max(m,str[i]);
        }
        
        if(m!=str[pos])
            k--;
        
        
        for(int i=str.length()-1;i>=pos;i--)
        {
            if(m==str[i])
            {
                swap(str[i],str[pos]);
                if(str.compare(ans)>0)
                    ans=str;
                recur(str,pos+1,k,ans);
                swap(str[i],str[pos]);
            }
                
        }
        
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends