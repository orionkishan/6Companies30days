class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        
        int low=1;
        int high=INT_MAX;
        int ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPoss(piles,h,mid))
            {
                ans=mid;
                high=mid-1;
            }
            
            else
            {
                low=mid+1;
                    
            }

            
        }
        
        return ans;
        
        
    }
    
    bool isPoss(vector<int> &piles,int h,int k)
    {
        int hours=0;
        for(int p:piles)
        {
            hours+=(p-1)/k +1;
        
        }

        return hours<=h;
    }
};