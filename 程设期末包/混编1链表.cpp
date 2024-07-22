#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�ṹ�嶨��
typedef struct node
{
	int val;
	struct node* next;
}Node;
//�����ӡ
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
//������������
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
//�����ڵ�λ�ã����ڴ�Ĵ���
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
//���򣨴�С����
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
//ɾ��һ���ڵ㣨��Ҫ������һ���ڵ㣩
Node* deleNode(Node* delNode, Node* prevNode)
{
	prevNode->next = delNode->next;
	Node* nextNode = delNode->next;
	free(delNode);
	return nextNode;
}
//����������ݹ�˼�룩
void printReverse(Node* head) 
{
	if (head == NULL) {
		return;
	}
	printReverse(head->next);
	printf("%d\n", head->val);
}
// �ͷ�����
void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;       // �ݴ浱ǰ�ڵ�
        head = head->next; // �ƶ�����һ���ڵ�
        free(temp);        // �ͷ��ݴ�Ľڵ�
    }
}
//����������뵽����һĳ���ڵ�֮��
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