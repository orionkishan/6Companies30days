// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
unordered_map<int,vector<int>> adl;
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    
	    for(auto p:pre)
	        adl[p.first].push_back(p.second);
	        
	   vector<bool> current(N,false);
	   vector<bool> visited(N,false);
	   
	   
	   for(int node=0;node<N;node+=1)
	        if(!visited[node] and dfs(N,current,visited,node))
	            return false;
	   
	  
	    return true;
	}
	
	bool dfs(int N,vector<bool> &current,vector<bool>&visited,int node)
	{
	    if(visited[node])
	        return false;
	        
	   current[node]=true;
	   visited[node]=true;
	   
	   for(auto n:adl[node])
	        if(current[n] or dfs(N,current,visited,n))
	            return true;
	    
	  current[node]=false;
	  return false;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends