// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string ans ="";
  
  char last = src[0];
  int count = 1;
  int i = 1;
  while(i<src.length())
  {   
      if(src[i]!=last)
      {
          ans+=last+to_string(count);
          count = 1;
          last = src[i];
      }
      else
        count+=1;
        
    i+=1;
      
  }
  
  ans+=last+to_string(count);
  return ans;
}     
 
