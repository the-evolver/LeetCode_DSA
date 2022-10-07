class Solution {
public:
    int m = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        
         return helper(n,k,target,dp);
        
       
        
    }
    int helper(int dice , int faces , int target,vector<vector<int>>& dp){
        if(target < 0 )
            return 0;
        if(target == 0 && dice > 0)
            return  dp[dice][target] = 0;
        if(dice == 0 && target > 0)
            return  dp[dice][target] = 0;
        if(dice == 0 && target == 0)
            return  dp[dice][target] = 1;
        
        if(dp[dice][target] != -1)
            return dp[dice][target];
        
        int sum = 0;
        for(int i = 1 ; i <= faces ; i++){
            if(dice - 1 >= 0 && target-i >= 0){
            dp[dice-1][target-i] = helper(dice-1,faces,target-i,dp) % m ;
            sum =  (sum % m + dp[dice-1][target-i] % m ) % m;
          }
            
        }
             //sum =  (sum % m + helper(dice-1,faces,target-i,dp) % m ) % m;
        
        return  dp[dice][target] = sum;
    }
};