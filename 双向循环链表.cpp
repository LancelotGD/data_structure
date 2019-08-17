#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct node {
	int num;
	struct node *pre, *next;
}node;

void description() {
	printf("1�������µ�Ԫ��(Ҫ��Ϊ�ɿ�������)\n2��ɾ��һ��Ԫ��\n3����ʾ����\n4������һ��Ԫ���Ƿ���������\n5��ɾ�����������˳�\n");//�û�������ʾ
}

void showlist(node* head) {//�������ӡ����
	if (head != NULL) {
		node* tail = head->pre;
		node* temp = NULL;
		if (head->next == head) {
			printf("%d\n", head->num);
		}
		else {
			for (temp = head; temp->next != head&&temp->next!=NULL; temp = temp->next) {
				printf("%d ", temp->num);
			}
			printf("%d\n", temp->num);
			for (temp = tail; temp->pre != tail; temp = temp->pre) {
				printf("%d ", temp->num);
			}
			printf("%d\n", temp->num);
		}
	}
}

node* nodeBuild(int size) {//����Ľ���
	node *head=NULL;
	if (size <= 0) {
		printf("error");
	}
	else if(size==1){				//size==0,1,2����
		node* p = (node*)malloc(sizeof(node));
		p->num = 0;
		p->next = p;
		p->pre = p;
		head = p;
	}
	else {
		node* p = (node*)malloc(sizeof(node));
		p->num = 0;
		p->next = p;
		head = p;
		node* prepointer = head;
		for (int i = 1; i < size; i++) {
			node* temp = (node*)malloc(sizeof(node));
			temp->num = i * i;
			temp->pre = prepointer;
			prepointer->next = temp;
			temp->next = head;
			prepointer = temp;
		}
		p->pre = prepointer;
	}
	return head;
}

node* listinsert(node* head,int number) {
	double root = sqrt(number);
	int k = (int)root;
	if (number < 0) {
		printf("�������Ϊ����\n");
	}
	else if (k*k != number) {
		printf("����������޷�����\n");
	}
	else {
		node* temp = head;
		if (number <= head->num) {
			node* newp = (node*)malloc(sizeof(node));
			newp->num = number;
			newp->next = head;
			newp->pre = head->pre;
			head->pre->next = newp;
			head->pre = newp;
			head = newp;
		}
		else if (number >= (head->pre)->num) {
			node *newp = (node*)malloc(sizeof(node));
			newp->num = number;
			newp->pre = head->pre;
			(head->pre) -> next = newp;
			newp->next = head;
			head->pre = newp;
		}
		else {
			int i = number;
			while (i > temp->num) { temp = temp->next; }
			node* newp = (node*)malloc(sizeof(node));
			newp->num = number;
			(temp->pre)->next = newp;
			newp->pre = temp->pre;
			newp->next = temp;
			temp->pre = newp;
		}
	}
	return head;
}

node* listdelete(node* head, int number) {
		int flag = 0;//��ʼû����Ѱ���������
		node* temp = head->next;
		node* p = temp;
		do {
			if (head->num == number) {
				head->pre->next = head->next;
				head->next->pre = head->pre;
				p = head;
				head = head->next;
				free(p);
				flag = 1;
			}
			else if (temp->num == number) {
				flag = 1;
				(temp->pre)->next = temp->next;
				(temp->next)->pre = temp->pre;
				p = temp;
				temp = temp->next;
				free(p);
			}
			else {
				temp = temp->next;
			}
		} while (temp != head && temp->num <= number);
		if (flag == 1)
			printf("�Ѿ��ɹ�ɾ���ڵ㡣\n");
		else
			printf("����������Ҫɾ���Ľڵ㡣\n");
		return head;
	
}

void alldelete(node* head) {
	while (head != NULL&&head->next!=head) {
		head=listdelete(head, head->next->num);
	}
	free(head);
	printf("�Ѿ��ɹ�ɾ���ڵ㡣\n");
}

void listsearch(node* head,int number) {//�����Ƿ���Ŀ�����������������ӡ����
	int count = 0;
	node* temp = head;
	if (head->pre->num == number) {
		count++;
	}
	while (temp->next != head) {
		if (temp->num == number)
			++count;
		temp = temp->next;
	}
	if (count == 0)
		printf("��������Ҫ���ҵ���");
	else
		printf("�������%d��������������", count);
}

int main() {
	int operation,size;
	printf("��������Ҫ����������Ĵ�Сn����nΪ������n����0��");
	scanf_s("%d", &size);
	node* head = nodeBuild(size);
	showlist(head);
	description();//1�������µ�Ԫ��\n2 ��ɾ��һ��Ԫ��\n3����ʾ����\n\4������һ��Ԫ���Ƿ���������
	int number;
	int quit = 0;
	while (scanf_s("%d", &operation)&&quit!=1 ){
		switch (operation)
		{
		case 1:
			printf("������Ҫ�����Ԫ�أ�\n");
			scanf_s("%d", &number);
			head=listinsert(head, number);
			showlist(head);
			description();
			break;
		case 2:
			printf("������Ҫɾ����Ԫ�أ�\n");
			scanf_s("%d", &number);
			if (head->next == head&&number==head->num) {
				free(head);
				printf("�Ѿ�ɾ���������������˳�");
				quit = 1;
			}
			else {
				head = listdelete(head, number);
				showlist(head);
				description();
			}
			break;
		case 3:
			showlist(head);
			description();
			break;
		case 4:
			printf("������Ҫ���ҵ�Ԫ�أ�\n");
			scanf_s("%d", &number);
			listsearch(head, number);
			description();
			break;
		case 5:
			alldelete(head);
			quit = 1;
			break;
		default:
			printf("ERROR����������ȷ�Ĳ�������");
			break;
		}
		if (quit == 1)
			break;
	}
	return 0;
}