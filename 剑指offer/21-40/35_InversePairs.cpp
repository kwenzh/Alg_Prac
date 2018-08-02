/*
题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
输入描述:

题目保证输入的数组中没有的相同的数字

数据范围：

	对于%50的数据,size<=10^4

	对于%75的数据,size<=10^5

	对于%100的数据,size<=2*10^5
*/


//这道题用 普通的做法 双层循环 遍历 可以统计出来次数，但是会超时，O(n^2)的时间复杂度显然不能满足需要。

// 归并排序的思路：把这个序列不断划分，合并的时候比较两个子序列的逆序对，合并的时候
// 那些子序列一定都是有序的，比较逆序对起来就容易的多了。
class Solution {
public:

    int InversePairs(vector<int> data) {
         int n = data.size();
         if(n <= 0) {
         	return 0;
         }

         vector<int> copy;
         for(int i = 0; i < n; i++) {
         	copy.push_back(data[i]);
         }

         long long count;
         count = merge(data, copy, 0, n - 1);


         return count % 1000000007;
    }

    long long merge(vector<int> &data, vector<int> &copy, int start, int end) {
    	if(start == end) {
    		copy[start] = data[start];
    		return 0;
    	}

    	int length = (end - start)/ 2;
    	long long left = merge(copy, data, start, start + length);
    	long long right = merge(copy, data, start + length + 1, end);

    	int i = start + length;
    	int j = end;
    	int indexcopy = end;
    	long long count = 0;
    	while(i >= start && j >= start + length + 1) {
    		if(data[i] > data[j]) {
    			copy[indexcopy--] = data[i--];
    			count = count + j -start - length;
    		}else{
    			copy[indexcopy--] = data[j--];
    		}
    	}

    	while(i >= start) {
    		copy[indexcopy--] = data[i--];
    	}

    	while(j >= start + length + 1){
    		copy[indexcopy--] = data[j--];
    	}

    	return left + right + count;
    }
};
