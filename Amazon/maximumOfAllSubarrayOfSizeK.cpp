// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<k;i+=1)
            pq.push({arr[i],i});
            
        vector<int> ans;
        
        ans.push_back(pq.top().first);
        
        for(int i =k;i<n;i+=1)
        {
            pq.push({arr[i],i});
            
            auto top = pq.top();
            
            if(top.second>=ans.size() and top.second<=ans.size()+k)
            {
                ans.push_back(top.first);
            }
            else
            {
                pq.pop();
                i-=1;
            }
            
            
            
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends