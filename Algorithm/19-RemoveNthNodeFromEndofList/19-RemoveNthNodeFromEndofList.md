### 19.Remove Nth Node From End of List
* Given a linked list, remove the n-th node from the end of list and return its head.

  给一个链表，删除倒数第n个节点然后返回链表的头。
* **Example:**
  >Given linked list: 1->2->3->4->5, and n = 2.<br>
  After removing the second node from the end, the linked list becomes 1->2->3->5.<br>

  >给一个链表：1->2->3->4->5，和变量n = 2。<br>
  >然后删除倒数第二个节点，原来的链表变为：1->2->3->5。<br>
  
* **Note:**

  Given n will always be valid.

  给出的变量n都是合法的。

* **Follow up:**

  Could you do this in one pass?

  你能一次通过吗？

* **解题思路**

  &emsp;&emsp;采用双指针法，使用last(用来检测是否扫描到链表的最后)，temp两个指针。在刚开始的时候，
  先让last扫描n+1个节点，然后temp和last一起向后扫描，待last扫到最后一个节点，temp节点
  指向了倒数n+1个节点，然后删除temp后继节点。为了让删除首元节点和其它节点操作相同，我
  们在链表前添加了一个附加空节点。

  &emsp;&emsp;本算法可以只扫描一遍就删除了倒数第n个节点，但是在实际运行中因为同时更新两个节点，和
  先扫描一遍链表求链表大小，再扫描一遍删除倒数第n个的方法实际运行时间差不多。但是该方
  法相对而言比较新颖一点。