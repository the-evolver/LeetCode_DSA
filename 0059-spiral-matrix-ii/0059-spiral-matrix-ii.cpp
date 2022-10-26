class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        
        vector<vector<int>> ans(n,vector<int>(n,0));
        
        int cnt = 1;
        int tar = n * n ;
        
        int sr = 0 , er = n-1 , sc = 0 , ec = n - 1;
        
        while( cnt <= tar ){
            
            // starting row 
            for(int i = sc ; i <= ec ; i++){
                ans[sr][i] = cnt;
                cnt++;
            }
            
            if(cnt > tar)
                break;
            
            sr++;
            
            // end coloumn 
            for(int i = sr ; i <= er ; i++){
                ans[i][ec] = cnt;
                cnt++;
            }
            
            if(cnt > tar)
                break;
            
            ec--;
            
            
            // end row 
            
            for(int i = ec ; i >= sc ; i--){
                ans[er][i] = cnt;
                cnt++;
            }
            
            if(cnt > tar)
                break;
            
            er--;
            
            for(int i = er ; i >= sr ; i--){
                ans[i][sc] = cnt;
                cnt++;
            }
            
            sc++;
            
            
            
            
            
        }
        
        return ans;
        
        
        
    }
};