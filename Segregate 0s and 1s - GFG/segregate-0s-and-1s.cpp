//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        // code here
        
        int j = 0 , i = 0;
        
        // [0 - j - 1] --> 0th zone
        // [j - i - 1] --> 1th zone
        // [1 - end  ] --> unknowns
        
        for(; i < n ; ){
            if(arr[i] == 1){
                i++;
                
            }else{
                swap(arr[j],arr[i]);
                j++;
                i++;
                
            }
        }
        return;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregate0and1(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends