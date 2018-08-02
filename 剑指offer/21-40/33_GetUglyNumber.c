/*
题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

*/

/*
这个对丑数的定义不是很清晰，其实丑数就是拿这个数字分别连续除以2,3,5，直到除不尽了，
看最后剩下的数字是不是1，是1 就是丑数。比如10，除以2，为5了，3没法除，除以5等于1,这个数就是丑数。

如果直接求第n个丑数，逐个从1判断n个丑数，这样子会超市，每次都要判断这个数字是不是丑数。

丑数从1开始分别是：1,2,3,4,5,6,8,9,10，.........所有的丑数都可以通过2,3,4的倍数来实现，
1除外，那么可以直接去生成第n个丑数，要得到第n个丑数，申请一个长度为n的数组，
去生成这个数组的每个元素，数组第一个元素就是1，第二个元素在1*2,1*3,1*5中诞生取最小，依次可以生成整个数组。
*/
int min3Num(int a, int b, int c)
{
  return (a <b ? a : b) < c ? (a <b ? a : b) : c;
}
int GetUglyNumber_Solution(int index) {
  int *array;
  int count2 = 0;
  int count3 = 0;
  int count5 = 0;
  int i;

  array = (int *)calloc(sizeof(int), index);
  array[0] = 1; //规定第一个丑数是1

  for(i = 1; i < index; i++) {
    array[i] = min3Num(array[count2] * 2, array[count3] * 3, array[count5] * 5);

    if(array[i] == array[count2] * 2) {
      count2++;
    }
    if(array[i] == array[count3] * 3) {
      count3++;
    }
    if(array[i] == array[count5] * 5) {
      count5++;
    }
  }
  i = array[index - 1];
  free(array);
  array = NULL;

  return i;
}
