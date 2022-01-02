// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

#define ull unsigned long long
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
        
        if(k<=1)
            return 0;
        
        ull p = 1;
        int ans = 0;
        int i = 0;
        int j = 0;
        while(j<n)
        {
            p*=a[j];
            
            while(p>=k){
                p/=a[i];
                i+=1;
            }
            
            ans += j-i+1;
            j+=1;
        }
        
        return ans;
        
        
    }
};


// 1 2 3 4 
// 1 2 6 24

// 1 9 2 8 6 4 3
// 1 9 18 144 864 3456 10368
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends