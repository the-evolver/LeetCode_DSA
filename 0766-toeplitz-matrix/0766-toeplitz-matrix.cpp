class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int st;
        for(int i = 0 ; i < n ; i++){
              int val = -1;
              st = i;
             for(int j = 0 ; j < m && st < n ; j++,st++){
                 if(val == - 1)
                     val = matrix[st][j];
                 if(matrix[st][j] != val){
                     cout<<" ; "<<matrix[st][j]<<endl;
                      return false;
                 }
                    
                 
             }
        }
        
        
        for(int j = 0 ; j < m ; j++){
              int val = -1;
              st = j;
             for(int i = 0 ; i < n && st < m ; i++,st++){
                 if(val == - 1)
                     val = matrix[i][st];
                 if(matrix[i][st] != val){
                      cout<<matrix[i][st]<<endl;
                      return false;
                 }
                    
                 
             }
        }
        return true;
        
    }
};