//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
          
          int row = image.size();
          int col = image[0].size();
          vector<vector<bool>> vis(row,vector<bool>(col,false));
          
          dfs(image,sr,sc,newColor,row,col,vis);
          
          return image;
    }
    
    void dfs(vector<vector<int>>& image,int i , int j , int nc , int row, int col ,vector<vector<bool>>& vis){
        
        vis[i][j] = true;
        
        if(i-1 >= 0 && vis[i-1][j] == false && image[i-1][j] == image[i][j]){
            dfs(image,i-1,j,nc,row,col,vis);
        }
        
        if(i+1 < row && vis[i+1][j] == false && image[i+1][j] == image[i][j]){
            dfs(image,i+1,j,nc,row,col,vis);
        }
        if(j-1 >= 0 && vis[i][j-1] == false && image[i][j-1] == image[i][j]){
            dfs(image,i,j-1,nc,row,col,vis);
        }
        if(j+1 <= col && vis[i][j+1] == false && image[i][j+1] == image[i][j]){
            dfs(image,i,j+1,nc,row,col,vis);
        }
        
        image[i][j] = nc;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends