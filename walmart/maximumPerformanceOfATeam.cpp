class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b)
    {
        return a.first>b.first;
        
    }
    int maxPerformance(int n, vector<int>& sp, vector<int>& ef, int k) {
        
        long long mod  = 1e9+7;
        vector<pair<int,int>> e;
        for(int i = 0;i<n;i+=1)
            e.push_back({ef[i],sp[i]});
        
        sort(e.begin(),e.end(),cmp);
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long long sum=0;
        long long ans=0;
        for(auto p:e)
        {
            sum+=p.second;
            pq.push(p.second);
            while(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            
            ans = max(ans,p.first*sum);
            
        }
        
        return ans % mod;
    }
};
// S=[2,10,3,1,5,8]
// E=[5,4,3,9,7,2] 
// S=[1,5,2,10,3,8]
// E=[9,7,5,4,3,2]
