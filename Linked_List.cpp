#include<iostream>
#include"Linked_List.h"
void LISTNODE::createNode(ListNode* node) {

	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;

	ListNode *p, *s;
	int x = -1;
	int i = 0;
	while (1)
	{
		printf("�����һ�������ڵ��ֵ��");
		std::cin >> x;
		if (x == 0)
			break;
		s = (ListNode*)malloc(sizeof(ListNode));	// sΪָ��ڵ��ָ��
		p = (ListNode*)malloc(sizeof(ListNode));	// sΪָ��ڵ��ָ��
		s->val = x;
		if (++i == 1) {
			head->next = s;
			s->next = NULL;
		}
		else
		{
			head->next = s;
			s->next = p;
		}
		p = s;
	}
}

void LISTNODE::deleteNode(ListNode* node) {
	node->val = node->next->val;
	node->next = node->next->next;
}

ListNode* LISTNODE::reverseList(ListNode* head) {
	ListNode* pre = NULL;
	ListNode* cur = head;

	while (cur != NULL)
	{
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}

ListNode* LISTNODE::middleNode(ListNode* head) {
	ListNode* pre = head;
	ListNode* cur = pre->next;
	while (cur != NULL)
	{
		if (cur->next) {
			cur = cur->next->next;
		}
		else
		{
			cur = cur->next;
		}
		pre = pre->next;
	}
	return pre;
}

ListNode* LISTNODE::mergeTwoLists(ListNode *l1, ListNode *l2) {
	if (l1 == NULL)return l2;
	if (l2 == NULL)return l1;

	if (l1->val < l2->val) {
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

//83. ɾ�����������е��ظ�Ԫ��
ListNode* LISTNODE::deleteDuplicates(ListNode* head) {
	if (head != NULL) {
		ListNode* cur = head;
		ListNode* next = head->next;
		while (next != NULL)
		{
			if (cur->val == next->val)
			{
				cur->next = next->next;
				next = next->next;
			}
			else
			{
				cur = next;
				next = next->next;
			}
		}
	}
	return head;
}

//24. �������������еĽڵ�
//!swapPairs�����������ı��еĽڵ�
/*
*���ܣ�ʵ��ÿ���ڵ������ڵ�֮��ĺ���
*˵��������Ĺؼ�������4���ڵ����
*������
		pram��ListNode* head
		return: ListNode* ָ��ͷ�ڵ�
*���ߣ�
		tztang
*�ο����ϣ�
		https://blog.csdn.net/my_clear_mind/article/details/81865061
*���ڣ�
        2019-01-15
"""
* ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
*/
ListNode * LISTNODE::swapPairs(ListNode * head)
{
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head;
	ListNode* cur = dummyHead;
	while (cur->next != NULL&&cur->next->next != NULL)
	{
		ListNode* node1 = cur->next;
		ListNode* node2 = node1->next;
		ListNode* next = node2->next;
		node2->next = node1;
		node1->next = next;
		cur->next = node2;
		cur = node1;
	}
	return dummyHead->next;
}
