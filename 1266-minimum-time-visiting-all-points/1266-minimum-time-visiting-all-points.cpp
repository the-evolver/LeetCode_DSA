class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int ans = 0;
        
        for(int i = 0 ; i + 1 < points.size() ; i++){
            
            ans += minimum_distance(points[i],points[i+1]);
            
            
            
        }
        return ans;
    }
    
    int minimum_distance(vector<int>& p1 , vector<int>& p2){
        
        int x1 = p1[0];
        int y1 = p1[1];
        
        int x2 = p2[0];
        int y2 = p2[1];
        
        if(x1 == x2)
            return abs(y2 - y1);
        if(y1 == y2)
            return abs(x2 - x1);
        
        int ans = 0;
        
        while(x2 > x1 && y2 > y1){
               ans++;
               x1++;
               y1++;
        }
        
         while(x1 > x2 && y1 > y2){
               ans++;
               x1--;
               y1--;
        }
        
        while(x2 > x1 && y2 < y1){
               ans++;
               x1++;
               y1--;
        }
        while(x2 < x1 && y2 > y1){
               ans++;
               x1--;
               y1++;
        }
        
        
        ans = ans + abs(x2-x1) + abs(y2-y1);
        
        return ans;
    }
};