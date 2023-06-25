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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int len = length(head);
        
        return rev(head,k,len);
        
    }
    
    ListNode* rev(ListNode* temp , int k , int remLen){
        if(remLen < k)
            return temp;
        
        ListNode* curr = temp;
        ListNode* nxt = NULL;
        ListNode* prev = NULL;
        
        int i = 1;
        while( i != k){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            i++;
        }
        nxt = curr->next;
        curr->next = prev;
        temp->next = rev(nxt,k,remLen-k);
        return curr;
        
        
        
        
    }
    
    int length(ListNode* head){
        
        int cnt = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            temp = temp->next;
            cnt++;
            
        }
        return cnt;
    }
};