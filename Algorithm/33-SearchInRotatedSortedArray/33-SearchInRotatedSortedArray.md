### 33.Search in Rotated Array

* 
  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

  (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

  You are given a target value to search. If found in the array return its index, otherwise return -1.

  You may assume no duplicate exists in the array.

  Your algorithm's runtime complexity must be in the order of O(log n).

  假定一个升序排列的数组以你未提前得知的基准点旋转。

  (例如： [0, 1, 2, 4, 5, 6, 7] 可能会变成 [4, 5, 6, 7, 0, 1, 2])。

  给你一个值去寻找它的位置，如果能在数组中找到它的位置就返回其位置下标，如果找不到就返回-1.

  你可以假设数组中没有重复的元素。

  你的算法的时间复杂度必须在O(log n)内。

* **Example 1:**

  >Input: nums = [4,5,6,7,0,1,2], target = 0
  >Output: 4

* **Example 2:**

  >Input: nums = [4,5,6,7,0,1,2], target = 3
  >Output: -1

* **解题思路：**

  其实这就是一个搜索问题，而且是已排好序数组的搜索问题。题干要求时间复杂度在O(log n)内，因此可以使用二叉搜索，它的时间复杂度即为O(log n)。这里关于搜索我再给出一种思路，哈希查找中解决冲突的二次散列法的启发思路，我们从头扫描，但跳的步长不是1，而是i<sup>2</sup>，当步长过长时，可以把步长再变为1，这个算法的时间复杂度也是O(log n)。

  当然这道题不是一个纯搜索问题，它将数组基于某个基准点进行了旋转，将数组分成了两大部分，因此我们需要先找出这个基准点，找基准点的方法也和上面搜索的方法类似，只需要注意一些细节就好。

  找到基准点后，判断target和nums[0]和nums[len-1]的关系，判断target在哪一截后直接搜索即可。

  注意未搜索成功返回“-1”。