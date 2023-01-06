class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        
        vector<vector<int>> vis(row,vector<int>(col,false));
        dfs(sr,sc,color,image,vis,row,col);
        return image;
        
    }
    
    void dfs(int i , int j , int cl,vector<vector<int>>& image ,vector<vector<int>>& vis,int row,int col){
        
              vis[i][j] = true;
              
        
              if(i-1 >= 0 && vis[i-1][j] == false && image[i-1][j] == image[i][j] ){
                  dfs(i-1,j,cl,image,vis,row,col);
              }
        
              if(j-1 >= 0 && vis[i][j-1] == false  && image[i][j-1]  == image[i][j]){
                  dfs(i,j-1,cl,image,vis,row,col);
              }
        
              if(i+1 < row && vis[i+1][j] == false  && image[i+1][j] == image[i][j]){
                  dfs(i+1,j,cl,image,vis,row,col);
              }
        
              if(j+1 < col && vis[i][j+1] == false  && image[i][j+1] == image[i][j]){
                  dfs(i,j+1,cl,image,vis,row,col);
              }
            
            
            image[i][j] = cl;
            
    }
    
    
};