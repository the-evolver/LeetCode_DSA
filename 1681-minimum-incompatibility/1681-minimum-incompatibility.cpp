class Solution {
public:
    
    int x = INT_MAX;
    
    int dfs(int e,int ma,int mi,vector<int> &nums,int isUsed, vector<int>& arr,int nidx,int arridx,int k,int sz,int prev){
        
        if(arridx == k){
            x = min(e,x);
            return e;
        }
        if( e > x) return INT_MAX;
        if(bitset<32>(arr[arridx]).count() == sz){
            return dfs(e + ma - mi,INT_MIN,INT_MAX,nums,isUsed,arr,0,arridx+1,k,sz,-1);
        }
        
        
        
        if(nidx == nums.size()) return INT_MAX;
        
        
        int ans = INT_MAX;
        
        for(int i = nidx; i < nums.size(); i++){
            
            if(isUsed&(1<<i) || (arr[arridx]&(1<<nums[i]) || nums[i] <= prev)) continue;
            
            
            
            arr[arridx]^=(1<<nums[i]);
            isUsed ^= (1<<i);
            ans = min(ans,dfs(e,max(ma,nums[i]),min(mi,nums[i]),nums,isUsed,arr,i+1,arridx,k,sz,nums[i]));
            
            arr[arridx]^=(1<<nums[i]);
            isUsed ^= (1<<i);
            
            if(arr[arridx] == 0) break;
            
        }
   
        
        return ans;
    }
    
    
    int minimumIncompatibility(vector<int>& nums, int k) {
          vector<int> b(k);
        sort(nums.begin(),nums.end());
       
        int ans = dfs(0,INT_MIN,INT_MAX,nums,0,b,0,0,k,nums.size()/k,-1);
        return ans != INT_MAX?ans:-1;
    }
};