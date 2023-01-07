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
	     
	     
	     /*
	     
	     logic : apun ko nearest 1 nikalna hai mtlb
	             kisi bhi cell se nearest 1 kahan hai horizontal and vertical 
	             movement allowed hai.... 
	     kya soch skte hain ----> bfs level wise kyun ki adjacent me kaam ho raha
	     
	     */
	     
	     int row = grid.size();
	     int col = grid[0].size();
	     
	     vector<vector<int>>  ans(row,vector<int>(col,0));
	     vector<vector<bool>> vis(row,vector<bool>(col,false));
	     
	     queue<pair<int,int>>qu;
	     
	     for(int i = 0 ; i < row ; i++){
	         for(int j = 0 ; j < col ; j++){
	             if(grid[i][j] == 1){
	                 
	                  qu.push({i,j});
	                  vis[i][j] = true;
	                  
	             }
	         }
	     }
	     
	     
	     while(qu.size() > 0){
	         
	         pair<int,int> co_or = qu.front();
	         qu.pop();
	         
	         int i = co_or.first;
	         int j = co_or.second;
	         
	         if(i-1>= 0 && vis[i-1][j] == false){
	             ans[i-1][j] = ans[i][j] + 1;
	             vis[i-1][j] = true;
	             qu.push({i-1,j});
	             
	         }
	         if(j-1>= 0 && vis[i][j-1] == false){
	             ans[i][j-1] = ans[i][j] + 1;
	             vis[i][j-1] = true;
	             qu.push({i,j-1});
	             
	         }
	         if(i+1 < row  && vis[i+1][j] == false){
	             ans[i+1][j] = ans[i][j] + 1;
	             vis[i+1][j] = true;
	             qu.push({i+1,j});
	             
	         }
	         if(j+1 < col && vis[i][j+1] == false){
	             ans[i][j+1] = ans[i][j] + 1;
	             vis[i][j+1] = true;
	             qu.push({i,j+1});
	             
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