// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> ans;
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> keys ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string curr;
        recur(a,N,0,keys,curr);
        return ans;
    }
    
    void recur(int a[],int N,int pos,vector<string> &keys,string& curr)
    {
        if(pos==N)
        {
            ans.push_back(curr);
            return;
        }
        
        
        for(int j=0;j<keys[a[pos]].length();j+=1)
        {
            curr+=keys[a[pos]][j];
            recur(a,N,pos+1,keys,curr);
            curr.pop_back();
        }
        
    
        
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends