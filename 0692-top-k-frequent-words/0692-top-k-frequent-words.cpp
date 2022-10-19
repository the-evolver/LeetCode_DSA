bool comp(pair<string,int> p1, pair<string,int> p2 ){
          
        if(p1.second > p2.second){
            return true;
        }else if(p1.second < p2.second)
            return false;
        
            return p1.first < p2.first;
        
        
    }

class Solution {
public:
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        vector<pair<string,int>> s_ans;
        
        unordered_map<string,int> up;
        int n = words.size();
        for(int i = 0 ; i < n ; i++){
            up[words[i]]++;
        }
        
      
        for(auto itr = up.begin();itr != up.end();itr++){
              pair<string,int> curr;
              curr.first  = itr->first;
              curr.second = itr->second;
              s_ans.push_back(curr);
        }
        
        sort(s_ans.begin(),s_ans.end(),comp);
        
        
        for(int i = 1 , j = 0 ; i <= k ; i++){
             
                
                 ans.push_back(s_ans[j++].first);
                 
             
        }
        
        return ans;
    }
};