/*
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

*/


//
class Solution {
public:

    //判断一个序列 也就是数组是不是一个二叉搜索树的后序遍历结果
    //总体思路： 后序遍历序列根节点是最后一个
    // 第一步先找到第一个大于根节点的 index1 index1到根节点的这段就是右子树
    // 根据BST树的性质 右子树所有节点均大于根节点 左子树相反 判断这段序列是否都大于根节点
    // 继续根据index1 递归划分左右子树判断
    bool VerifySquenceOfBST(vector<int> sequence) {
    	int length = sequence.size();

    	return isDeBst(sequence, length);
    }

    bool isDeBst(vector<int> sequence, int length) {
    	if(length <= 0) {
    		return false;
    	}

    	int rootValue = sequence[length - 1];
    	int i;
    	int rightIndex;

    // 从序列头开始找 找到第一个大于根节点的
    	for(i = 0; i < length - 1 && sequence[i] < rootValue; i++);
    	rightIndex = i;
    //判断rightIndex到根节点这段序列的值是否都大于根节点
    	for(int j = rightIndex; j < length - 1; j++) {
    		if(sequence[j] < rootValue) {
    			return false;
    		}
    	}

    //对根节点左右子树递归判断是否满足二叉搜索树
    	bool left = true;
    	if(rightIndex > 0) {
    		left = isDeBst(sequence, rightIndex);
    	}

    	bool right = true;
    	if(length - rightIndex - 1 > 0) {
    		right = isDeBst(sequence, length - rightIndex - 1);
    	}

    	return left && right;
    }
};
