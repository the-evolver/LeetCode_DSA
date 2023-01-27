//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
         
         int n = grid.size();
         int m = grid[0].size();
         set<vector<pair<int,int>>> ans;
         
         vector<vector<bool>> vis(n,vector<bool>(m,false));
         
         for(int i = 0 ; i < n ; i++){
             for(int j = 0 ; j < m ; j++){
                 
                 if(vis[i][j] == false && grid[i][j] == 1){
                     vector<pair<int,int>> v;
                     dfs(grid,vis,i,j,n,m,i,j,v);
                     ans.insert(v);
                 }
                 
             }
         }
         
         
         return ans.size();
         
         
    }
    
    
    void dfs(vector<vector<int>>& grid , vector<vector<bool>>& vis ,int i , int j , int row , int col ,int base_i,int base_j,vector<pair<int,int>>& v){
        
         if( i < 0 || i == row || j < 0 || j == col || grid[i][j] == 0 || vis[i][j] == true)
              return;
              
              vis[i][j] = true;
              v.push_back({i-base_i,j-base_j});
              dfs(grid,vis,i-1,j,row,col,base_i,base_j,v);
               dfs(grid,vis,i+1,j,row,col,base_i,base_j,v);
                dfs(grid,vis,i,j-1,row,col,base_i,base_j,v);
                 dfs(grid,vis,i,j+1,row,col,base_i,base_j,v);
             
        
    }
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends