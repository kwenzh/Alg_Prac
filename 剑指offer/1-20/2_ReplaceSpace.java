/*
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

// java处理字符串比c方便的多了 注意边界问题 当给出的字符串只有一个空格的情况
public class Solution {
    public String replaceSpace(StringBuffer str) {
      StringBuffer result_bf = new StringBuffer();
  		int str_length = str.length();
  		int begin = 0;
  		int i;

  		for(i = 0; i < str_length; i++) {
  			if(str.charAt(i) == ' ') {
  				result_bf.append(str.substring(begin, i) + "%20");
  				begin = i + 1;
  			}
  		}
  		if(begin != i) {
  			result_bf.append(str.substring(begin, i));
  		}

      	return result_bf.toString();
      }
}
