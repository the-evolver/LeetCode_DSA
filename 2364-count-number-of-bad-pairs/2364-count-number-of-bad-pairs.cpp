class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unsigned long long cnt = 0;
        unordered_map<unsigned long long,unsigned long long>up;
        unsigned long long n = nums.size();
        for(unsigned long long i = 0 ; i < n ; i++){
            nums[i] = nums[i] - i;
            up[nums[i]]++;
            
        }
        
        unsigned long long total = (long long)((n - 1) * (n) ) / 2;
        unsigned long long  good = 0 ;
        for(auto it = up.begin() ; it!= up.end() ; it++){
              if(it->second > 1){
                  unsigned long long cnt = it->second;
                  good += (long long )((cnt) *(cnt-1))/2;
              }
        }
        
        return total - good;
        
    }
    
};