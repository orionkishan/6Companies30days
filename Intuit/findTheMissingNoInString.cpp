// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
long long stoi(string &s)
{
    long long x=0;
    for(int i=0;i<s.size();i++)
      x=x*10+s[i]-'0';
    return x;
}
int missingNumber(const string& s)
{
    int n=s.size();
    for(int len=1;len<=6;len++)
    {
       string temp="";
       int l=len,i=0;
       while(i<s.size()&&l--)
        temp+=s[i++];
       long long prev=stoi(temp),count=0,j=i,miss,flag=0;
       temp="";
       while(j<s.size())
       {
               temp+=s[j++];
               long long next = stoi(temp);
               if(prev+1==next)
               {
                   prev=next;
                   temp="";
               }
               else if(prev+2==next)
                {
                        count++;
                        miss=prev+1;
                        prev=next;
                        temp="";
                }
                else if(prev<next)
                    flag=1;
        }
        if(count==1&&flag==0)
         return miss;
    }
    return -1;
}