class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        
        signed long long ans = 0;
        signed long long src = 0;
        
       
        
        signed long long curr_sum = 0;
        
        priority_queue< pair<signed long long,signed long long> > pq;
        
        signed long long n = chargeTimes.size();
        
        for(int i = 0 ; i < n ; i++){
            
            
             pq.push({chargeTimes[i],i});
            
             curr_sum += runningCosts[i];
            
            while(((signed long long)pq.top().first + (signed long long)curr_sum*(i-src + 1)) > budget){
                
                  curr_sum = curr_sum - runningCosts[src];
                  src++;
                  while(pq.size() > 0 && pq.top().second < src){
                      pq.pop();
                  }
                if(pq.size() == 0 || curr_sum == 0)
                    break;
            }
            
            ans = max(ans,i-src+1);
            
            
        }
        
        
        return ans;
        
        
    }
};