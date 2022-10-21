class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;
        for(int i = 0 ; i < sentences.size();i++)
            maxi = max(maxi,words(sentences[i]));
        
        return maxi;
    }
    
    int words(string str){
        int cnt =  0;
        for(int i = 0 ; i < str.length();i++){
            if(str[i] == ' ' || i == str.length()-1)
                cnt++;
        }
        return cnt;
    }
};