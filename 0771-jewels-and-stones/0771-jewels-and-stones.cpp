class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        unordered_map<char,int> up;
        
        for(int i = 0 ; i < jewels.length() ; i++){
            up[jewels[i]] = i;
        }
        
        int cnt = 0;
        for(int i = 0 ; i < stones.length();i++){
             if(up.find(stones[i]) != up.end())
                 cnt++;
        }
        
        return cnt;
        
    }
};