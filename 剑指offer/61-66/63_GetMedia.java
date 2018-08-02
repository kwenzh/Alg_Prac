/*题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，
使用GetMedian()方法获取当前读取数据的中位数。
*/

// 在添加数据的时候 用插入排序的方式  得到就是一个有序的序列 完了需要得到中位数的时候 判断奇偶 然后做计算
import java.util.*;

public class Solution {

  LinkedList<Integer> numList = new LinkedList<>();

	  public void Insert(Integer num) {
		 int listSize = numList.size();
		 int InsertIndex = 0;

		 for(; InsertIndex < listSize && num >= numList.get(InsertIndex); InsertIndex++);
		 numList.add(InsertIndex, num);
	  }

	  public Double GetMedian() {
      // 这个三目最好改成if/else
		  return (numList.size() & 1) == 1 ?
      Double.valueOf(numList.get(numList.size() / 2)) :
      Double.valueOf(numList.get(numList.size()/ 2) + numList.get((numList.size() / 2 )  - 1)) / 2;
	  }


}
