class Solution {
public:
    struct cmp{
        bool operator()(string &a,string &b)
        {
            if(a.length()==b.length())
            {
                for(int i=0;i<a.length();i+=1)
                {
                    if(a[i]==b[i])
                        continue;
                    
                    else
                        return a[i]<b[i];
                    
                }
                
            }
            
            return a.length()<b.length();
            

        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<string,vector<string>,cmp> pq;
        
        for(auto i:nums)
            pq.push(i);
        
        string ans;
        while(!pq.empty() and k)
        {   
            ans=pq.top();
            pq.pop();
            k-=1;
        }
        
        return ans;
    }
};