class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i = 0 ; i < n ; i++){
            dp[0][i] = grid[0][i];
        }
        
        for(int i = 1 ; i < n ; i++){
             for(int j = 0 ; j < n ; j++){
                 
                 //int v1 = (i-1>= 0 && j >= 0) ? dp[i-1][j] + matrix[i][j] : INT_MAX;
                 int val = INT_MAX;
                 for(int k = 0 ; k < n && i-1 >= 0; k++){
                      if(k == j )
                          continue;
                     
                     val = min(val,dp[i-1][k] + grid[i][j]);
                     
                 }
                 dp[i][j] = val;
                 
             }
        }
        
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++)
             ans = min(ans,dp[n-1][i]);
        
        return ans;
        
        
    }
};