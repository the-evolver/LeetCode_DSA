class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        set<int> rows;
        set<int> cols;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

             if(matrix[i][j] == 0){
                 rows.insert(i);
                 cols.insert(j);
               }
            
            }
        }
        
        for(auto itr = rows.begin(); itr != rows.end() ; itr++ ){
            
             int row = (*itr) ;
             for(int j = 0 ; j < m ; j++){
                   matrix[row][j] = 0;
             
             }
        
        }
        
        for(auto itr = cols.begin(); itr != cols.end() ; itr++ ){
            
             int col = (*itr) ;
             for(int j = 0 ; j < n ; j++){
                   matrix[j][col] = 0;
             
             }
        
        }
        
        return ;
        
    }
};