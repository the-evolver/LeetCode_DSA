//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        
        set< vector<pair<int,int>> > st;
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == false ){
                    vector<pair<int,int>> v ;
                    dfs(grid,vis,i,j,n,m,v,i,j);
                    st.insert(v);
                }
            }
        }
        
        return st.size();
        
        
        
        
    }
    void dfs(vector<vector<int>>& grid ,vector<vector<bool>>& vis ,int i , int j , int row , int col , vector<pair<int,int>>& v , int base_i , int base_j){
        
        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] != 1 || vis[i][j] == true)
             return;
             
             
        v.push_back({i-base_i,j-base_j});
        vis[i][j] = true;
        
           dfs(grid,vis,i-1,j,row,col,v,base_i,base_j);
           dfs(grid,vis,i+1,j,row,col,v,base_i,base_j);
           dfs(grid,vis,i,j-1,row,col,v,base_i,base_j);
           dfs(grid,vis,i,j+1,row,col,v,base_i,base_j);
        
        
        
        
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