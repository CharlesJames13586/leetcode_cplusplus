#include "pch.h"
#include <iostream>

using namespace std;

class Solution {
public:
	//暴力运算，可以实现除法，但是当测试数据很大时运行时间过长
	int divide_BruteForce(int dividend, int divisor) {
		if (divisor == 0) {
			//如果除数为0，直接退出
			exit(-1);
		}
		if (dividend == 0) {
			//如果商为0，直接返回0
			return 0;
		}
		int quotient = 0;
		int sign = 1;    //商的符号，1代表(+)，-1代表(-)
		if (dividend > 0 && divisor < 0 || dividend < 0 && divisor>0) {
			//如果被除数和除数异号，商的符号为负
			sign = -1;
		}
		//处理溢出问题
		if (dividend + 1 == -2147483647 && sign == -1) {
			//正溢出
			return 2147483647;
		}
		int temp;
		temp = dividend - divisor * sign;
		while (dividend > 0 && temp >= 0 || dividend < 0 && temp <= 0) {
			//cout << dividend << ' ' << temp << ' ' << quotient << endl;
			//处理溢出问题
			if ((quotient == 2147483647 && sign == 1) || (quotient +1 == -2147483647 && sign == -1)) {
				break;
			}
			quotient = quotient + sign;
			dividend = temp;
			temp = dividend - divisor * sign;
		}
		return quotient;
	}
	//讨论区的一个优秀解法的重新编写
	int divide(int dividend, int divisor) {
		if (divisor == 0) {
			//如果除数为0，直接退出
			exit(-1);
		}
		if (dividend == 0) {
			//如果商为0，直接返回0
			return 0;
		}
		if (divisor == 1) {
			//如果除数为1，直接返回被除数，还避免了dividend=2147483647，divisor=1时中间变量的溢出问题
			return dividend;
		}
		//处理溢出
		if (divisor == -1) {
			if (dividend == INT_MIN) {
				return INT_MAX;
			}
			else {
				return -dividend;
			}
		}
		
		int quotient = 0;    //商
		int sign = 1;        //商的符号，1代表(+)，-1代表(-)
		if (dividend > 0 && divisor < 0 || dividend < 0 && divisor>0) {
			//如果被除数和除数异号，商的符号为负
			sign = -1;
		}
		//一般情况
		int dividend_abs = abs(dividend), divisor_abs = abs(divisor);          //取被除数和除数的绝对值运算
		while (dividend_abs >= divisor_abs) {   //当被除数大于除数
			int temp = divisor_abs, m = 1;
			while (temp << 1 <= dividend_abs) {  //除数乘2后与被除数相比
				//temp <<= 1;
				//m <<= 1;
				temp = temp << 1;      //除数乘2
				m = m << 1;  //m乘2
				cout << temp << ' ' << m << endl;
			}
			dividend_abs = dividend_abs - temp;  //被除数减除数
			quotient = quotient + m;
		}

		//return quotient * sign;      题面要求不能使用乘法(不过leetcoe该题并未检测此种情况)
		return sign > 0 ? quotient : -quotient;  //判断sign的符号返回商
	}
};

//用来测试的主函数
int main() {
	
	int dividend = 0, divisor = 1, quotient = 0;
	cout << "请输入被除数：";
	cin >> dividend;
	cout << endl;
	cout << "请输入除数：";
	cin >> divisor;
	cout << endl;
	Solution solution;
	quotient = solution.divide(dividend, divisor);
	cout << "商：" << quotient << endl;
	
	return 0;
}