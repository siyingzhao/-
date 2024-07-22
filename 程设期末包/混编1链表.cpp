#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//结构体定义
typedef struct node
{
	int val;
	struct node* next;
}Node;
//链表打印
void printlist(Node *head) 
{
    Node *current = head;
    while (current->next != NULL) 
	{
        printf("%d->", current->val);
        current = current->next;
    }
	printf("%d\n", current->val);
}
//创建链表（单向）
Node* creat()
{
	Node *head=NULL,*tail=NULL;
	int value;
	while(1)
	{
		scanf("%d",&value);
		if(value==0)
			break;
		Node *current=head;
		Node *newnode=(Node*)malloc(sizeof(Node));
		newnode->val=value;
		newnode->next=NULL;

		if(head==NULL)
		{
			head=newnode;
			tail=newnode;
		}
		else
		{
			tail->next=newnode;
			tail=newnode;
		}
		printlist(head);
	}
	return head;
}
//交换节点位置（对内存的处理）
void exchange(Node** head,Node*a,Node*b)
{
	if(a==b) return;
	
	Node* prev1=NULL,*curr1=*head;
	Node* prev2=NULL,*curr2=*head;

	for(int i=1;curr1!=NULL&&curr1!=a;i++)
	{
		prev1=curr1;
		curr1=curr1->next;
	}

	for(int i=1;curr2!=NULL&&curr2!=b;i++)
	{
		prev2=curr2;
		curr2=curr2->next;
	}

	if (curr1 == NULL || curr2 == NULL) return;

	if(prev1!=NULL)
		prev1->next=curr2;
	else
		*head=curr2;

	if(prev2!=NULL)
		prev2->next=curr1;
	else
		*head=curr1;

	Node*temp=curr2->next;
	curr2->next=curr1->next;
	curr1->next=temp;
}
//排序（从小到大）
void sort(Node** head)
{
	Node*curr=*head,*index=NULL;
	if(*head==NULL)
		return;
	while(curr!=NULL)
	{
		index=curr->next;
		while(index!=NULL)
		{
			if(curr->val > index->val)
			{
				exchange(head,curr,index);
				curr=index;
			}
			index=index->next;
		}
		curr=curr->next;
	}
}
//删除一个节点（需要它的上一个节点）
Node* deleNode(Node* delNode, Node* prevNode)
{
	prevNode->next = delNode->next;
	Node* nextNode = delNode->next;
	free(delNode);
	return nextNode;
}
//倒序输出（递归思想）
void printReverse(Node* head) 
{
	if (head == NULL) {
		return;
	}
	printReverse(head->next);
	printf("%d\n", head->val);
}
// 释放链表
void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;       // 暂存当前节点
        head = head->next; // 移动到下一个节点
        free(temp);        // 释放暂存的节点
    }
}
//把链表二插入到链表一某个节点之后
Node* InsertInfor(Node* L1,Node* L2)
{
	int n,i=0,k=0;
	Node* L,p,q,s,u;
	scanf("%d",&n);
	p=L1->next;
	while(p!=NULL)
	{
		k++;
		p=p->next;
	}
	while(n<0||n>k)
	{
		printf("Out of valid range, please input again:");
		scanf("%d",&n);
	}
	s=L2;u=L2->next;
	while(u!=NULL)
	{
		s=s->next;
		u=u->next;
	}
	p=L1->next;
	while(n>1)
	{
		p=p->next;
		n--;
	}
	s->next=p->next;
	p->next=L2->next;
	free(L2);
	L=L1;
	return L;
}

int main()
{
	Node*head=creat();
	sort(&head);
	printlist(head);
	system("pause");
	return 0;
}