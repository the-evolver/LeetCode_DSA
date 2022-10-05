class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        string s ="";
        for(int i = 1 ; i <= n ; i++)
             s+= ".";
       
        vector<string> st;
        for(int i = 0 ; i < n ; i++){
            st.push_back(s);
            //cout<<st[i]<<endl;
        }
              
        
        vector<vector<string>> ans;
        
        recur(ans,st,n,0);
        
        return ans;
        
        
        
       
    }
    void recur(vector<vector<string>>& ans, vector<string>& st ,int n , int i){
        
        if(i == n){
            //cout<<" -- > ";
            ans.push_back(st);
            return;
        }
        
        for(int j = 0 ; j < n ; j++){
              if( valid(st,i,j,n) == true ){
                   st[i][j] = 'Q';
                   recur(ans,st,n,i+1);
                   st[i][j]='.';
              }
        }
        
        
        
    }
    bool valid(vector<string>& st,int i , int j , int n){
        
        // upar 
        for(int k = 0 ; k < i ; k++){
            if(st[k][j] == 'Q')
                return false;
        }
        
        int k = i-1,l=j-1;
        while(k >= 0 && l >= 0){
            if(st[k][l] == 'Q')
                return false;
            k--;
            l--;
        }
        k = i-1;
        l = j+1;
        while(k >= 0 && l < n){
            if(st[k][l] == 'Q')
                return false;
            k--;
            l++;
        }
        return true;
        
    }
};