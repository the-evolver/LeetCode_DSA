class Solution {
public:
    int lengthOfLastWord(string s) {
        stack<string> st;
        string curr ="";
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == ' '){
                if(curr.length() > 0)
                    st.push(curr);
                curr ="";
                
            }else{
                curr += s[i];
            }
        }
        if(curr.length() > 0)
                    st.push(curr);
        return st.top().length();
    }
};