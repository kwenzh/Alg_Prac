/*
题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
*/

//num1,num2分别为长度为1的数组。传出参数
//将num1[0],num2[0]设置为返回结果
import java.util.*;

// 利用集合元素不重复这一点 偶数次的元素最终都会被移除
public class Solution {
    public void FindNumsAppearOnce(int [] array,int num1[] , int num2[]) {
        Set<Integer> numSet = new HashSet<>();
		 for(int num : array) {
			 if(numSet.add(num) == false){
				 numSet.remove(num);
			 }
		 }

		 Object[] result = numSet.toArray();
		 num1[0] = (int) result[0];
		 num2[0] = (int) result[1];
    }
}
