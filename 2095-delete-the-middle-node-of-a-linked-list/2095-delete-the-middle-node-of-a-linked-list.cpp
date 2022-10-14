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
        if(head -> next == NULL)
            return NULL;
       ListNode* fptr = head;
       ListNode* sptr = head;
       ListNode* mptr = NULL;
        
      while(fptr != NULL && fptr->next!=NULL){
          fptr = fptr->next->next;
          mptr = sptr;
          sptr = sptr->next;
      }
      
      mptr->next = sptr->next;
      sptr->next = NULL;
      delete sptr;
      return head;

    }
};