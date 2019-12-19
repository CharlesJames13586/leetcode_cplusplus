### 24. Swap Nodes in Pairs

* Given a linked list, swap every two adjacent nodes and return its head.

  You may not modify the values in the list's nodes, only nodes itself may be changed.

  给一个链表，交换两个相邻的节点并返回链表的头节点。

  你不能修改链表节点的值，只能修改链表的本身。

* **Example:**

  >Given 1->2->3->4, you should return the list as 2->1->4->3.
  
  >给一个链表 1->2->3->4，你应该返回2->1->4->3。

* **解题思路：**

  &emsp;&emsp;这是一道挺简单的题，本质上就是删除链表和插入链表的结合。
  注意在做链表的插入和删除时在链表头部添加一个附加空节点，
  这样，在首元节点前插入一个节点和首元节点的删除就会和其它
  节点的情况已知。

  <div align=center>
    <img src="24-SwapNodesinPairs_Resource/24-1.png" alt="交换链表相邻节点图解">
    <br>
    <strong>图24-1 交换链表相邻节点图解</strong>
  </div>