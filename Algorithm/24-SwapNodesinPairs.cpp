#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode;
void printList(ListNode *head);

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		//在头部添加一个附加空节点，使首元节点的删除与在首元节点前插入一个节点和其它节点的操作一致；
		ListNode header = ListNode(0);
		header.next = head;
		head = &header;
		ListNode * pre = head;         //指向附加空节点，首元节点的前一个
		ListNode * cur = head->next;   //指向首元节点
		//当 当前节点 存在并且有 后继节点 时
		while (cur!=NULL && cur->next != NULL) {
			pre->next = cur->next;     //将当前节点从链表中断开
			cur->next = pre->next->next;         //将当前节点的原后继节点的后继节点赋给当前节点
			pre->next->next = cur;     //将当前节点再放置回链表
			//pre向前走两个，cur向前走一个
			pre = cur;       //更新pre指针
			cur = cur->next; //更新cur指针
		}
		//返回时注意去掉附加空节点
		return head->next;
	}
};

//用于测试的主函数
int main() {
	//输入一个链表
	ListNode * head = &ListNode(0);
	ListNode * temp = head;
	int l = 0;
	cout << "请输入链表的长度：";
	cin >> l;
	cout << endl;
	int nodeVal = 0;
	for (int i = 0; i < l; i++) {
		cin >> nodeVal;
		temp->val = nodeVal;
		if (i != l - 1) {
			temp->next = new ListNode(0);
			temp = temp->next;
		}
	}
	printList(head);
	//交换链表相邻节点
	Solution solution;
	head = solution.swapPairs(head);
	printList(head);         //输出交换后的链表
}

//输出链表
void printList(ListNode *head) {
	ListNode * temp = head;
	while (temp != NULL) {
		cout << temp->val;
		temp = temp->next;
		if (temp != NULL) {
			cout << "->";
		}
		else {
			cout << endl;
		}
	}
}