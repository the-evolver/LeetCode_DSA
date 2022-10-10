class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
         int n = triangle.size();
    
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < triangle[i].size();j++){
                   int op1 = INT_MAX;
                   int op2 = INT_MAX;
                   if(triangle[i-1].size() > j )
                       op1 = triangle[i-1][j];

                   if( j >= 1){
                       op2 = triangle[i-1][j-1];
                   }
                   
                
                   triangle[i][j] = min(op1,op2) + triangle[i][j];
                
            }
            //cout<<endl;
        }
        int mini = INT_MAX;
        for(int i = 0 ; i < triangle[n-1].size();i++){
            mini = min(mini,triangle[n-1][i]);
        }
        return mini;
        
    }
};