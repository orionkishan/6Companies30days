class Solution {
public:
    vector<int> ans;
    vector<int> findOrder(int nums, vector<vector<int>>& pre) 
    {
    
        vector<vector<int>> adm(nums,vector<int>(nums,0));
        
        for(int i=0;i<pre.size();i++)
            adm[pre[i][1]][pre[i][0]]=1;
        
        if(cycle(adm,nums))
            return {};
        
        vector<bool> visited(nums,false);
        for(int i=0;i<nums;i++)
            cs2fun(i,adm,visited);
        
        reverse(ans.begin(),ans.end());
        return ans;
     
    }
    
    void cs2fun(int v,vector<vector<int>>&adm,vector<bool> &visited)
    {
        if(!visited[v])
        {   
            visited[v]=true;
            for(int i=0;i<adm[v].size();i++)
            {
                if(adm[v][i])
                    cs2fun(i,adm,visited);
            }
        ans.push_back(v);
        }
        
    }    
    
    
    bool cycle(vector<vector<int>> &adm,int n)
    {
        vector<int> visited(n,false);
        vector<int> recSt(n,false);
    
        for(int i=0;i<n;i++)
            if(cycleUtil(i,adm,visited,recSt))
                return true;
    
        return false;
    }
    
    bool cycleUtil(int v, vector<vector<int>> &adm,vector<int> &visited,vector<int> &recSt)
    {
        if(visited[v] == false)
        {
            visited[v] = true;
            recSt[v] = true;
        
            for(int i=0; i< adm[v].size(); i++)
            {   
                if(adm[v][i])
                {
                    if ( !visited[i] && cycleUtil(i, adm,visited, recSt) )
                        return true;
                    else if (recSt[i])
                        return true;
                
                }
                
            }
 
        }
        recSt[v] = false; 
        return false;
        
    
    }
};