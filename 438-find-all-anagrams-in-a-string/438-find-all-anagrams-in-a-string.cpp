class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length() > s.length())
            return {};
        
        vector<int>ans;
        vector<int>arrp(26,0);
        vector<int>arrs(26,0);
        int pn = p.length();
       
        
        for(int i = 0 ; i < pn ; i++){
            arrp[p[i]-'a']++;
        }
        for(int i = 0 ; i < pn ; i++){
            arrs[s[i]-'a']++;
        }
        
        if(check(arrp,arrs) == true)
            ans.push_back(0);
        
        for(int i = 1 ; i + pn - 1 < s.length();i++){
            
             arrs[s[i-1]-'a']--;
             arrs[s[i+pn-1]-'a']++;
            if(check(arrp,arrs) == true)
               ans.push_back(i);
            
        }

        
        return ans;
        
        
    }
    bool check(vector<int>arr1,vector<int>arr2){
        for(int i = 0 ; i < 26; i++){
            if(arr1[i] != arr2[i])
                return false;
        }
        return true;
    }
};