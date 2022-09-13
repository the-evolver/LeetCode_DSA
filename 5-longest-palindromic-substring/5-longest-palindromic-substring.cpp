class Solution {
public:
    string longestPalindrome(string s) {
        
        // odd center
        int st = -1 , en = -1;
        int n  = s.length();
        int max_len = 0;
        for(int c = 0 ; c < n ; c++){
            
            for(int i = c , j = c ; i >= 0 && j < n ; i--,j++){
                 if(s[i] != s[j])
                     break;
                  
                  if(max_len < j - i + 1){
                      st = i ;
                      en = j;
                      max_len = j - i +1;
                  }
            }
            
            
             
        }
        
        for(int c = 0 ; c < n ; c++){
            for(int i = c , j = c+1 ; i >= 0 && j < n ; i--,j++){
                 if(s[i] != s[j])
                     break;
                  
                  if(max_len < j - i + 1){
                      st = i ;
                      en = j;
                      max_len = j - i +1;
                  }
            }
                    
            
             
        }
        
        return s.substr(st,en-st+1);
        
    }
};