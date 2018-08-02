/*
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:

如果当前字符流没有存在出现一次的字符，返回#字符。

*/

//输入字符串的时候就记录各个字符的出现次数

public class Solution {
    //Insert one char from stringstream
  private  StringBuffer str_bf = new StringBuffer(); //存放字符的地方
  private  int count[] = new int[256];   //统计各个字符出现次数的数组

	public void Insert(char ch)
	{
		str_bf.append(ch);
		count[ch]++;
	}
	public char FirstAppearingOnce()
	{
		char all_str[] = str_bf.toString().toCharArray();

	    for(char ch : all_str) {
	    	if(count[ch] == 1) {
	    		return ch;
	    	}
	    }

	    return '#';
	}

}
