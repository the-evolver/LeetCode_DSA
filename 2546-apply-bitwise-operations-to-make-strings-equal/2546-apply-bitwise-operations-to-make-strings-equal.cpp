class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        
        if(s == target){
            
            return true;
        }
        
        int n = s.length();
        
        int cnts_0 = 0 , cntt_0 = 0;
        for(int i = 0 ; i < n ; i++){
            
            if(s[i] == '0')
                cnts_0++;
            
            if(target[i] == '0')
                cntt_0++;
            
        }
        
        if(cnts_0 == n || cntt_0 == n){
            
            return false;
        }
            
        return true;
    }
};