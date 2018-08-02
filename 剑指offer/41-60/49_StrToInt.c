/*
题目描述
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。
 数值为0或者字符串不是一个合法的数值则返回0。
输入描述:

输入一个字符串,包括数字字母符号,可以为空

输出描述:

如果是合法的数值表达则返回该数字，否则返回0

示例1
输入
复制

+2147483647
    1a33

输出
复制

2147483647
    0

*/

//没有太多复杂的逻辑 细心即可 c提供有字符串转化的函数atoi java有Integer.valueOf()要是用这个 那你就很呆
int judgeSign(char ch) {
	if(ch == '+') {
		return 0;    //带符号正数
	}else if('0' <= ch && ch <='9') {
		return 1;   //无符号正数
	}else if(ch == '-') {
		return 2;   //负数
	}else {
		return -1;
	}

}

int isNumber(char ch) {
	return '0' <= ch && ch <='9';
}

int StrToInt(string str) {

	int len = str.length();
	if(len <= 0) {
		return 0;
	}

	int sign = judgeSign(str[0]);
	if(sign == -1) {
		return 0;
	}
	int numlength = len;
	int beginIndex = 0;
	if(sign == 0 || sign == 2) {
		numlength--;
		beginIndex++;
	}
	int power = (int)pow(10, numlength - 1);
	int result = 0;
	for(; beginIndex <len; beginIndex++){
		char ch = str[beginIndex];
		if(isNumber(ch) == 0) {
			return 0;
		}
		result = result + (ch - '0') * power;
		power = power / 10;
	}

    return sign == 2 ? -result : result;
}
