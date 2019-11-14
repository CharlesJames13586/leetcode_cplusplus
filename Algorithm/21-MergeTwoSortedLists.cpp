#include "pch.h"
#include <iostream>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
public:
	//使用递归方法，比较简单清晰，但比较费内存。
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode *l = new ListNode(0);
		if (l1->val < l2->val) {
			l->val = l1->val;
			l->next = this->mergeTwoLists(l1->next, l2);
			return l;
		}
		else {
			l->val = l2->val;
			l->next = this->mergeTwoLists(l1, l2->next);
			return l;
		}

	}
};


/*
归并排序
Merge two sorted linked lists and return it as a new list.The new list should be made by splicing together the nodes of the first two lists.

Example:

    Input: 1->2->4, 1->3->4
	Output : 1->1->2->3->4->4
*/