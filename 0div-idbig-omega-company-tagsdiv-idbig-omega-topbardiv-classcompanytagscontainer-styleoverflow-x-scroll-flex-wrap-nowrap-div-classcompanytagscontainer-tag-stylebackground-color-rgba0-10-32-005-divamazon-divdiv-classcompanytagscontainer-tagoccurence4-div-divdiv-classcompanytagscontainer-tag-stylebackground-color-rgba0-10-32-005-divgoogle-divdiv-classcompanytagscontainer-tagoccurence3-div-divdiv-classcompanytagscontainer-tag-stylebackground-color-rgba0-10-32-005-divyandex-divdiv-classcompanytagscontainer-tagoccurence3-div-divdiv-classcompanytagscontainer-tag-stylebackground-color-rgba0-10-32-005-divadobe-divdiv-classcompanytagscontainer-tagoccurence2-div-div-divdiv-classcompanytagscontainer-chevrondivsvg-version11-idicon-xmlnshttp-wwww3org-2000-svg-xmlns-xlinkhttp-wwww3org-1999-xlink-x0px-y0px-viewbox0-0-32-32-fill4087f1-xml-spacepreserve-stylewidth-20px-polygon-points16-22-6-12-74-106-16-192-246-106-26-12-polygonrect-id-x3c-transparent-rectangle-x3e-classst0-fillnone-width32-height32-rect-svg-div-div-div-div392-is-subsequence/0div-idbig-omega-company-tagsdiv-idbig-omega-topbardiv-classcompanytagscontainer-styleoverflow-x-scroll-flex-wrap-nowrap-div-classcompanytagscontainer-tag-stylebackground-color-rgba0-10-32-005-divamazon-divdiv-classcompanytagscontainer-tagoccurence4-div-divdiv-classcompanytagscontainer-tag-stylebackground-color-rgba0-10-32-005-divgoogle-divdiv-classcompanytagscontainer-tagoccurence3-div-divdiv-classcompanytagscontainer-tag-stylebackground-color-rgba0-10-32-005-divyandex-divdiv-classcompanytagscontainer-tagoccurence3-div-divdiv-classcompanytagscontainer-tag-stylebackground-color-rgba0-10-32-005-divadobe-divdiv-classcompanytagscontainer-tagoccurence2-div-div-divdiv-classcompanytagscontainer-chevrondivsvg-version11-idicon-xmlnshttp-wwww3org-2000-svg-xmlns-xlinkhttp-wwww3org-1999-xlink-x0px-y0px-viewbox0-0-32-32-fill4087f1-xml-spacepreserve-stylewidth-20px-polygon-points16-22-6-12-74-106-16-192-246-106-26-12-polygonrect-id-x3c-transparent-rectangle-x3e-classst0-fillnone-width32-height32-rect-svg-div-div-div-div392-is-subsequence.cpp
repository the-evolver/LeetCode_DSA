class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s == t)
            return true;
        if(s.length() >= t.length())
            return false;
        
        int si = 0 , ti = 0;
        
        int n = s.length();
        int m = t.length();
        while(si < n && ti < m){
            if(s[si] == t[ti]){
                si++;
                ti++;
            }else{
                ti++;
            }
            
        }
        if(si == n)
            return true;
        
        return false;
        
        
    }
};