class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
        if(n<=2)
            return 0;
        
        vector<int> l(n,0);
        vector<int> r(n,0);
        
        for(int i=1;i<n-1;i+=1)
        {
            if(arr[i]>arr[i-1])
                l[i] = l[i-1]+1;
            
        }
        
        for(int i=n-2;i>0;i-=1)
        {
            if(arr[i]>arr[i+1])
                r[i] = r[i+1]+1;
            
        }
        
        int ans =0;
        for(int i =0;i<n;i+=1)
            if(l[i] and r[i])
                ans = max(ans,l[i]+r[i]+1);
        
        return ans;
    }
};

// 2 1 4 7 3 2 5
// 0 0 1 2 0 0 1
// 0 0 0 2 1 0 0