class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        // two cases : element found or not found
        vector<int>ans;
        int n = arr.size();
        int st = 0 , en = n - 1 , mid;
        bool found = false;
        while(st <= en ){
            mid = (st + en )/2;
            if(arr[mid] == x){
                found = true;
                break;
            }
            if(arr[mid] < x)
                st = mid + 1;
            if(arr[mid] > x)
                en = mid - 1;
        }
        
        if(found == true){
            
            ans.push_back(arr[mid]);
            int i = mid - 1 , j = mid + 1;
            int cnt = 1;
            while(cnt < k ){
                
                if(i < 0 && j < n ){
                    ans.push_back(arr[j]);
                    j++;
                    cnt++;
                }
                else if(j == n && i >= 0 ){
                    ans.push_back(arr[i]);
                    i--;
                    cnt++;
                }
                else if(i >= 0 && j < n ){
                    
                     int v1 = abs(arr[i]- x);
                     int v2 = abs(arr[j]-x);
                     if(v1 <= v2){
                         ans.push_back(arr[i]);
                         i--;
                         cnt++;
                         
                     }else{
                         
                         ans.push_back(arr[j]);
                         j++;
                         cnt++;
                         
                     }
                     
                }
                
                
                
            }
            
        }else{
            if(en < 0 ){
                for(int i = 0 ; i < k ; i++)
                    ans.push_back(arr[i]);
                
            }
            else if(st > n - 1){
                for(int j = n-1 , cnt = 0; cnt < k ; j--,cnt++)
                    ans.push_back(arr[j]);
                
            }
            else{
                
            int i = st , j = en;
                cout<<st<<" -- "<<en<<endl;
                int cnt = 0;
              while(cnt < k ){
                
                if(i == n && j >= 0 ){
                    ans.push_back(arr[j]);
                    j--;
                    cnt++;
                }
                else if(j < 0 && i < n ){
                    ans.push_back(arr[i]);
                    i++;
                    cnt++;
                }
                else if(i < n && j >= 0 ){
                    
                     int v1 = abs(arr[i]- x);
                     int v2 = abs(arr[j]-x);
                     if(v1 < v2){
                         ans.push_back(arr[i]);
                         i++;
                         cnt++;
                         
                     }else{
                         
                         ans.push_back(arr[j]);
                         j--;
                         cnt++;
                         
                     }
                     
                }
                
                
                
            }
                
                
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};