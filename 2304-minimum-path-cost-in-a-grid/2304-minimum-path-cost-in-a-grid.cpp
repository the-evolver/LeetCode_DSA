class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i = 0 ; i  < n ; i++)
            dp[0][i] = grid[0][i];
        
        for(int i = 1 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                
                 int mini = INT_MAX;
                 for(int k = 0 ; k < n ; k++){
                     mini = min(mini,dp[i-1][k] + moveCost[grid[i-1][k]][j] + grid[i][j]);
                 }
                 dp[i][j] = mini;
            }
        }
        
        int mini = INT_MAX;
        for(int j = 0 ; j < n ; j++)
             mini = min(mini,dp[m-1][j]);
        
        return mini;
        
    }
};