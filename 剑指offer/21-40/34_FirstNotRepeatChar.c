/*
题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

*/

//统计各个字符次数 然后找到出现一次的
int FirstNotRepeatingChar(string str) {
  int chCount[256] = {0};
  int i;

  for(i = 0; str[i]; i++) {
    chCount[str[i]]++;
  }

  for(i = 0; str[i]; i++){
    if(chCount[str[i]] == 1) {
      return i;
    }
  }

  return -1;
}
