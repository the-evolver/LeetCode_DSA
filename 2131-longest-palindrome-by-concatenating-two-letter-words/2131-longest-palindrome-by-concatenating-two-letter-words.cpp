class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int>up;
        
        for(int i = 0 ; i < words.size() ; i++){
            up[words[i]]++;
        }
        
        int ans = 0;
        bool middle_possible = false;
        
        for(int i = 0 ; i < words.size() ; i++){
              
              string s = words[i];
              string rev = words[i];
             reverse(rev.begin(),rev.end());
            
            if(s == rev ){
                
                int a = up.find(s)->second;
                a = a % 2 == 0 ? a : a - 1;
                ans = ans + a*2;
                up[s] = up[s] - a;
                if(up[s] > 0 ){
                    middle_possible = true;
                    
                }
                
                
                
            }else{
                
                int a = up.find(s) == up.end() ? 0 : up.find(s)->second;
                int b = up.find(rev) == up.end() ? 0 : up.find(rev)->second;
                
                int minv = min(a,b);
                
                if(minv != 0 ){
                    
                    ans = ans + minv*4;
                    up[s] = 0;
                    up[rev] = 0; // no need for this just for easy understanding
                }
                
                
                
            }
        
        
        
        }
        if(middle_possible == true)
            ans = ans + 2;
        
         return ans;
        
    }
};