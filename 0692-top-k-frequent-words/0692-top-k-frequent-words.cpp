struct CompareHeight {
    bool operator()(pair<string,int> p1, pair<string,int> p2 )
    {
         if(p1.second > p2.second){
            return true;
        }else if(p1.second < p2.second)
            return false;
        
            return p1.first < p2.first;
        
    }
};





class Solution {
public:
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        vector<string> ans;
        vector<pair<string,int>> s_ans;
        
        unordered_map<string,int> up;
        priority_queue< pair<string,int> , vector<pair<string,int>> ,CompareHeight > pq;
        
        int n = words.size();
        
        for(int i = 0 ; i < n ; i++){
            up[words[i]]++;
        }
        
      
        for(auto itr = up.begin();itr != up.end();itr++){
              pair<string,int> curr;
              curr.first  = itr->first;
              curr.second = itr->second;
              pq.push(curr);
              if(pq.size() > k)
                  pq.pop();
        }
        
        
        while(pq.size() > 0){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        for(int i = 0 , j = ans.size() - 1 ; i < j ; i++,j--)
              swap(ans[i],ans[j]);
        
        return ans;
    }
};