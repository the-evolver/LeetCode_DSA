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
private:
    
    ListNode* mergeTwoLists(ListNode* first, ListNode* second){
        if(!first) return second;
        if(!second) return first;        
        
        if(first->val < second->val){
            first->next = mergeTwoLists(first->next, second);
            return first;
        }
        else{
            second->next = mergeTwoLists(first, second->next);
            return second;
        }
    }
    
public:    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        
        // traversing over the lists
        for(int itr = 1; itr < lists.size(); itr++){
            lists[0] = mergeTwoLists(lists[0], lists[itr]);
        }
        
        return lists[0];
    }
};