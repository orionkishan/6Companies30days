class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int sum = 0;
        for(auto i:weights)
            sum+=i;
        
        int ans = sum;
        int low = 1;
        int high = sum;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            if(isValid(weights,days,mid))
            {
                ans=min(ans,mid);
                high = mid-1;
            }
            else
            {
                low=mid+1;
            }
            
            
        }
        
        return ans;
    }
    
    bool isValid(vector<int> &weights,int days,int cap)
    {
        int d = 0;
        int p = 0;
        
        for(int i =0;i<weights.size();i+=1)
        {   
            if(weights[i]>cap)
                return false;
            
            p+=weights[i];
            if(p>cap)
            {
                p=weights[i];
                d+=1;
            }
            
        }
        
        if(p<=cap)
            d+=1;

        return d<=days;
 
    }
};