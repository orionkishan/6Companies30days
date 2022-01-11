// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        int rows[9][9]={0},cols[9][9]={0},cells[9][9]={0};
        
        for(int i = 0;i<mat.size();i+=1)
        {
            for(int j=0;j<mat[0].size();j+=1)
            {
                if(!mat[i][j])
                    continue;
                    
                int cell = (i/3)*3+j/3;
                int val = mat[i][j]-1;
                if(rows[i][val] or cols[j][val] or cells[cell][val])
                    return false;
                
                rows[i][val] = 1;
                cols[j][val] = 1;
                cells[cell][val] = 1;
                
                
            }
            
        }
        
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends