class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        string str ="";
        
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == ' '){
                
                if(str.size() > 0)
                st.push(str);
                str = "";
            }else{
                str = str + s[i];
            }
            
        }
        if(str.size() > 0)
            st.push(str);
        
        string ans = "";
        while(st.size() > 0){
            ans += st.top();
            
            st.pop();
            if(st.size() > 0)
                ans+= " ";
        }
        
        return ans;
        
    }
};