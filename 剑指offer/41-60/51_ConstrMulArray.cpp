/*
题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。
*/

//看懂公式就没问题了  在LeetBook Code有做过
// 比如:2 4 5 6结果应该是120 60 48 20
// 第一遍的构造完了是: 1 2*1 2*4 2*4*5
// 然后开始第二遍的构造 用result[0]来存放一个乘数  这不能画图有点烦
/*
1         2*1       2*4     2*4*5
1         2*1       2*4*6   2*4*5
1         2*1*5*6   2*4*6   2*4*5
1*4*5*6   2*1*5*6   2*4*6   2*4*5
*/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int size = A.size();
        vector<int> result(size);
        int i;

        for(i = 1, result[0] = 1; i < size; i++) {
        	result[i] = result[i - 1] * A[i - 1];
        }

        for(i = size - 2, result[0] = A[size - 1]; i > 0; i--) {
        	result[i] = result[i] * result[0];
        	result[0] = result[0] * A[i];
        }

        return result;
    }
};
