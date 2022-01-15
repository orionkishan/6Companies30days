// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int ans;
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool> visited(V,false);
        ans=1;
        // for(int i=0;i<V;i+=1){
        //     for(int j = 0;j<adj[i].size();j+=1)
        //         cout<<adj[i][j]<<" ";
            
        //     cout<<endl;
            
        // }
        

        dfs(V,adj,visited,c,d,c);
        
        return ans;
    }
    
    void dfs(int V,vector<int> adj[],vector<bool> &visited,int c,int d,int node)
    {
        if(node==d){
            ans=0;
            return;
        }
        
        visited[node]=true;
        for(auto n:adj[node])
        {
            if((n==c and node==d)or(n==d and node==c) or visited[n])
                continue;
            
            dfs(V,adj,visited,c,d,n);
            
        }
        
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends