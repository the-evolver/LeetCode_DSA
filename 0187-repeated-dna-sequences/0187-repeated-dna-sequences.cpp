class Solution {
public:
vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        int i = 0;
        int j = 0;
        int n = s.length();
        int k = 10;
        string temp = "";
        while(j<n){
            temp+=s[j];
            if(j-i+1 <k){
                j++;
            }
            else{
                m[temp]++;
                temp.erase(temp.begin());
                i++;
                j++;
            }
        }
        vector<string> ans;
          for(auto i:m){
            if(i.second>1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};