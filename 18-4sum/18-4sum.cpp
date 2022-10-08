class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans ;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i =  0 ; i < n - 3 ; i++){
            if( i == 0 || nums[i] != nums[i-1]){
                
                 vector<vector<int>> tsum = ThreeSum(nums,target - nums[i] ,i + 1);
                 for(int j = 0 ; j < tsum.size() ;j++){
                       vector<int> curr = tsum[j];
                       curr.push_back(nums[i]);
                       ans.push_back(curr);
                 }
                
                
                
            }
            
        }
        return ans;
        
    }
    
    vector<vector<int>> ThreeSum(vector<int>& nums, int target,int i){
        
           int n = nums.size();
           vector<vector<int>> ans;
        
           for(int j = i ; j < n - 2 ; j++ ){
                 if(j == i || nums[j] != nums[j-1]){
                     
                     int k = j + 1 , l = n-1;
                     while( k < l ){
                         long long val = (long)nums[j] + (long)nums[k] + (long)nums[l];
                         if( val == target){
                              ans.push_back({nums[j],nums[k],nums[l]});
                              k++;
                              l--;
                             while(k < l && nums[k] == nums[k-1])
                                 k++;
                             while(l > k && nums[l] == nums[l+1])
                                 l--;
                             
                         }
                         else if( val < target)
                               k++;
                         else
                             l--;
                     }
                     
                 }
           }
           
        
        return ans;
        
    }
};