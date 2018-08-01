/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

*/

// 这和上一道题大同小异
// 还是反过来想 从高处往下跳
// 不过一次可以选择跳1,2,3,....,n阶台阶
// 那就循环递归
class Solution {
public:

      int count =  0;
      void jump(int number) {
          int i;
          if(number == 0) {
              count++;
              return;
          }
          if(number <= 0) {
              return;
          }

          for(i = 1; i <= number; i++) {
              jump(number - i);
          }
      }

      int jumpFloorII(int number) {
          jump(number);

          return count;
      }

};
