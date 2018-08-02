/*
题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,
你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:

输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

*/



import java.util.ArrayList;

//由两个指针控制序列的前后端 begin len 然后根据求和公式计算s 当s大于sum时就需要前移动begin 继续添加所有满足要求的序列
public class Solution {
    public ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {
       ArrayList<ArrayList<Integer>> result = new ArrayList<>();
  		int begin = 1;
  		int len = begin + 1;

  		for(; len <= sum /2 + 1 ; len++) {
  			int s = (begin + len) * (len - begin + 1) / 2; //求和公式
  			if(s == sum) {
  				ArrayList<Integer> Sum_list = new ArrayList<>();
  				for(int i = begin; i <= len; i++) {
  					Sum_list.add(i);
  				}
  				result.add(Sum_list);
  			}
  			if(s > sum) {
  				begin++;
  				len = begin;
  			}
  		}


		    return result;
    }
}
