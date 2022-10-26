class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> ans;
        
        int cnt = 0;
        int len = (n * m);
        
        int sr = 0 , er = n - 1 , sc = 0 , ec = m - 1;
        while(cnt < len){
            
            // starting row
            for(int i = sc ; i <= ec ; i++){
                ans.push_back(matrix[sr][i]);
                cnt++;
                 
            }
            if(cnt == len)
                break;
            sr++;
            
            // end coloumn 
            
            
            for(int i = sr ; i <= er ; i++){
                ans.push_back(matrix[i][ec]);
                cnt++;
                 
            }
            if(cnt == len)
                break;
            ec--;
            
            // end row 
            
            for(int i = ec ; i >= sc ; i--){
                ans.push_back(matrix[er][i]);
                cnt++;
                 
            }
            if(cnt == len)
                break;
            er--;
            
            for(int i = er ; i >= sr ; i--){
                ans.push_back(matrix[i][sc]);
                cnt++;
                 
            }
            sc++;
           
        }
        
        return ans;
        
    }
};