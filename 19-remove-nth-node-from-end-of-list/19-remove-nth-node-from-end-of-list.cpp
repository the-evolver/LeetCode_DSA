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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        if(n == len){
            // remove head
            return head->next;
        }
        
         if(n == 1){
            
            // remove tail
            ListNode* temp = head;
            
            while(temp ->next ->next != NULL){
                temp = temp->next;

            }
            
            temp->next = NULL;
            return head;
            
            
        }
            int nth_node = len - n + 1; // front se;
            int curr = 1;
             ListNode* tmp = head;
            while(curr != nth_node-1){
                 tmp = tmp->next;
                 curr++;
                
            }
            tmp->next = tmp->next->next;
            return head;
            
            
        
        
    }
};