class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        // most imp part is to understand lagana kya hai
        // sliding window aur divide and conquer soch raha tha but divide and conquer me
        // mostly hum cnt ke jagah process krte hain sliding window is the way to go..
        
        
        long long int ans = 0;
        
        int src = 0;
        
        unordered_map<int,int> up;
        
        long long curr_pair_cnt = 0;
        
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            
            
            up[nums[i]]++;
            curr_pair_cnt = curr_pair_cnt + up[nums[i]] - 1;
            
            while(curr_pair_cnt >= k ){
                
                 curr_pair_cnt = curr_pair_cnt - (up[nums[src]] - 1);
                 up[nums[src]]--;
                 src++;
                 ans = ans + (n -  i );
            }
            
            
            
        }
        
        return ans;
        

    }
};