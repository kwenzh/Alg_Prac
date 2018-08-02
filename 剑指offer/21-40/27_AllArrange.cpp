/*
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:

输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

*/


/*
全排列问题 还是递归

*/
class Solution {
public:
    vector<string> result;

    vector<string> Permutation(string str) {
    	if(str.length() == 0) {
    		return result;
    	}


    	ArrangeMent(0, str);
      sort(result.begin(), result.end());

    	return result;
    }

    void ArrangeMent(int n, string str) {
    	int str_length =str.size();

    	if(n == str_length - 1) {

    		result.push_back(str);
    	}else {

    		for(int i = n; i < str_length; i++) {
                 if(i!=n && str[i]==str[n]) {//有重复字符时，跳过
                    continue;
                }
            // 核心代码
          swapChar(&str[i], &str[n]);
    			ArrangeMent(n + 1, str);
          swapChar(&str[i], &str[n]);
    		}
    	}
    }

    void swapChar(char *x, char *y) {
    	char temp = *x;
    	*x = *y;
    	*y = temp;
    }

};
