/*题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
那么对应的输出是第一个重复的数字2。*/

//找粗来第一个重复的数字 统计各个数字出现的次数 一旦找到了第一个重复出现的返回就完了
class Solution {
public:

  bool duplicate(int numbers[], int length, int* duplication) {
    if(length <= 1) {
      return false;
    }

    int *temp = (int *)calloc(sizeof(int), length);
    for(int i = 0; i < length; i++) {
      if(temp[numbers[i]] == 0) {
        temp[numbers[i]]++;
      }else {
        *duplication = numbers[i];

        return true;
      }
    }

    free(temp);

    return false;
    }
};
