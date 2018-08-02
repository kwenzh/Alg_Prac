/*
题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}；
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
 {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
 {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/


//根据数组长度和给出的滑动窗口大小会计算 包含几个滑动窗口 然后分别找小区间内的最大值
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
  vector<int> result;
  if(size <= 0) {
    return result;
  }
  int numSize = num.size();
  int resultLength = numSize - size + 1;

  for(int i = 0; i < resultLength; i++) {
    int max = num[i];
    for(int j = i; j <  size + i; j++) {
      max = num[j] > max ? num[j] : max;
    }
    result.push_back(max);
  }

  return result;
}
