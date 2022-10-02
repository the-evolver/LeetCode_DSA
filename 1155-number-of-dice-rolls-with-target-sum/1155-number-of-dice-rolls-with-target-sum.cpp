class Solution {
public:
    int m = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        
       // vector<vector<unsigned long long >>dp(n+1,vector<unsigned long long>(max(target,k)+1,-1));
        //return solve(n,k,target,dp);
        
        vector<vector<int>> dp(n+1,vector<int>(max(k,target) + 1 , 0));
        dp[0][0] = 1 ; // dice bhi 0 and  target bhi 0 
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= target ; j++){
                 //
                int ans = 0;
                for(int f = 1 ; f <= k ; f++){
                    if(j - f >= 0)
                    ans = (ans % m + dp[i-1][j-f] % m ) % m;
                 }
                 dp[i][j] = ans;
                //
            }
        }
        return dp[n][target];
        
        
        
    }
    int solve(int dice , int face , int tar,vector<vector<unsigned long long>>& dp){
        
        if(tar < 0)
            return 0;
        
        if(tar == 0 && dice != 0 ||  dice == 0 && tar != 0 )
            return 0;
        
        if(tar == 0 && dice == 0)
            return 1;
        
        if(dp[dice][tar] != -1 )
            return dp[dice][tar];
        
        unsigned long long ans = 0;
        for(int i = 1 ; i <= face ; i++){
            ans = (ans % m + solve(dice-1,face,tar-i,dp) % m ) %m;
        }
        return dp[dice][tar] = ans;
    }
};