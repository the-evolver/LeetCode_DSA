class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int>arrs1(26,0);
        for(int i = 0 ; i < s1.length();i++){
            arrs1[s1[i]-'a']++;
        }
        
         string sn = s2.substr(0,s1.length());
        
         vector<int>arrsn(26,0);
        
         for(int k = 0 ; k < sn.length();k++){
                arrsn[sn[k]-'a']++;
           }
        
          if(check(arrs1,arrsn) == true)
                return true;
        
        for(int i = 1  ; i + s1.length() - 1 < s2.length();i++){
             arrsn[s2[i-1]-'a']--;
             arrsn[s2[i + s1.length() - 1]-'a']++;
            
            
            if(check(arrs1,arrsn) == true)
                return true;
            
        }
        return false;
    }
    bool check(vector<int>arrs1,vector<int>arrsn){
        for(int i = 0 ; i < 26 ; i++){
            if(arrs1[i] != arrsn[i])
                return false;
        }
        return true;
    }
};