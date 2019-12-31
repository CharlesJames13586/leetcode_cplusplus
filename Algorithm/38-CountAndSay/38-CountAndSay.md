### 38. Count and Say

* The count-and-say sequence is the sequence of            integers with the first five terms as following:

  数并读序列是某种整数序列，下面列出它的前五个。

  >1.     1
  >2.     11
  >3.     21
  >4.     1211
  >5.     111221

  1 is read off as "one 1" or 11.

  11 is read off as "two 1s" or 21.

  21 is read off as "one 2, then one 1" or 1211.

  1 被读作 “一个1” 或 11；

  11 被读作 “两个1” 或 21；

  21 被读作 “一个2，一个1” 或 1211.

  Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

  给一个整数n(1=< n =< 30)，产生第n个数并读序列。你可以递归的求解，换句话说，从从前一个读出的数列中，数出每组相同数字的个数。

  Note: Each term of the sequence of integers will be represented as a string.

  注意：整数序列的每一项都将用字符串表示出来。

* **解题思路**
  
  本题是典型的递归题，而且题比较简单，把每个连在一个的相同数字用个数+该数的表达方法表示出来即可。

  需要注意的有两点，一、理解该题，在讨论区有不少人把题面理解错了。二、在该题中我使用了std::to_string()函数将数字转化为字符串，使用过程中发现该函数只能将数字类型的转化为字符串，char类型的参数会转化成其ASCII再转化成字符串。因为本题中的处理的数字是一位的，可以先将减去'0'，然后再转化成字符串。

  该题比较简单，不做过多赘述。

  以下是1-10的输出。

  >1<br>
  >11<br>
  >21<br>
  >1211<br>
  >111221<br>
  >312211<br>
  >13112221<br>
  >1113213211<br>
  >31131211131221<br>
  >13211311123113112211<br>