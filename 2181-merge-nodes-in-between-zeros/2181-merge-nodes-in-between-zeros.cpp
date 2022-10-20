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
    ListNode* mergeNodes(ListNode* head) {
        
        vector<int> num;
        all(head,0,num);
        ListNode* curr = NULL;
        ListNode* temp = NULL;
        for(int i = 0 ; i < num.size();i++){
             ListNode* newnode = new ListNode(num[i]);
             if(curr == NULL){
                 curr = newnode;
                
             }else{
                 temp->next = newnode;
                 
                
             }
             temp = newnode;
        }
        return curr;
        
    }
    void all(ListNode* curr , int curr_sum , vector<int>& num){
            if(curr == NULL)
                return ;
        
            if(curr->val == 0 && curr_sum != 0){
                num.push_back(curr_sum);
                curr_sum = 0;
            }
          
           all(curr->next,curr_sum + curr->val,num);
        
        
        
    }
};