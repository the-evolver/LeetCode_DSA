class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        // logic : agar koe bhi O boundary pe hai kisi region ka to region capture nahe hoga warna capture hoga.....
        
        int row = board.size();
        int col = board[0].size();
        
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        queue<pair<int,int>> qu;
        
        for(int i = 0 ; i < row ; i++){
              for(int j = 0 ; j < col ; j++){
                  
                     if( board[i][j] =='O' && ( i == 0 || j == 0 || i == row-1 || j == col-1)){
                         qu.push({i,j});
                         vis[i][j] = true;
                     }
    
    
           }
         }
        
        while(qu.size() > 0){
            pair<int,int> co_or = qu.front();
            qu.pop();
            
            int i = co_or.first;
            int j = co_or.second;
            
            if(i-1 >= 0 && vis[i-1][j] == false && board[i-1][j] == 'O'){
                vis[i-1][j] = true;
                qu.push({i-1,j});

            }
            if(j-1 >= 0 && vis[i][j-1] == false && board[i][j-1] == 'O'){
                vis[i][j-1] = true;
                qu.push({i,j-1});

            }
            if(i+1 < row && vis[i+1][j] == false && board[i+1][j] == 'O'){
                    vis[i+1][j] = true;
                    qu.push({i+1,j});
            }
            if(j+1 < col  && vis[i][j+1] == false && board[i][j+1] == 'O'){
                        vis[i][j+1] = true;
                        qu.push({i,j+1});

            }
            
        }
        
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(vis[i][j] == false){
                    board[i][j] ='X';
                }
            }
        }
       
        
    }
};