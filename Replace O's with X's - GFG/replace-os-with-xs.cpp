//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
       
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        int i = 0 ,j = 0;
        
        while( j < m ){
            if(vis[i][j] == false && mat[i][j] == 'O'){
                dfs(mat,vis,i,j,n,m);
            }
            j++;
        }
        
        i = n-1;
        j = 0;
        
        while( j < m ){
            if(vis[i][j] == false && mat[i][j] == 'O'){
                dfs(mat,vis,i,j,n,m);
            }
            j++;
        }
        
        i = 0;
        j = 0;
        
        while( i < n ){
            if(vis[i][j] == false && mat[i][j] == 'O'){
                dfs(mat,vis,i,j,n,m);
            }
            i++;
        }
        
        j = m-1;
        i = 0;
         while( i < n ){
            if(vis[i][j] == false && mat[i][j] == 'O'){
                dfs(mat,vis,i,j,n,m);
            }
            i++;
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                 //cout<<vis[i][j]<<" ";
                if(vis[i][j] == false && mat[i][j] =='O')
                    mat[i][j] ='X';
            }
            //cout<<endl;
        }
        
        
        
        return mat;
        
        
    }
    void dfs(vector<vector<char>>& board , vector<vector<bool>>& vis,int i , int j , int n , int m ){
        
       
        if(i < 0 || j < 0 || i == n || j == m || board[i][j] == 'X' || vis[i][j] == true)
            return;
        
        vis[i][j] = true;
        dfs(board,vis,i-1,j,n,m);
        dfs(board,vis,i+1,j,n,m);
        dfs(board,vis,i,j-1,n,m);
        dfs(board,vis,i,j+1,n,m);
        
        
        
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends