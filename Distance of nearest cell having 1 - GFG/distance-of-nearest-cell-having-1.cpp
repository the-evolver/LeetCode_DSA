//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,0));
	    
	    queue<pair<int,int>> qu;
	    vector<vector<bool>> vis(n,vector<bool>(m,false));
	    
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < m ; j++){
	            if(grid[i][j] == 1){
	                vis[i][j] = true;
	                qu.push({i,j});
	            }
	        }
	    }
	    
	    while(qu.size() > 0 ){
	        
	        auto it = qu.front();
	        qu.pop();
	        
	        int i = it.first;
	        int j = it.second;
	        
	        if(i-1 >= 0 && vis[i-1][j] == false){
	            ans[i-1][j] = ans[i][j] + 1;
	            qu.push({i-1,j});
	            vis[i-1][j] = true;
	        }
	        if(j-1 >= 0 && vis[i][j-1] == false){
	            ans[i][j-1] = ans[i][j] + 1;
	            qu.push({i,j-1});
	            vis[i][j-1] = true;
	        }
	        if(i+1 < n && vis[i+1][j] == false){
	            ans[i+1][j] = ans[i][j] + 1;
	            qu.push({i+1,j});
	            vis[i+1][j] = true;
	        }
	        if(j+1 < m && vis[i][j+1] == false){
	            ans[i][j+1] = ans[i][j] + 1;
	            qu.push({i,j+1});
	            vis[i][j+1] = true;
	        }
	        
	    }
	    
	    return ans;
	    
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends