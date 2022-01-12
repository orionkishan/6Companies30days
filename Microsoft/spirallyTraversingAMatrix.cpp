// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int top = 0;
        int bottom = r-1;
        int left = 0;
        int right = c-1;
        
        
        while(top<=bottom and left<=right and ans.size()<=r*c)
        {
            for(int i = left;i<=right;i+=1)
                ans.push_back(matrix[top][i]);
            top+=1;
            
            for(int j=top;j<=bottom;j+=1)
                ans.push_back(matrix[j][right]);
            right-=1;
            
            for(int i = right;top<=bottom and i>=left;i-=1)
                ans.push_back(matrix[bottom][i]);
            bottom-=1;
            
            for(int j=bottom;left<=right and j>=top;j-=1)
                ans.push_back(matrix[j][left]);
            left+=1;
        }
        return ans;
    }
};

// 1 2 3
// 4 5 6
// 7 8 9
// 1 2 3
// 4 5 6
// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends