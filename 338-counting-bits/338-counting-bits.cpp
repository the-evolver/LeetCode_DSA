class Solution {
public:
    vector<int> countBits(int n) {
        
        // logic ::: ) 
        //  .. if for any number x we can get it by x/2 (even) or x/2 + 1 (odd)
        
        vector<int>dp(n+1,0);
      
        for(int i = 1 ; i <= n ; i++){
             dp[i] = dp[i/2] +(i % 2);
        }
        
        return dp;
        
    }
};