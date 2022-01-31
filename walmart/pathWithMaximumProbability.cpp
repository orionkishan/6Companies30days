class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        
        vector<vector<pair<int,double>>> adl(n);
        for(int i=0;i<edges.size();i++)
        {
            adl[edges[i][0]].push_back({edges[i][1],succ[i]});
            adl[edges[i][1]].push_back({edges[i][0],succ[i]});
        }
    
        
        queue<pair<int,double>> q;
        int curr=start;
        q.push({curr,1});
        
        vector<double> dst(n,0);
        dst[start]=1;
        
        while(!q.empty())
        {
            auto [curr,dist]=q.front();
            q.pop();
            
            for(int i=0;i<adl[curr].size();i++)
            {
                int nxt=adl[curr][i].first;
                double d=adl[curr][i].second*dst[curr];
                
                if(dst[nxt]>=d)
                    continue;
                
                dst[nxt]=d;
                q.push({nxt,d});
            }
            
        }

        return dst[end];
        
    }
    
};