class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        // i != j
        int maxi = 0;
        unordered_map<int,int> up;
        for(int i = 0 ; i < nums.size();i++){
            up[nums[i]]++;
           
        }
        int ans = 0;
       
            
        
        for(auto it = up.begin() ;  it!= up.end() ;it++){
            int curr = it->first;
            if(up.find(curr+k) != up.end()){
                    if(k == 0 ){
                        if(up[curr] > 1)
                            ans++;
                    }else{
                        ans++;
                    }
                    
             
            }
           
        }
        return ans;
        
    }
    
    
};