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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* fptr = head;
        ListNode* sptr = head;
        
        while(fptr!= NULL && fptr->next != NULL){
            fptr = fptr->next->next;
            sptr = sptr->next;
        }
        
        return sptr;
        
    }
};