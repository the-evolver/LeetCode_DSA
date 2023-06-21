class Solution {
public:
    bool isValid(string s) {
        
        stack<char> open;
        
        for(int i = 0 ; i < s.length();i++){
            
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                 open.push(s[i]);
            }
            else{
                if(open.size() == 0)
                    return false;
               
               char ch = open.top();
               if(( s[i] == ')' && ch == '(' )||( s[i] == '}' && ch == '{' )|| ( s[i] == ']' && ch == '[' ) ){
                      
                        open.pop();
                       }
                    else{
                        return false;
                    }
                
                
                
                
                
            }
            
            
        }
        
        return open.size() == 0 ? true :false;
        
    }
};