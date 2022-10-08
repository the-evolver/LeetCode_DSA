class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        long long ans = INT_MAX;
        for(int i = 0 ; i < n - 2 ; i++){
            
            if(i == 0 || nums[i] != nums[i-1]){
                int lo = i + 1 , hi = n-1;
                
                while( lo < hi ){
                      if( nums[i] + nums[lo] + nums[hi] == target){
                           return target;
                      }
                      else if(nums[i] + nums[lo] + nums[hi] < target){
                             if( abs(target - (nums[i] + nums[lo] + nums[hi])) < abs(target - ans)){
                                   ans = nums[i] + nums[lo] + nums[hi];
                             }
                                
                              lo++;
                      }
                        else{
                               if( abs(target - (nums[i] + nums[lo] + nums[hi])) < abs(target - ans)){
                                   ans = nums[i] + nums[lo] + nums[hi];
                                }
                            
                              hi--;
                        }
                       
                               
                      
                
                }
                
            }
            
            
        }
        return ans;
        
    }
};