class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int src = 0;
        
        vector<int> map(3,0);
        
        int ans = 0;
        
        int n = s.length();
        
        for(int i = 0 ; i < n ; i++){
            
             map[s[i]-'a']++;
            
             while(map[0] >= 1 && map[1] >= 1 && map[2] >= 1){
                    ans += n - i;
                    map[s[src]-'a']--;
                    src++;
             }
            
        }
        
     return ans;
    }
};