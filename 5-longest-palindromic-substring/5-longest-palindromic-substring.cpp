class Solution {
public:
    string longestPalindrome(string s) {
        
        int st = -1 , en = -1 , max_l = -1;
        int n = s.length();
        bool dp[n][n];
        
        for(int g = 0 ; g < n ; g++){
             
              for(int i = 0 , j = g ; j < n ; i++,j++){
                   if(g == 0){
                       dp[i][j] = true;
                       if(max_l < 1){
                           max_l = 1;
                           st = i;
                           en = j;
                       }
                   }
                  
                  else if(g == 1){
                      if(s[i] == s[j] ){
                          dp[i][j] = true;
                         if(max_l < 2){
                            max_l = 1;
                            st = i;
                            en = j;
                       }
                          
                      }
                      else
                          dp[i][j] = false;
                      
                      
                  }else{
                      if(s[i] == s[j] && dp[i+1][j-1] == true){
                             dp[i][j] = true;
                             if(max_l < j - i + 1){
                                 max_l = j - i + 1;
                                 st = i ;
                                 en = j ;
                             }
                      }else 
                          dp[i][j] = false;
                       

                  
                  }
                  
              }
            
            
        }
        return s.substr(st,en-st+1);
        
        
    }
};