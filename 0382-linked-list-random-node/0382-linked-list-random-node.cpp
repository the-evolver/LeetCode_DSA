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
    
    int len = 0;
    ListNode* curr;
    Solution(ListNode* head) {
        curr = head;
        len = length();
        
    }
    
    int getRandom() {
        
        int i  = 0 + (rand() % (len ));
        
        
        ListNode* temp = curr;
        int cnt = 0;
        while( cnt < i){
            cnt++;
            temp = temp->next;
        }
        i++;
        return temp->val;
        
    }
    int length(){
        ListNode* temp = curr;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */