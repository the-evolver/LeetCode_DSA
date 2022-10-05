class Solution {
public:
    int maxArea(vector<int>& height) {
      
        int wid ,hei,ans = -1;
        int i = 0 , j = height.size()-1;
        
        while(i < j ){
            
            wid = j - i;
            hei = min(height[j],height[i]);
            ans = max(ans,wid*hei);
            
            if(height[i] < height[j])
                  i++;
            else
                j--;
            
        }
        return ans;
        
    }
};