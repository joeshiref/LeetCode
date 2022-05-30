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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode cur=head;
        head=cur;
        int len=0;
        while(cur!=null)
        {
            len++;
            cur=cur.next;
        }
        //System.out.println(len);
        
        int indexOfWantedNode=len-n;
        System.out.println(indexOfWantedNode);

        cur=head;
        for(int i=0;i<indexOfWantedNode-1;i++)
            cur=cur.next;
        
        //System.out.println(cur.val);
        if(indexOfWantedNode==0)
            head=head.next;
        else
            cur.next=cur.next.next;
        
        
        return head;
    }   
}