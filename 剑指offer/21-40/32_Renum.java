/*
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
则打印出这三个数字能排成的最小数字为321323。

*/

//自定义一个比较规则 两两比较的时候选择的是最小的组合方式
//字典序最小
import java.util.*;

public class Solution {
    public String PrintMinNumber(int [] numbers) {
        Comparator compare = new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				String s1 = "" + o1 + o2;
				String s2 = "" + o2 + o1;
				return s1.compareTo(s2);
			}

		};
		Integer[] ar_result = new Integer[numbers.length];
		for(int i = 0; i < numbers.length; i++) {
			ar_result[i] = numbers[i];
		}
    // 按照自定义的排序规则 进行数组排序
		Arrays.sort(ar_result, compare);

    String result = "";
		for(int num : ar_result) {
			result += num;
		}


		return result;
    }
}
