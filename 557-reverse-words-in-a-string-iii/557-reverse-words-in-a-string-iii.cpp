class Solution {
public:
    string reverseWords(string s) {
        int st = -1  ;
        string curr ="";
        for(int i = 0 ; i < s.length();i++){
             // if(s[i] == '"' && i < s.length() - 1)
             //     continue;
            
             if(s[i] == ' ' ){
                  curr = wordrev(curr);
                  cout<<curr<<endl;
                  for(int j = 0 ; j < curr.length() ; j++ ){
                      s[i-curr.length()+ j ] = curr[j];
                  }
                 curr.clear();
             }
             else{
                 curr = curr + s[i];
             }
            

        }
                  curr = wordrev(curr);
                  cout<<curr<<endl;
                  for(int j = 0 ; j < curr.length() ; j++ ){
                      s[s.length()-curr.length()+ j ] = curr[j];
                  }
        return s;
        
    }
    
    string wordrev(string s){
       for(int i = 0 , j = s.length()-1 ; i < j;i++,j--){
           swap(s[i],s[j]);
       }
        return s;
    
    }
};