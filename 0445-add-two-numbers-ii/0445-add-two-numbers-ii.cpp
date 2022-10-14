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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int len1 = length(l1);
        int len2 = length(l2);
        
        
        if(len1 > len2){
            int diff = len1-len2;
            ListNode* curr = l1;
            while(diff > 0){
                curr = curr->next;
                diff--;
            }
            int c = comp(curr,l2);
            int nc = recur(l1,curr,c);
            if(nc > 0){
             return insert(l1,nc);
         }
            return l1;
            
            
        }
        else if(len2 > len1){
        int diff = len2-len1;
        ListNode* curr = l2;
        while(diff > 0){
                curr = curr->next;
                diff--;
            }
        int c = comp(curr,l1);
        int nc = recur(l2,curr,c);
        if(nc > 0){
             return insert(l2,nc);
         }
        
        return l2;
        
    }
         int c = comp(l1,l2);
         if(c > 0){
             return insert(l1,c);
         }
         return l1;
        
        
    }
    int recur(ListNode* head,ListNode* temp , int c){
        if(head->next == temp){
           
        int val        =  (head->val + c)   ;
        int sum        =  val % 10;
        int new_carry  =  val / 10;
        head->val = sum;
        return new_carry;
            
            
        }
        int nc = recur(head->next,temp,c);
        int val        =  (head->val + nc)   ;
        int sum        =  val % 10;
        int new_carry  =  val / 10;
        head->val = sum;
        return new_carry;
        
        
        
        
    }
    int length(ListNode* curr){
        int cnt = 0;
        
        ListNode* temp = curr;
        while(temp != NULL){
            
            cnt++;
            temp = temp->next;
            
            
        }
            return cnt;
            
            
    }
    
    int comp(ListNode* curr1, ListNode* curr2){
        
        if(curr1->next == NULL && curr2->next == NULL){
            int sum   =  (curr1->val + curr2->val)  % 10 ;
            int carry =  (curr1->val + curr2->val)  / 10 ;
            
            curr1->val = sum;
            return carry;
            
            
        }
        int carry      =  comp(curr1->next,curr2->next);
        int val        =  (curr1->val + curr2->val + carry)   ;
        int sum        =  val % 10;
        int new_carry  =  val / 10;
        curr1->val = sum;
        return new_carry;
        
        
    }
    ListNode* insert(ListNode* head,int val){
        ListNode* temp = new ListNode(val);
        temp->next = head;
        return temp;
    }
};