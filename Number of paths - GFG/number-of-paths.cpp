//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
long long  numberOfPaths(int m, int n)
{
    // Code Here
    long long int arr[m][n];
    for(int i = 0 ; i < m ; i++){
        arr[i][0] = 1;
    }
     for(int i = 0 ; i < n ; i++){
        arr[0][i] = 1;
    }
    
    
    for(int i = 1 ; i < m ; i++){
        for(int j = 1 ; j < n ; j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    return arr[m-1][n-1];
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends