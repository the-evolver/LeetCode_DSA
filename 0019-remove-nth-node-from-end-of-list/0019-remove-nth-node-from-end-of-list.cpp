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
        
        ListNode* temp = head;
        ListNode* fptr = temp;
        ListNode* sptr = temp;
        
        
        for(int j = 1 ; j <= n ; j++)
             fptr = fptr->next;
        
        if(fptr == NULL){
            // deletion at head
            head = head->next;
            delete temp;
            return head;
        }
        
        while(fptr->next != NULL){
                fptr = fptr->next;
                sptr = sptr->next;
           
        }
        
        ListNode* curr = sptr->next;
        sptr->next = sptr->next->next;
        delete curr;
        return head;
        
    }
};