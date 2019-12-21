### 31.Next Permutation

* 
  &ensp;&ensp;Implement next permutation, which rearranges  numbers into the lexicographically next greater permutation of numbers.

  &ensp;&ensp;If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

  &ensp;&ensp;The replacement must be in-place and use only constant extra memory.

  &ensp;&ensp;Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

  >&ensp;&ensp;1,2,3 → 1,3,2<br>
  >&ensp;&ensp;3,2,1 → 1,2,3<br>
  >&ensp;&ensp;1,1,5 → 1,5,1<br>

  &emsp;&emsp;实现数列的后继全排列(next permutation)，即字典序中的下一个排列。

  &emsp;&emsp;如果不存在字典序中的后继全排列，那将该排列的后继全排列其定义为升序序列。

  &emsp;&emsp;元素必须在原地交换以及只允许使用固定的额外内存。

  &emsp;&emsp;下列有一些例子，左边一列是输入，右边一列是正确的输出。

  >&emsp;&emsp;1,2,3 → 1,3,2<br>
  >&emsp;&emsp;3,2,1 → 1,2,3<br>
  >&emsp;&emsp;1,1,5 → 1,5,1<br>

* **解题思路：**

  &emsp;&emsp;首先解释什么是后继全排列(next permutation)，后继全排列就是字典序中一个排列紧挨的下一个全排列就是题干中的后继全排列。同时题干中说明最后一个排列的后继全排列是升序排列，即字典序中的第一个全排列。以{1, 2, 3}为例，每个全排列和其后继全排列为：

  >&emsp;&emsp;1,2,3 → 1,3,2<br>
  >&emsp;&emsp;1,3,2 → 2,1,3<br>
  >&emsp;&emsp;2,1,3 → 2,3,1<br>
  >&emsp;&emsp;2,3,1 → 3,1,2<br>
  >&emsp;&emsp;3,1,2 → 3,2,1<br>
  >&emsp;&emsp;3,2,1 → 1,2,3<br>

  &emsp;&emsp;求解后继全排列：

  1.从排列末尾向前寻找第一个小于后继元素的元素下标，记为index。如1,2,3第一个小于后继元素的元素下标为1(2\<3，元素2的下标为1)；3,2,1所有元素都大于后继元素，因此下标为-1。

  2.当index>=0时，交换nums[index]和下标大于index中元素集合的最小值，只有这样才能找到后继(在计算机中，后继的意思为下一个)全排列。如1,2,3，交换index=1的元素2和下标大于index中的元素集合{3}中的最小值3；3,2,1，不交换。

  3.将交换后的数列下标大于index中的元素集合进行升序排列，这样才能保证这些元素的排列最小。

  &emsp;&emsp;总体来看，我们把全排列的数组看成一个十进制数，即将排列1,2,3看成123，由1,2,3三个数字组成的数字中，比123大的数字中最小的132对应的数列1,3,2就是所求的后继全排列。比321大的只有四位数了，其中中最小的为*123，取其后三位123，因此可以组成一个循环了。