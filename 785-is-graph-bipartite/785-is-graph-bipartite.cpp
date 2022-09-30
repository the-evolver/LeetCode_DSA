class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();
        vector<int>vis(V,0);
         queue<pair<int,int>>qu;
         for(int i = 0 ; i < V ; i++){
               if(vis[i] != 0)
                   continue;
              
               qu.push({i,-1});
               qu.push({-1,-1});
               int color = 1;
             
               while(qu.size() > 0 ){
                   
                   pair<int,int> top = qu.front();
                   qu.pop();
                   
                   if(top.first == -1){
                       if(qu.size() > 0 )
                           qu.push({-1,-1});
                       
                       color = 3 - color;
                       
                   }else{
                       
                       vis[top.first] = color;
                   
                    for(int j : graph[top.first]){
                       
                       if(j == top.second)
                           continue;
                       if(vis[j] == vis[top.first])
                           return false;
                       if(vis[j] == 0){
                           qu.push({j,top.first});
                       }
                     }
                       
                   }
                   
                   
               }
          
         }
        return true;
    }
};