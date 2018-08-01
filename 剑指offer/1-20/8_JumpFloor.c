/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

// 逆向考虑 从高处往低处跳
// 一次可以下1个台阶 也可以下2个台阶 那就递归
// 给一个静态或者全局变量记录种类

int count =  0;

void jump(int number) {
    if(number == 0) {
        count++;
        return;
    }
    if(number <= 0) {
        return;
    }

    jump(number - 1);
    jump(number - 2);
}
int jumpFloor(int number) {
    jump(number);

    return count;
}
