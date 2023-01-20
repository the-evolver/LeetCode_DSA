class Solution {
public:
     set<vector<int>> v;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int> ans;
        nn(0,nums.size(),nums,ans);
        vector<vector<int>> soln;
        
        for(auto i = v.begin() ; i != v.end() ;i++){
               soln.push_back((*i));
        }
        return soln;
       
    }
    
    
    void nn(int i , int n , vector<int>& nums,vector<int>& ans){
        
        if(i == n ){
            if(ans.size() > 1)
            v.insert(ans);
            ans.pop_back();
        return;
        }
        
        if(ans.size() == 0 || ans[ans.size()-1] <= nums[i]){
            ans.push_back(nums[i]);
            nn(i+1,n,nums,ans);
        }
        
        nn(i+1,n,nums,ans);
        
        return;
        
        
    }
};