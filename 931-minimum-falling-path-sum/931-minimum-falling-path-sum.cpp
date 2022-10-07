class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) { 
        
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i = 0 ; i < n ; i++){
            dp[0][i] = matrix[0][i];
        }
        
        for(int i = 1 ; i < n ; i++){
             for(int j = 0 ; j < n ; j++){
                 
                 int v1 = (i-1>= 0 && j >= 0) ? dp[i-1][j] + matrix[i][j] : INT_MAX;
                 int v2 = (i-1 >= 0 && j-1 >= 0) ? dp[i-1][j-1] + matrix[i][j] : INT_MAX;
                 int v3 = (i-1 >= 0 && j+1 < n) ? dp[i-1][j+1] + matrix[i][j] : INT_MAX;
                 dp[i][j] = min(v1,min(v2,v3));
                 
             }
        }
        
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++)
             ans = min(ans,dp[n-1][i]);
        
        return ans;
        
        
        
    }
};