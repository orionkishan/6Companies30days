// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()%2)
            return false;
            
    
        unordered_map<int,int> ump;
        
        for(auto i:nums)
            ump[i%k]+=1;
        
        
        for(auto i:nums)
        {
            
            int r = i%k;
            
            if(2*r==k)
            {
                if(ump[r]%2)
                    return false;
            }
            
            else if(!r)
            {
                if(ump[r]%2)
                    return false;
            }
            else if(ump[r]!=ump[k-r])
                return false;
            
        }
        
        return true;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends