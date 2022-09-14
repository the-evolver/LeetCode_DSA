class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return recur(n-1,m-1,word1,word2,dp);
        for(int i = 0 ; i <=n ; i++)dp[i][0] = i;
        for(int j = 0 ; j <=m ; j++)dp[0][j] = j;
        
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
               
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(1 + dp[i][j-1],
                  min(1 + dp[i-1][j-1],1 + dp[i-1][j]));
        

                }
        
                
                
            }
        }
        
        return dp[n][m];
    }
    
    int recur(int i , int j , string &s1 , string &s2,vector<vector<int>>&dp){
        
        if(i < 0){
           
            return j+1;
        }  
        if(j < 0 ){
           
            return i+1;
        } 
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s1[i] == s2[j]){
            
            return dp[i][j] = recur(i-1,j-1,s1,s2,dp);
        }
            
        
        return dp[i][j] = min(1 + recur(i,j-1,s1,s2,dp),
                  min(1 + recur(i-1,j-1,s1,s2,dp),1 + recur(i-1,j,s1,s2,dp)));
        
        
    }
};