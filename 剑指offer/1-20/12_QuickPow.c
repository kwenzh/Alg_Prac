/*
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

*/

// 快速幂算法 不谈了
double Power(double base, int exponent) {
    if(exponent >= 0) {
		double ans = 1.0;
		while(exponent) {
			if(exponent & 1) {
				ans = ans * base;
			}
			base = base *base;
			exponent = exponent >> 1;
		}

		return ans;
	}else {
		return 1.0 / Power(base, -1 * exponent);
	}
}
