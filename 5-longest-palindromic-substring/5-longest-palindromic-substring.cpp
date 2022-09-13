class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        int max_len = 0;
        int st = -1 , en = -1;
        
        for(int g = 0 ; g < n ; g++){
            for(int i = 0 , j = g ; j < n ; j++,i++){
                 if(g == 0){
                      dp[i][j] = true;
                      if(max_len < 1){
                          max_len = 1;
                          st = i;
                          en = j;
                      }
                 }
                    
                else if(g == 1){
                    if(s[i] == s[j]){
                         dp[i][j] = true;
                        if(max_len < 2 ){
                          max_len = 2;
                          st = i;
                          en = j;
                      }
                    }
                       
                    else 
                        dp[i][j] = false;
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1] == true){
                        dp[i][j] = true;
                        if(max_len < j-i+1){
                          max_len = j-i+1;
                          st = i;
                          en = j;
                      }
                    }
                         
                    else
                        dp[i][j] = false;
                    
                }
            }
        }
        return s.substr(st,en-st+1);
        
    }
};