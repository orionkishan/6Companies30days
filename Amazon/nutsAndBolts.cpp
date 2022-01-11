// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
// 5
// 1 2 3 4 5
// 1 2 4 3 5
    
//     4 2 1 3 5 
//     4 1 5 3 2 
    int partition(char a[],int low,int high,char pivot)
    {
        int i = low;
        for(int j = low;j<high;j+=1)
        {
            if(a[j]<pivot)
            {
                swap(a[i],a[j]);
                i+=1;
            }
            else if(a[j]==pivot){
                swap(a[j],a[high]);
                j--;
            }
        }
        
        swap(a[i],a[high]);

        return i;
        
    }
    
    void qSort(char nuts[], char bolts[], int low,int high)
    {
        if(low<high)
        {
            int pivot = partition(nuts,low,high,bolts[high]);
            partition(bolts,low,high,nuts[pivot]);
            
            qSort(nuts,bolts,low,pivot-1);
            qSort(nuts,bolts,pivot+1,high);

        }
        
    }
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    qSort(nuts,bolts,0,n-1);
	}

};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends