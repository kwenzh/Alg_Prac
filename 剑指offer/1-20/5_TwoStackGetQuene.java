/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

import java.util.Stack;

public class Solution {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();

    public void push(int node) {
       stack1.push(node);
    }

    //用两个栈实现一个队列 出栈的时候，把一个栈里面的元素全部倒入另外一个栈里面去
    // 出栈完了之后要倒回来 
    public int pop() {
    	while(!stack1.isEmpty()) {
    		stack2.push(stack1.pop());
    	}
        stack1.clear();
    	int result = stack2.pop();
    	while(!stack2.isEmpty()) {
    		stack1.push(stack2.pop());
    	}

    	return result;
    }
}
