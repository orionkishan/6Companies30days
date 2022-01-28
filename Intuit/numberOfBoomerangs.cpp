class Solution {
public:
int numberOfBoomerangs(vector<vector<int>>& points) {
    
    int res = 0;

    for (int i = 0; i < points.size(); ++i) {
        
        unordered_map<long, int> dist;
  
        for (int j = 0; j < points.size(); j+=1) {
            
            if (j == i) continue;
            
            int dy = points[i][1] - points[j][1];
            int dx = points[i][0] - points[j][0];
            int key = dy*dy+dx*dx;
            dist[key]+=1;
        }
        
        for (auto& p : dist) {
            if (p.second > 1) {
                res += p.second * (p.second - 1); //nc2
            }
        }
    }
    
    return res;
}
};