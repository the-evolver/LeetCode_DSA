//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        int maxi = -1;
        for(int i = 0 ; i < n ; i++){
             maxi = max(maxi,a[i]);
        }
        
        vector<int> mapp(maxi+1,0);
        
        for(int i = 0 ; i < n ; i++){
             mapp[a[i]]++;
        }
        int sum = 0;
        for(int i = maxi ; i >= 0 ; i--){
             if(mapp[i] > 0){
                 sum += (i * mapp[i]);
                 mapp[i-1] = mapp[i-1] - mapp[i];
                 
             }
            
        }
        return sum ;
        
        
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends