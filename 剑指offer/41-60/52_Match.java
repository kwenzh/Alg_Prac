/*
题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

//动态规划求解 说实话 这道题我不会 这是网上别人代码 相当于自己实现一个match函数 java中现成的函数
// 看别人代码还没看懂 先放在这这里
public class Solution {
    public boolean match(char[] str, char[] pattern)
    {
      boolean[][] dp = new boolean[str.length + 1][pattern.length + 1];
      dp[0][0] = true;
      for (int i = 1; i < dp[0].length; i ++) {
          if(pattern[i - 1] == '*') {
            dp[0][i] = dp[0][i - 2];
          }
      }
      for (int i = 1; i < dp.length; i ++) {
          for (int j = 1; j < dp[0].length; j ++) {

              if(pattern[j - 1] == '.' || pattern[j - 1] == str[i - 1]){
                  dp[i][j] = dp[i - 1][j - 1];
              }
              else if(pattern[j - 1] == '*') {
                  if(pattern[j - 2] != str[i - 1] && pattern[j - 2] != '.') {
                    dp[i][j] = dp[i][j - 2];
                  }
                  else {
                    dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
                  }
              }
          }
      }
      return dp[str.length][pattern.length];
    }
}
