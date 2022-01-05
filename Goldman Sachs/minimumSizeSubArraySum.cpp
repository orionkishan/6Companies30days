class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        // prefix sum
        vector<int> ps(n+1,0);
        
        
        for(int i =0;i<n;i+=1)
            ps[i+1] = ps[i]+nums[i];
        
        
        int ans = INT_MAX;
        int i = -1;
        int j = 0;
        
        
        while(j<n)
        {
            // if current window sum
            // greater than equal to target
            // decrease the window(i+=1)
            if(ps[j+1]-ps[i+1]>=target){
                ans=min(ans,j-i);
                i+=1;
            }
            
            // else increase the window
            // (j+=1)
            else
            {
                j+=1;
            }
  
        }
        return ans==INT_MAX?0:ans;
    }
};