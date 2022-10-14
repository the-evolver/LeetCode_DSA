class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        int i = 0 ,j = 0;
        
        while( j < m ){
            if(vis[i][j] == false && board[i][j] == 'O'){
                dfs(board,vis,i,j,n,m);
            }
            j++;
        }
        
        i = n-1;
        j = 0;
        
        while( j < m ){
            if(vis[i][j] == false && board[i][j] == 'O'){
                dfs(board,vis,i,j,n,m);
            }
            j++;
        }
        
        i = 0;
        j = 0;
        
        while( i < n ){
            if(vis[i][j] == false && board[i][j] == 'O'){
                dfs(board,vis,i,j,n,m);
            }
            i++;
        }
        
        j = m-1;
        i = 0;
         while( i < n ){
            if(vis[i][j] == false && board[i][j] == 'O'){
                dfs(board,vis,i,j,n,m);
            }
            i++;
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                 cout<<vis[i][j]<<" ";
                if(vis[i][j] == false && board[i][j] =='O')
                    board[i][j] ='X';
            }
            cout<<endl;
        }
        
        
        
        return;
        
        
    }
    void dfs(vector<vector<char>>& board , vector<vector<bool>>& vis,int i , int j , int n , int m ){
        
       
        if(i < 0 || j < 0 || i == n || j == m || board[i][j] == 'X' || vis[i][j] == true)
            return;
        
        vis[i][j] = true;
        dfs(board,vis,i-1,j,n,m);
        dfs(board,vis,i+1,j,n,m);
        dfs(board,vis,i,j-1,n,m);
        dfs(board,vis,i,j+1,n,m);
        
        
        
    }
};