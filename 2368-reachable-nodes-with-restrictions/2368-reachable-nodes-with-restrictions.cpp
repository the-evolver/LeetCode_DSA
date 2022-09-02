class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
       
        vector<vector<int>>edgs(n,vector<int>());
        
        vector<bool> res(n,false);
        for(int i = 0 ; i < restricted.size();i++)
              res[restricted[i]] = true;
        
        for(int i = 0 ; i < edges.size();i++){
                 int ky  = edges[i][0];
                 int val = edges[i][1];
                 if(res[ky] == false && res[val] == false){
                     edgs[ky].push_back(val);
                     edgs[val].push_back(ky);
                 }
                 
        }
        return dfs(0,-1,edgs) ;
      
    }
    int dfs(int curr ,int parent , vector<vector<int>>& edgs ){
         int cnt = 1;
         for(int i = 0 ; i < edgs[curr].size() ;i++){
              if(edgs[curr][i] != parent)
              cnt += dfs(edgs[curr][i],curr,edgs);
         }
        return cnt ;

    }
    
    
};