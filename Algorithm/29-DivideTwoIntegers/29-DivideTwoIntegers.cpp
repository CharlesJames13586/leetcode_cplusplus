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
		int sign = 1;        //商的符号，1代表(+)，-1代表(-)
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
	//讨论区的一个优秀解法的重新编写。
	int divide(int dividend, int divisor) {
		if (dividend == 0) {
			//如果商为0，直接返回0
			return 0;
		}
		switch (divisor){
		    case 0:
			    //如果除数为0，直接退出
			    exit(-1);
		    case 1:
		        //如果除数为1，直接返回被除数，还避免了dividend=-2147483648，divisor=1时的情况
			    return dividend;
	        case -1:
		        //除数为-1的情况
			    if (dividend == INT32_MIN) {
				    return INT32_MAX; 
			    } else {
				    return -dividend;
			    }
		}
		
		long long quotient = 0;        //商，使用long类型避免运算过程中的溢出现象
		int sign = 1;        //商的符号，1代表(+)，-1代表(-)
		if (dividend > 0 && divisor < 0 || dividend < 0 && divisor>0) {
			//如果被除数和除数异号，商的符号为负
			sign = -1;
		}
		//一般情况
		long long dividend_abs = abs((long long)dividend), divisor_abs = abs((long long)divisor);          //取被除数和除数的绝对值运算
		while (dividend_abs >= divisor_abs) {    //当被除数大于等于除数
			long long temp = divisor_abs, m = 1; //temp暂存除数的绝对值，m暂存商的部分值
			while (temp << 1 <= dividend_abs) {  //除数乘2(左移一位)后小于等于被除数时
				//temp <<= 1;
				//m <<= 1;
				temp = temp << 1;      //除数乘2
				m = m << 1;  //m乘2
				//cout << temp << ' ' << m << endl;
			}
			dividend_abs = dividend_abs - temp;  //被除数减除数
			quotient = quotient + m;   //商加上暂存的商
		}
		if (quotient > INT32_MAX) {
			quotient = INT32_MAX;
			//注：商=INT32_MIN的情况已在除数为1时返回，因此此处不会存在这种情况
		}

		//return quotient * sign;      题面要求不能使用乘法(不过leetcoe该题并未检测此种情况)
		return sign > 0 ? quotient : -quotient;  //判断sign的符号返回商
	}
};

//用来测试的主函数
int main() {
	
	int dividend = 0, divisor = 1, quotient = 0;
	//gdb调试时无法输出中文，所以将提示信息改为中文
	//cout<<"请输入被除数：";
	cout<<"Please enter the dividend:";
	cin >> dividend;
	cout << endl;
	//cout << "请输入除数：";
	cout<<"Please enter the divisor:";
	cin >> divisor;
	cout << endl;
	Solution solution;
	quotient = solution.divide(dividend, divisor);
	//cout << "商：" << quotient << endl;
	cout<<"The quotient is "<< quotient << endl;
	
	return 0;
}