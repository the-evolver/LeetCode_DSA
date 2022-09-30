class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sa(26,0);
        vector<int> ta(26,0);
        
        for(int i = 0 ; i < s.length();i++)
            sa[s[i]-'a']++;
         for(int i = 0 ; i < t.length();i++)
            ta[t[i]-'a']++;
        
        for(int i = 0 ; i < 26 ; i++)
            if(sa[i] != ta[i]) return false;
        
        return true;
        
    }
};