class Solution {
public:
    string minWindow(string s, string t) {
        
        int lens = s.length();
        int lent = t.length();
        
        if( (lens < lent)  )
            return "";
        if(s == t)
            return s;
        
        
         unordered_map<char,int> map_st;
        
         unordered_map<char,int>  curr_st;
        
         int curr_cnt = 0;
        
        for(int i = 0 ; i < lent ; i++){
            
            map_st[t[i]]++;
            
        }
        
        
        
        string ans = "";
        
        for(int i = 0 , j = 0 ; j <= lens ; ){
            
           
            
              
            
             if(curr_cnt < lent){
                 //cout<<i<<" , "<<j<<endl;
                 char rem = s[j];
                 j++;
                 curr_st[rem]++;
                 if( map_st.find(rem) != map_st.end() && map_st[rem] >= curr_st[rem] )
                      curr_cnt++;
                 
                 
             }
             else {
                 //cout<<i<<" : "<<j<<endl;
                 if(curr_cnt == lent){
                     if(ans == "" || ans.length() > j - i  ){
                         ans = s.substr(i , j - i);
                     }
                 }
                 
                 char rem = s[i];
                 i++;
                 curr_st[rem]--;
                 if(map_st.find(rem) != map_st.end() && curr_st[rem] < map_st[rem])
                     curr_cnt--;
                 
                
             }
            
           
            
        }
        
        
        return ans;
        

    }
    
    
};