### 29. Divide Two Integers

* Given two integers dividend and divisor, divide two integers 
  without using multiplication, division and mod operator.

  Return the quotient after dividing dividend by divisor.

  The integer division should truncate toward zero.

  给两个整数：被除数和除数，不使用乘法、除法和模运算做两数相除运算。

  返回**被除数**÷**除数**运算后的**商**。

  除法运算的结果的值应**向0取整**。

* **Example1:**
  
  >Input: dividend = 10, divisor = 3<br>
  >Output: 3
  
  >输入：被除数 = 10，除数 = 3<br>
  >输出：3
* **Example2:**

  >Input: dividend = 7, divisor = -3<br>
  >Output: -2

  >输入：被除数 = 7，除数 = -3<br>
  >输出：-2

* **Node:**

  1. Both dividend and divisor will be 32-bit signed integers.
  2. The divisor will never be 0.
  3. Assume we are dealing with an environment which could only 
     store integers within the 32-bit signed integer range: 
     [−2^31^,   2^31^−1]. For the purpose of this problem, 
     assume that your function returns 2^31^−1 when the division
     result overflows.

  &ensp;
  1. 被除数和除数都是32位有符号整数；
  2. 除数不会是0；
  3. 假设我们运行的环境只能存储[-2^31^, 2^31^-1]区间内的32位有符号的整数。
     这个问题的目的是：假定当除法结果溢出时，你的函数返回2^32^-1。

* **解题思路：**

  * 方法一
  
    &emsp;&emsp;暴力求解：如果除数和被除数同号(异号)，商为正(负)，被除数减(加)
    除数，如果减过的被除数不变号，商加一，否则跳出循环。

    &emsp;&emsp;记得处理商的溢出。在除数为不为0整数的情况下，只有(被除数为-2^32，
    除数为-1)时会溢出。
    
    &emsp;&emsp;暴力解决在提交代码时会有运行超时的测试样例。
    
    >error C4146: 一元负运算符应用于无符号类型，结果仍为无符号类型
    
    &emsp;&emsp;暴力解决的代码在VS2017的编译器编译时会出现如上问题。原因是因为在执行**dividend == -2147483648**判断条件时，-2147483648是4字节int的最小值，逻辑上没有问题(有的编译器中也没有问题)，但是在VS的编译器中，编译器先判断-2147483648的
    绝对值2147483648与int(4字节)最大值(值为2147483647)的大小。因为|-2147483648| > INT_MAX
    所以就会将|-2147483648|的类型变为unsigned int，再根据原来的值是负数，将值再取反进行表达式的判断，因此会出现上述错误。

    &emsp;&emsp;为了避免这样的错误，我们只需要将表达式**dividend == -2147483648**变为**dividend + 1 == -2147483647**，就可以编译通过了。
   
    &emsp;&emsp;需要说明的是：表达式**dividend == -2147483648**在leetcode的编译器中是被允许的，暴力解决无法被Accept是因为当运行时间过长。
    

  * 方法二
 
    &emsp;&emsp;讨论区的一个题解的改进，[点击这里](https://leetcode.com/problems/divide-two-integers/discuss/13407/C%2B%2B-bit-manipulations)。

    &emsp;&emsp;此解使用的解法算是一个变相的暴力解法吧，巧妙的使用了左移运算达到\*2的效果，对除数\*2，相应的给m(暂存商的值)加上对应的值，当除数大于被除数时，被除去减去此时的除数，把m值加到记录最终商的变量(quotient)中，把除数变回初试值进行下一轮运算。
    
    &emsp;&emsp;C++标准中long的位数大于等于int的位数，因此，在代码中我使用了long long类型，因为long类型可能和int位数一样造成溢出。不过看链接里的程序说明leetcode所使用的编译器long类型是大于32位的。
    
* **附：**

  &emsp;&emsp;题面说不让用乘法、除法和取模运算，方法二的原作者用到了乘法运算，比如说：**sign * ans**。很是尴尬了，其实也是用判断sign的正负和与0的加减法代替乘。这些都是很小的细节，无伤大雅，但是谨防在面试中谈到后一时没有解决方法。
  
    