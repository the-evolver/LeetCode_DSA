class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> numtrust(n+1,0);
        vector<int> mytrust(n+1,0);
        
        for(int i = 0 ; i < trust.size() ; i++){
            
            mytrust[trust[i][0]]++;
            numtrust[trust[i][1]]++;
        }
        
        for(int i = 1 ; i < n + 1 ; i++){
            if(numtrust[i] == n-1 && mytrust[i] == 0)
                return i;
        }
        return -1;
    }
};