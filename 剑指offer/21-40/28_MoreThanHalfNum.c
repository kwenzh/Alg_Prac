/*
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
超过数组长度的一半，因此输出2。如果不存在则输出0。

*/

/*
同样在LeetCode里面遇到过，不需要统计的每个元素出现次数的做法，需要一个count表示次数，
初始化为0，开始设这个出现次数超过一半元素的数字就是数组第一个，然后开始遍历数组，然后是从数组第二个也就是下标为1开始

如果数组当前元素和当前主要元素不同，那么count就需要自减1，相同就自加。

如果count到0，就需要更换了主要元素为数组当前元素。

这样的一遍遍历完了之后，如果count大于0，说明存在主要元素，再遍历一遍数组统计一下这个主要元素的次数，
是否真的超过了一半，是只统计上一步得到的这个主要元素的出现次数。
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> array) {
      int array_length = array.size();
    	int i;
    	int majority = array[0];
    	int count = 1;
    	int counter;

    	for(i = 1 ; i < array_length; i++) {
    		if(count == 0) {
    			majority = array[i];
    			count++;
    		}else {
    			count += (majority == array[i]) ? 1 : -1;
    		}
      }

//对已经得到的元素进行进一步的判断
//如果给出的数组元素没有存在主要元素 就返回-1
    	if(count <= 0) {
    		return 0;
    	}else {
    		for(i = 0, counter = 0; i < array_length; i++) {
    			if(majority == array[i]) {
    				counter++;
    			}
    		}
    	}

	   return (counter > (array_length / 2)) ? majority : 0;
    }
};
