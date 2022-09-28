class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int src = 0 ;
        int dest = graph.size()-1;
        vector<int>c_ans;
        vector<bool>vis(dest+1,false);
        
        allp(graph,src,dest,c_ans,vis);
        return ans;
        
    }
    
    void allp(vector<vector<int>>& graph , int src , int dest ,vector<int>& c_ans , vector<bool>& vis){
        
        if(src == dest){
            c_ans.push_back(src);
            ans.push_back(c_ans);
            c_ans.pop_back();
            return;
        }
        vis[src] = true;
        
        for(int i = 0 ; i < graph[src].size();i++){
            
            if(vis[graph[src][i]] == false){
                c_ans.push_back(src);
                allp(graph,graph[src][i],dest,c_ans,vis);
                c_ans.pop_back();
            }
        }
        vis[src] = false;
        
    }
};