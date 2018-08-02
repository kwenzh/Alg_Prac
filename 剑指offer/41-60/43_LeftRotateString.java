/*
题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，
请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/

//左移动字符串 循环数组的做法 下标减少取余 这是一种做法

public class Solution {
    public String LeftRotateString(String str,int n) {
         int str_len = str.length();
		 char result[] = new char[str_len];
		 char str_ar[] = str.toCharArray();

		 for(int i = 0; i < str_len; i++) {
			 result[(i + str_len - n) % str_len] = str_ar[i];
		 }

		 return new String(result);
    }
}
// 第二种做法 三次翻转字符串
string LeftRotateString(string str, int n) {
  if(str.length() <= 0) {
    return str;
  }
  reverse(str.begin(), str.begin() + n);
  reverse(str.begin() + n, str.end());
  reverse(str.begin(), str.end());

  return str;
}
