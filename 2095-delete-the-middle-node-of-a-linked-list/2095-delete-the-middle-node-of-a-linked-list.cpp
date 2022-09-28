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
    ListNode* deleteMiddle(ListNode* head) {
        
        int len = length( head);
        int mid = (len / 2);
        
        if(len == 1)
            return NULL;
        
        int curr = 0;
        ListNode* temp = head;
        while(curr != mid - 1){
             curr++;
             temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
       
        
    }
    
    int length(ListNode* head){
        int curr = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            curr++;
        }
        return curr;
    }
};