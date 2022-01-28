// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int m,n;
    vector<int> row={1,-1,0,0};
    vector<int> col={0,0,1,-1};
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        m=board.size();
        n=board[0].size();
        
     
        for(int i=0;i<m;i+=1)
        {   
            for(int j=0;j<n;j+=1)
            {
                if(board[i][j]==word[0] and dfs(board,word,0,i,j))
                    return true;
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board,string &word,int pos,int i,int j)
    {
        if(pos==word.length())
            return true;
        
        if(i>=m or i<0 or j>=n or j<0)
            return false;
  
        if(board[i][j]!=word[pos])
            return false;
        
        char temp=board[i][j];
        board[i][j]='#';
        for(int k=0;k<4;k+=1)
        {   
            if(dfs(board,word,pos+1,i+row[k],j+col[k]))
                return true;
        }
        board[i][j]=temp;
        
        return false;
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends