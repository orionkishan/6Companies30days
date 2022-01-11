// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    
		string FirstNonRepeating(string A){
		    // Code here
		    int i =0;
		    vector<int> count(26,0);
		    
		    string ans ="";
		    for(int j = 0;j<A.length();j+=1)
		    {
		        count[A[j]-'a']+=1;
		        while(i<A.length() and count[A[i]-'a']>1)
		            i+=1;
		        
		        if(i<=j and count[A[i]-'a'])
		            ans+=A[i];
		        else
		            ans+="#";
		        
		    }
		    
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends