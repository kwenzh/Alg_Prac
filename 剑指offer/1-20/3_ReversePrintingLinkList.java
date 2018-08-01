/**
*    public class ListNode {
*        int val;
*        ListNode next = null;
*
*        ListNode(int val) {
*            this.val = val;
*        }
*    }
*
题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

*/
import java.util.ArrayList;
import java.util.Stack;

// 逆序打印可以用递归 也可以用栈完成
// 递归的本质就是压栈 出栈 相比于递归 用一个栈显然要更安全
public class Solution {
    ArrayList<Integer> list = new ArrayList<>();
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {


		if(listNode != null) {
			printListFromTailToHead(listNode.next);
			list.add(listNode.val);
		}

		return list;
    }
}
