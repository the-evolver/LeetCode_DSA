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
         int row = n;
         int col = m;
         vector<vector<bool>>vis(row,vector<bool>(col,false));
         
         queue<pair<int,int>> qu;
         
         for(int i = 0 ; i < row ; i++){
             for(int j = 0 ; j < col ; j++){
                 if(mat[i][j] == 'O' &&(i == 0 || j == 0 || i == row -1 || j == col-1)){
                    qu.push({i,j});
                    vis[i][j] = true;
                 }
                 
             }
         }
         
         while(qu.size() > 0){
             pair<int,int> pa_ir = qu.front();
             qu.pop();
             int i = pa_ir.first;
             int j = pa_ir.second;
             
             
             if(i-1 >= 0 && vis[i-1][j] == false && mat[i-1][j] == 'O'){
                 vis[i-1][j] = true;
                 qu.push({i-1,j});
             }
             if(i+1 < row && vis[i+1][j] == false && mat[i+1][j] == 'O'){
                 vis[i+1][j] = true;
                 qu.push({i+1,j});
             }
             if(j-1 >= 0 && vis[i][j-1] == false && mat[i][j-1] == 'O'){
                 vis[i][j-1] = true;
                 qu.push({i,j-1});
             }
             if(j+1 <= col && vis[i][j+1] == false && mat[i][j+1] == 'O'){
                 vis[i][j+1] = true;
                 qu.push({i,j+1});
             }
             
             
         }
         
         for(int i = 0 ; i < row ; i++){
             for(int j = 0 ; j < col ; j++){
                 if(vis[i][j] == false){
                     mat[i][j] = 'X';
                 }
             }
         }
         
         return mat;
         
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