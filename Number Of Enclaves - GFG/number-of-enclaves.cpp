//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        
         int row = grid.size();
         int col = grid[0].size();
         
         vector<vector<bool>> vis(row,vector<bool>(col,false));
         
         queue<pair<int,int>> qu;
         
         for(int i = 0 ; i < row ; i++){
              if(grid[i][0] == 1){
                  vis[i][0] = true;
                  qu.push({i,0});
              }
              if(grid[i][col-1] == 1){
                  vis[i][col-1] = true;
                  qu.push({i,col-1});
              }
         }
         for(int j = 0 ; j < col ; j++){
              if(grid[0][j] == 1){
                  vis[0][j] = true;
                  qu.push({0,j});
              }
              if(grid[row-1][j] == 1){
                  vis[row-1][j] = true;
                  qu.push({row-1,j});
              }
         }
         
         while(qu.size() > 0){
             
             auto it = qu.front();
             qu.pop();
             
             int i = it.first,j = it.second;
             
             if(i-1 >= 0 && grid[i-1][j] == 1 && vis[i-1][j] == false){
                 vis[i-1][j] = true;
                 qu.push({i-1,j});
                 
             }
             if(i+1 < row && grid[i+1][j] == 1 && vis[i+1][j] == false){
                 vis[i+1][j] = true;
                 qu.push({i+1,j});
                 
             }
             if(j-1 >= 0 && grid[i][j-1] == 1 && vis[i][j-1] == false){
                 vis[i][j-1] = true;
                 qu.push({i,j-1});
                 
             }
             if(j+1 < col && grid[i][j+1] == 1 && vis[i][j+1] == false){
                 vis[i][j+1] = true;
                 qu.push({i,j+1});
                 
             }
             
             
             
             
         }
         
         int ans = 0;
         for(int i = 0 ; i < row ; i++){
             for(int j = 0 ; j < col ; j++){
                 if(grid[i][j] == 1 && vis[i][j] == false)
                  ans++;
             }
         }
         
         
        
        return ans;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends