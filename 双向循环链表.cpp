#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct node {
	int num;
	struct node *pre, *next;
}node;

void description() {
	printf("1、插入新的元素(要求为可开方整数)\n2、删除一个元素\n3、显示链表\n4、查找一个元素是否在链表中\n5、删除整个链表并退出\n");//用户操作提示
}

void showlist(node* head) {//正反序打印链表
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

node* nodeBuild(int size) {//链表的建立
	node *head=NULL;
	if (size <= 0) {
		printf("error");
	}
	else if(size==1){				//size==0,1,2……
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
		printf("输入的数为负数\n");
	}
	else if (k*k != number) {
		printf("输入的数字无法开方\n");
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
		int flag = 0;//初始没有找寻到适配的数
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
			printf("已经成功删除节点。\n");
		else
			printf("链表不包含所要删除的节点。\n");
		return head;
	
}

void alldelete(node* head) {
	while (head != NULL&&head->next!=head) {
		head=listdelete(head, head->next->num);
	}
	free(head);
	printf("已经成功删除节点。\n");
}

void listsearch(node* head,int number) {//搜索是否含有目标参数，如果是则将其打印出来
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
		printf("链表不含所要查找的数");
	else
		printf("链表包含%d个符合条件的数", count);
}

int main() {
	int operation,size;
	printf("请输入所要创建的链表的大小n：（n为整数且n大于0）");
	scanf_s("%d", &size);
	node* head = nodeBuild(size);
	showlist(head);
	description();//1、插入新的元素\n2 、删除一个元素\n3、显示链表\n\4、查找一个元素是否在链表中
	int number;
	int quit = 0;
	while (scanf_s("%d", &operation)&&quit!=1 ){
		switch (operation)
		{
		case 1:
			printf("请输入要插入的元素：\n");
			scanf_s("%d", &number);
			head=listinsert(head, number);
			showlist(head);
			description();
			break;
		case 2:
			printf("请输入要删除的元素：\n");
			scanf_s("%d", &number);
			if (head->next == head&&number==head->num) {
				free(head);
				printf("已经删除所有链表，即将退出");
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
			printf("请输入要查找的元素：\n");
			scanf_s("%d", &number);
			listsearch(head, number);
			description();
			break;
		case 5:
			alldelete(head);
			quit = 1;
			break;
		default:
			printf("ERROR：请输入正确的操作数！");
			break;
		}
		if (quit == 1)
			break;
	}
	return 0;
}