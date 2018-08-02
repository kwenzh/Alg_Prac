//题目描述
// 统计一个数字在排序数组中出现的次数。


class Solution {
public:

    // 统计一个数字k在排序数组中出现的次数
    // 思路：先二分查找 找到这样数字的位置
    // 然后双指针左右探查
    int GetNumberOfK(vector<int> data ,int k) {
    	int K_index;
    	int left;
    	int count = 0;
    	int right;

    	K_index = binarySearch(data, k);
    	if(K_index == -1) {
    		return count; //没有找到这样的数字在数组中
    	}
    	left = K_index;
    	right = K_index + 1;
    	while(left >= 0 && data[left] == k){
    		count++;
    		left--;
    	}
    	int len = data.size();
    	while(right < len && data[right] == k) {
    		count++;
    		right++;
    	}

        return count;
    }

    int binarySearch(vector<int> array, int targetValue) {
    	int array_length = array.size();
    	int a = 0;
    	int b = array_length - 1;

    	while(a <= b) {
    		int middle = (a + b) / 2;
    		if(array[middle] == targetValue) {
    			return middle;
    		}
    		array[middle] < targetValue ? (a = middle + 1) : (b = middle - 1);
    	}


    	return -1;
    }

};
