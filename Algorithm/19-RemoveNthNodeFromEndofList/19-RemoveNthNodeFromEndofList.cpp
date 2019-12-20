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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //加一个空节点，这样删除第一个节点和其它节点的操作就一样了
        ListNode header = ListNode(0);
        header.next = head;
        head = &header;
        //采用双指针法
        ListNode * temp = head;
        ListNode * last = head;
        //先将last往前走n步
        for (int i = 0; i < n+1; i++) {
            last = last->next;
        }
        //然后temp和last一起往后走，知道last走到最后，这时temp指向倒数第n个节点
        while (last != NULL) {
            temp = temp->next;
            last = last->next;
        }
        ListNode *del = temp->next;
        temp->next = temp->next->next;   //删除倒数第n个节点
        delete del;          //释放内存空间
        return head->next;
    }
};
//用于测试的主函数
int main() {
    ListNode head = ListNode(0);
    ListNode * temp = &head;
    int l = 0;
    cout << "请输入链表的长度：";
    cin >> l;
    cout << endl;
    int nodeVal = 0;
    for (int i = 0; i < l; i++) {
        cin >> nodeVal;
        temp->val = nodeVal;
        if (i != l-1) {
            temp->next = new ListNode(0);
            temp = temp->next;
        }
    }
    printList(&head);
    int n = 0;
    cout << "请输入要删除倒数第n个节点的n的值：";
    cin >> n;
    cout << endl;
    Solution solution;
    temp = solution.removeNthFromEnd(&head, n);
    printList(temp);
    return 0;
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