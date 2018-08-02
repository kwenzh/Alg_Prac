/*
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/


//已知数组是有序的, 保证乘积最小 两数距离最大 这是要点
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
     	vector<int> result;
    	int begin = 0;
    	int end = array.size() - 1;

    	while(begin < end) {
    		int add = array[begin] + array[end];

    		if(add == sum) {
    			result.push_back(array[begin]);
    			result.push_back(array[end]);

    			return result;
    		}

    		if(add > sum) {
    			end--;
    		}
    		if(add < sum) {
    			begin++;
    		}
    	}

    	return result;
    }
};
