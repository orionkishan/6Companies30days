// Problem: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/#

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans; // answer vector
        // map that stores at what index in answer vector
        // the anagram should be grouped
        // Two anagrams have same sorted sequence
        // and hence it is used as a key for the map
        unordered_map<string,int>ump; 
        for(auto i:string_list)
        {
            string temp(i);
            sort(temp.begin(),temp.end());
            
            
            if(ump.find(temp)==ump.end())
            {
                ans.push_back({i});
                ump[temp] = ans.size()-1;
                
            }
            else
                ans[ump[temp]].push_back(i);
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
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends