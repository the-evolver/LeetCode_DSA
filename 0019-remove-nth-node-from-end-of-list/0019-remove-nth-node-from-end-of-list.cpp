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
    
        int len = length(head);
        int i = len - n + 1;
        
        ListNode* temp = head;
        
        if(i == 1){ // deletion at head
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return head;
        }
        
        int j = 1;
        while( j < i - 1){
            temp = temp -> next;
            j++;
        }
        
        ListNode* ptr = temp->next;
        temp->next = ptr->next;
        ptr->next = NULL;
        delete ptr;
        
        return head;
        
    }
    
    int length(ListNode* head){
        
        ListNode* temp = head;
        int cnt = 0 ;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
};