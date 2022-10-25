/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> crt;
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
            int cnt = 0;
        
        while(temp != NULL){
              nxt = temp->next;
             if(prev != NULL && nxt != NULL){
                 if(temp->val < prev->val && temp->val < nxt->val){
                      crt.push_back(cnt);
                 }
                 if(temp->val > prev->val && temp->val > nxt->val){
                      crt.push_back(cnt);
                 }
                 
                    
             }
            
            prev = temp;
            temp = nxt;
            cnt++;
            
        }
        vector<int> ans;
        int mini = -1;
        int maxi = -1;
        if(crt.size() >= 2)
            maxi = crt[crt.size()-1]-crt[0];
        for(int i = 1 ; i < crt.size() ;i++){
            //cout<<crt[i-1]<<" "<<crt[i]<<endl;
            if(mini == -1){
                mini = crt[i]-crt[i-1];
            }else{
                mini = min(mini,crt[i]-crt[i-1]);
            }
        }
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
        
    }
};