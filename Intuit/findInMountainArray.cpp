/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        int n = m.length();
        
        int l = 0;
        int h = n-1;
        int mid = l+(h-l)/2;
        while(l<=h)
        {
            mid = l+(h-l)/2;
            if(mid==0 or mid==n-1)
                break;
            int vmid=m.get(mid);
            int vmid1=m.get(mid-1);
            int vmid2=m.get(mid+1);
            if(vmid>max(vmid1,vmid2))
                break;
            else if(vmid>vmid1)
                l = mid+1;
            else if(vmid>vmid2)
                h = mid-1;

        }
        
        int left = bs(target, m,0,mid);
        if(left!=-1)
            return left;
        int right = bs1(target,m,mid+1,n-1);
        if(right!=-1)
            return right;
        
        return -1;
        
        
    }
    
    int bs(int target, MountainArray &m,int l,int h)
    {
        int mid = l+(h-l)/2;
        
        while(l<=h)
        {   
            mid = l+(h-l)/2;
            int vmid = m.get(mid);
            if(vmid==target)
                return mid;
            else if(vmid>target)
                h = mid-1;
            else
                l = mid+1;
        }
        
        return -1;
        
        
    }
    int bs1(int target, MountainArray &m,int l,int h)
    {
        int mid = l+(h-l)/2;
        
        while(l<=h)
        {   
            mid = l+(h-l)/2;
            int vmid = m.get(mid);
            if(vmid==target)
                return mid;
            else if(vmid<target)
                h = mid-1;
            else
                l = mid+1;
        }
        
        return -1;
        
        
    }
};