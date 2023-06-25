/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == headB)
            return headA;
        
        int len1 = length(headA);
        int len2 = length(headB);
        
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        if(len1 > len2){
            
                int diff = len1 - len2 ;
                while(diff){
                    temp1 = temp1->next;
                    diff--;
                }
        }
        else{
           
                int diff = len2 - len1 ;
                while(diff){
                    temp2 = temp2->next;
                    diff--;
                }
        
        }
        
        if(temp1 == temp2)
            return temp1;
        
        while(temp1 != NULL && temp2 != NULL && temp1->next != temp2->next){
            
             temp1 = temp1->next;
             temp2 = temp2->next;
            
            
        }
        if(temp1 == NULL || temp2 == NULL)
            return NULL;
        
        return temp1->next;
        
        
        
        
        
    }
    
    int length(ListNode* head){
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
};