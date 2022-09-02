class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        vector<bool>arr(2000+a+b+100,true);
        
        for(int i = 0 ; i < forbidden.size() ; i++)
              arr[forbidden[i]] = false;
        
        queue<pair<int,bool>>state;
        
         state.push({0,false});
         
         int ans  = 0;
        
        while(state.empty() == false){
            
              int sz = state.size();
              while(sz--){
                    pair<int,bool> top = state.front();
                    state.pop();
                   
                    if(top.first == x)
                        return ans;
            
            
                    int curr = top.first;
                  if(curr-b >= 0 && arr[curr-b] == true && top.second == false){
                    arr[curr-b] = false;
                    state.push({curr-b,true});
                }
                    if(curr + a  <=  2000 + a + b && arr[curr+a] == true){
                        arr[curr+a] = false;
                        state.push({curr+a,false});
                    }
                    
                
                
                  
              }
           
          ans++;
        }
        return -1;
        
    }
};