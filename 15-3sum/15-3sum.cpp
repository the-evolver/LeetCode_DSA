class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i = 0 ; i < n - 2 ; i++){
            if( i > 0 && nums[i] == nums[i-1])
                continue;
            
            
            int j = i + 1 , k = n - 1;
            while( j < k ){
                
                   
                
                if(nums[i] + nums[j] + nums[k] == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    
                }
                if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                    
                }
                if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                    
                }
                    
                
            }
            
        }
        set<vector<int>>st;
        for(int i = 0 ; i < ans.size();i++){
            
             vector<int> v = ans[i];
             sort(v.begin(),v.end());
             st.insert(v);
        }
           
        
        ans.clear();
        for(auto it = st.begin();it!= st.end();it++){
            ans.push_back(*it);
        }
        return ans;
        
    }
};