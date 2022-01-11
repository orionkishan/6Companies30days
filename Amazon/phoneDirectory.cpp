// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
struct node
{
    bool isEnd=false;
    node* letters[26]={nullptr};
};
class trie
{   
    public:
        node* head = new node();    
        
        void insert(string contact)
        {
            node* temp = head;
            for(auto c:contact)
            {
                if(!temp->letters[c-'a'])
                    temp->letters[c-'a']=new node();
                
                temp = temp->letters[c-'a'];
                
            }
            
            temp->isEnd = true;
        }
        
        vector<string> search(string str)
        {
            vector<string> ans;
            string prefix(str);
            node* temp = head;
            for(auto c:str)
            {
                if(!temp->letters[c-'a'])
                    return ans;
                    
                else
                    temp = temp->letters[c-'a'];
            }
            
            recur(temp,prefix,ans);
            return ans;
        }
        
        void recur(node* temp,string &curr,vector<string>& ans)
        {
            if(!temp)
                return;
                
            if(temp->isEnd)
                ans.push_back(curr);
                
            
            for(int i =0;i<26;i+=1)
            {
                curr+='a'+i;
                recur(temp->letters[i],curr,ans);
                curr.pop_back();
            }
            
            
        }
    
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        trie t;
        for(int i =0;i<n;i+=1)
        {
            t.insert(contact[i]);
        }
        
        vector<vector<string>> ans;
        
        string pre="";
        bool flag = false;
        for(auto c:s)
        {   
            if(flag){
                ans.push_back({"0"});
                continue;
            }
            pre+=c;
            auto v = t.search(pre);
            if(v.empty()){
                ans.push_back({"0"});
                flag=true;
                
            }
            
            else
                ans.push_back(v);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends