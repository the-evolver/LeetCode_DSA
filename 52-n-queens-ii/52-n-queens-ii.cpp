class Solution {
public:
    int cnt = 0;
    int totalNQueens(int n) {
        
        vector<vector<int>> v(n,vector<int>(n,0));
        recur(0,n,v);
        return cnt;
        
    }
    
    void recur(int i , int n,vector<vector<int>>& v){
        if(i == n){
            cnt++;
            return ;
        }
        
        for(int j = 0 ; j < n ; j++){
              if( valid(i,j,n,v) == true ){
                  v[i][j] = 1;
                  recur(i+1,n,v);
                  v[i][j] = 0;
              }
        
        }
        return;
        
        
    
        
        
    }
    bool valid(int row , int col , int n , vector<vector<int>>& v){
        
        // row
        for(int i = 0 ; i < row ; i++ )
             if(v[i][col] == 1)
                 return false;
        // col
         for(int i = 0 ; i < col ; i++ )
             if(v[row][i] == 1)
                 return false;
        
        int i = row - 1 , j = col - 1;
        while( i >= 0 && j >= 0){
            if(v[i][j] == 1)
                return false;
            i--;
            j--;

        
        }
        
        i = row - 1;
        j = col + 1;
        while(i >= 0 && j < n){
            if(v[i][j] == 1)
                return false;
            i--;
            j++;

        }
        return true;    
        
    }
};