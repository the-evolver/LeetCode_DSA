class Solution {
    public boolean isBipartite(int[][] graph) {
        int V = graph.length;
        int[] vis = new int[V];
        
// vis will have 3 states : //  0 - not visited //  1 - visited and coloured with 1 //2 - visited and coloured with 2
        
        for(int i = 0 ; i < V ; i++){ 
            // loop used as graph may bedisconnected so we need to check for all nodes na re babu...
            if(vis[i] == 0 && dfs(graph,vis,i,-1,1) == false)
                 return false;   
        }
        return true;
    }
    
    public boolean dfs(int[][] graph,int[] vis ,int curr,int par , int color ){
        
        vis[curr] = color;
        
        for(int j : graph[curr]){
              if(j == par) // respect your parent 
                 continue; 
            
              if(vis[j] == color)
                  return false;
              if(vis[j] == 0 && dfs(graph,vis,j,curr,3-color) == false)
                  return false;
        }
        return true;
        
        
    }
    
    
}