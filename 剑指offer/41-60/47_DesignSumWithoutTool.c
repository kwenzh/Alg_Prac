/*
题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

//不得使用循环 和判断 只能考虑用递归当做循环 而终止条件则是用的短路运算 这是很巧妙的 这一点要学习
int Sum_Solution(int n) {
    n && (n += Sum_Solution(n - 1));

    return  n;
}
// 也可以用空间来算
// 底层还是有乘法  5*6/2 = (n)(n+1)/2 求和公式
bool a[n][n+1];
return sizeof(a)>>1;
