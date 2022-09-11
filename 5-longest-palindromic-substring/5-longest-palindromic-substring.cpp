class Solution {
public:
    string longestPalindrome(string s) {
        
        int max_len = 0;
        int st = -1 , en = -1;
        
        // odd center 
        for(int c = 0 ; c < s.length() ; c++){
            for(int i = c , j = c ; i >= 0 && j < s.length();i--,j++){
                if(s[i] != s[j])
                    break;
                if(j-i+1 > max_len){
                    max_len = j - i + 1;
                    st = i;
                    en = j;
                }
            }
        }
        
        for(int c = 0 ; c < s.length() ; c++){
            for(int i = c , j = c + 1 ; i >= 0 && j < s.length();i--,j++){
                if(s[i] != s[j])
                    break;
                if(j-i+1 > max_len){
                    max_len = j - i + 1;
                    st = i;
                    en = j;
                }
            }
        }
        return s.substr(st,en-st+1);
        
        
    }
};