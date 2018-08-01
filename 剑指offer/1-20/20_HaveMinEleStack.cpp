/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

*/

// 要求时间复杂度位O(1)  所以需要另外的空间记录当前栈中最小的元素
// 可以设计栈的时候加上这一成员 也可以用另外相同的一个栈 专门记录最小元素
// 入栈的时候更新这个记录最小元素的栈即可
class Solution {
public:
     stack<int> dataStack, minStack;
    void push(int value) {
        dataStack.push(value);
        if (minStack.empty()) {
            minStack.push(value);
        }
        else{
            int min = minStack.top();
            value<=min?minStack.push(value):minStack.push(min);
        }

    }
    void pop() {
        dataStack.pop();
        minStack.pop();
    }
    int top() {
        return  dataStack.top();
    }
    int min() {
        return minStack.top();
    }
};
