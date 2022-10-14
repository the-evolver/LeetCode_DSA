class Node{
    public:
    Node* next;
    int val;
    Node(int val){
        this->val = val;
        next = NULL;
    }
};



class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        Node* pos = NULL;
        Node* neg = NULL;
        Node* tp  = NULL;
        Node* tn  = NULL;
        
        for(int i = 0 ; i < n ; i++){
            
            if(nums[i] < 0){
                Node* curr = new Node(nums[i]);
                
                if(neg == NULL){
                    neg = curr;
                    tn = curr;
                }else{
                    tn -> next = curr;
                    tn = curr;
                    
                }
                
            }else{
                  Node* curr = new Node(nums[i]);
                  
                
                 if(pos == NULL){
                    pos = curr;
                    tp = curr;
                   }else{
                    tp -> next = curr;
                    tp = curr;
                    }
               }
        }
        
        
        
        
        Node* head = pos;
        Node* temp = head;
        pos = pos->next;
        while(neg != NULL || pos != NULL){
            if(temp->val > 0 && neg != NULL){
                temp->next = neg;
                neg = neg->next;
            }else if(pos != NULL && temp->val < 0){
                temp->next = pos;
                pos = pos->next;
            }
            temp = temp->next;
        }
        for(int i = 0 ; i < n ; i++){
            nums[i] = head->val;
            head = head->next;
        }
        return nums;
    }
};