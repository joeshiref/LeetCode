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
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null)
            return head;
        TreeSet<Integer> st = new TreeSet<Integer>();
        while(head!=null)
        {
            st.add(head.val);
            head=head.next;
        }
        ListNode res = new ListNode();
        ListNode ans = new ListNode();
        ans=res;
        Iterator itr = st.iterator();
      
        while(itr.hasNext())
        {
            Object element = itr.next();
            //System.out.println(element);
            res.val=(int)element;
            if(itr.hasNext())
                res.next=new ListNode();
            res=res.next;
        }
        return ans;

    }
}