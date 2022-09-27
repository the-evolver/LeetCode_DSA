class Solution {
public:
    list<int>* adj;
    
    int snakesAndLadders(vector<vector<int>>& board) {
         int n = board.size();
         int v = n*n + 1 ;
         adj = new list<int>[v];
        
        for(int i = 1 ; i < v ; i++){
             for(int x = 1 ; x <= 6 ; x++){
                   int val = i + x ;
                   if(val > n*n)
                       break;
                 
                   int rw ,cl;
                   if(val % n == 0){
                       rw = val / n  -  1;
                       cl = n - 1;
                   }
                   else{
                       rw = val / n;
                       cl = val % n - 1;
                   }
                   rw = n - 1 - rw;
                 
                   if(n % 2 == 0){
                       if(rw % 2 == 0)
                           cl = n - 1 - cl;
                       
                   }
                  if(n % 2 != 0){
                      if(rw % 2 != 0)
                           cl = n - 1 - cl;
                      
                  }
                 
                  if(board[rw][cl] == -1)
                      adj[i].push_back(val);
                  else{
                      adj[i].push_back(board[rw][cl]);
                      if(val == n*n)
                      adj[i].push_back(val);
                      
                  }
                      
             }
        }
        return bfs_shortest_path(n*n);
        
        
        
    }
    
    int bfs_shortest_path(int dest ){
        int src = 1;
        
        vector<int> dist(dest+1,-1);
        dist[src] = 0;
        queue<int>qu;
        qu.push(src);
        
        while(qu.size() > 0){
            int f = qu.front();
            qu.pop();
            
            for(int j : adj[f]){
                //cout<<f<<" --- "<<j<<" ";
                //cout<<endl;
                if(dist[j] == -1){
                    dist[j] = dist[f] + 1;
                    qu.push(j);
                }
            }
            
            
        }
//         for(int i = 1 ;i <= dest ; i++){
//             cout<<i << " -- "<<dist[i]<<"  ";
//             cout<<endl;
            
//         }
        return dist[dest];
        
        
    }
};