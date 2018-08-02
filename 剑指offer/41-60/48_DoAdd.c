/*
题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

//用位运算做加法  核心通过异或 注意进位
int Add(int num1, int num2)
{
  int carry_data = num1 & num2;
  int result = num1 ^ num2;

  while(carry_data != 0) {
      int temp = result;
      result = result ^ (carry_data << 1);   //相当于相加
      carry_data = temp & (carry_data << 1); //进位数据
  }

  return result;
}
