class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;
        
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }

            }
        }
        
        for( auto it = rows.begin() ; it!= rows.end() ; it++ ){
            
              int curr_row = *it;
              for(int j = 0 ; j < matrix[0].size() ; j++){
                   matrix[curr_row][j] = 0;
           }
            
         }
        for( auto it = cols.begin() ; it!= cols.end() ; it++ ){
            
              int curr_col = *it;
            
              for(int i = 0 ; i < matrix.size() ; i++){
                   matrix[i][curr_col] = 0;
           }
            
         }
       
        
        
        return ;
        
    }
};