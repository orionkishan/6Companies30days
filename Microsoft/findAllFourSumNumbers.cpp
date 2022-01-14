// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    
    vector<vector<int> > fourSum(vector<int> &nums, int K) {
        // Your code goes here
        int n=nums.size();
        if(n<4)
            return {};
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < n-3; i+=1)
        {   
            // 2 3 4 5 7 8 10
            // 0 0 1 1 2
            for(int j=i+1;j<n-2;j+=1)
            {   
                
                int s = nums[i]+nums[j];
                int d = K-s;
                int k = j + 1, l = n - 1; //2 pointers
                while(k < l) //nums[j] + nums[k] should be equal to -nums[i](target)
                {
                    if(nums[k] + nums[l] > d) --l;
                    else if(nums[k] + nums[l] < d) ++k;
                    else
                    {   
                        ans.push_back({nums[i], nums[j], nums[k++],nums[l--]});
                        while(k<l and nums[k]==nums[k-1]) k+=1;
                        while(k<l and nums[l]==nums[l+1]) l-=1;
                    }
                    
                }
                
                while(j<n and nums[j]==nums[j+1]) j+=1;
                
            }
            
            while(i<n and nums[i]==nums[i+1]) i+=1;
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends