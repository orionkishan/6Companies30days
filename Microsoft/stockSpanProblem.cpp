// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int> st;
       vector<int> ans(n,1);
       
       st.push(0);
       
       for(int i =1;i<n;i+=1)
       {
            if(price[i]<price[st.top()])
                st.push(i);
            else
            {
                int c = 0;
                while(!st.empty() and price[st.top()]<=price[i])
                {
                    c+=ans[st.top()];
                    st.pop();
                }
                st.push(i);
                ans[i]+=c;
                
            }
        }
        
        return ans;
        
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends