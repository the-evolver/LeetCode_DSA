/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(head.next==null) return head;
        if(left==right) return head;
        ListNode temp = head;
        ListNode prev = head;
        int len=1;
        while(temp.next!=null){
            temp=temp.next;
            len++;
        }
        temp=head;
        //System.out.println(len);
        for(int i=1;i<left;i++){
            prev = temp;
            temp=temp.next;
        }
        ListNode prevStart = prev;
        
        prev=null;
        ListNode nex = null;
        for(int i=left;i<right+1;i++){
            nex=temp.next;
            temp.next=prev;
            prev=temp;
            temp=nex;
            
        }
        if(left!=1)prevStart.next=prev;
        if(len!=right){
            temp=head;
            while(temp.next!=null){
                temp=temp.next;
            }
            temp.next=nex;
        }
        //System.out.println(prev.val);
        //System.out.println(temp.val);
        //System.out.println(nex.val);
        if(left==1) return prev;
       
        return head;
    }
}