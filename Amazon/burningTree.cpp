// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    unordered_map<int,vector<int>> adl;
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        buildADL(root);
        return bfs(target);
    }
    
    void buildADL(Node* root)
    {
        if(!root)
            return;
            
        if(root->left){
            adl[root->data].push_back(root->left->data);
            adl[root->left->data].push_back(root->data);
        }   
        
        if(root->right){
            adl[root->data].push_back(root->right->data);
            adl[root->right->data].push_back(root->data);
        }    
        
        buildADL(root->left);
        buildADL(root->right);
    }
    
    int bfs(int target)
    {   
        if(adl.find(target)==adl.end())
            return 0;
            
        int ans = 0;
        unordered_set<int> burnt;
        queue<pair<int,int>> q;
        q.push({target,0});
        
        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            burnt.insert(f.first);
            ans = max(ans,f.second);
            
            for(auto i:adl[f.first])
            {
                if(burnt.find(i)!=burnt.end())
                    continue;
                
                q.push({i,f.second+1});
            }
            
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends