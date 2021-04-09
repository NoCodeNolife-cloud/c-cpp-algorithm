#pragma once
#include <iostream>
using namespace std;

typedef struct node {
	char data;
	struct node* next;
}LNode, * LinkList;

LinkList CreatLinkList() {
	char ch;
	LinkList list = NULL;
	cin >> ch;
	list = (LinkList)malloc(sizeof(LNode));
	list->data = ch;
	list->next = NULL;
	return list;
}

void insertList(LinkList* list, LinkList q, char e) {
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	p->data = e;
	if (!*list) {
		*list = p;
		p->next = NULL;
	}
	else {
		p->next = q->next;
		q->next = p;
	}
	return;
}

void DynamicSort(LinkList q) {
	LNode* p = q;
	int i, j, k = 0;
	char t;
	while (p) {
		k++;
		p = p->next;
	}
	p = q;
	for (i = 0; i < k - 1; i++) {
		for (j = 0; j < k - i - 1; j++) {
			if (p->data > p->next->data) {
				t = p->data;
				p->data = p->next->data;
				p->next->data = t;
			}
			p = p->next;
		}
		p = q;
	}
	return;
}