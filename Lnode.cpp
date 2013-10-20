// Lnode.cpp
#include "iostream"
#include "cstdlib"
using namespace std;
struct Node{/*双向链表节点的结构体*/
	int data;
	Node* up;
	Node* next;
};
class Lnode{
public:
	Node *p;/*指向链表头的指针*/
	int length; /*链表长度*/
	Lnode(){/*默认初始化链表长度为1*/
		length=1;
		p=(Node*)malloc(sizeof(Node));
		p->next=p;
		p->up=p;
	}
	Lnode(int x){/*带参数x初始化长度为x的链表*/
		length=x;
		Node *h;
		h=p=(Node*)malloc(sizeof(Node));
		for (int i = 0; i < x - 1; ++i)
		{
			p->next=(Node*)malloc(sizeof(Node));
			(p->next)->up=p;
			p=p->next;
		}
		h->up=p;
		p->next=h;
		
	}
	Node* find(int x){/*查找第x个节点返回指向当前节点的指针*/
		Node* a=p;
		for (int i = 1; i < x; ++i){
			a=a->next;
		}
		return a;
	}
	Node* findd(int data){/*查找数据data，如找到数据返回当前指针，没找到返回NULL*/
		Node* a=p;
		int b=0;
		for (int i = 0; i < length; ++i){
			if(a->data==data){
				b=1;
				break;
			}
			a=a->next;
		}
		if(b==0)
			a=NULL;
		return a;

	}
	Node* insert(Node* x){/*在链表节点x前插入新节点，返回新节点指针*/
		Node* b=(Node*)malloc(sizeof(Node));
		length++;
		b->up=x->up;
		b->next=x;
		(x->up)->next=b;
		x->up=b;
		return b;
	}
	void insert(int x,int d){/*在链表第x位置插入新节点且数据储存为d*/
		Node* a=p;
		for (int i = 1; i < x; ++i){
			a=a->next;
		}
		Node* b=insert(a);
		if(x==1) {
			p=b;
		}
		b->data=d;
	}
	void del(int x){/*删除链表第x位置的节点*/
		Node *a=find(x);
		if(a==p){
			p=p->next;
		}
		(a->next)->up=a->up;
		(a->up)->next=a->next;
		free(a);
		length--;
	}
	void deld(int x){/*删除数据为x的第一个结点*/
		Node *a=findd(x);
		if(a==p){
			p=p->next;
		}
		(a->next)->up=a->up;
		(a->up)->next=a->next;
		free(a);
		length--;
	}
	void show(){/*显示所有结点数据*/
		Node* a=p;
		for (int i = 0; i < length; ++i)
		{
			cout<<a->data<<' ';
			a=a->next;
		}
		cout<<endl;
	}
};
int main(int argc, char const *argv[])
{
	Lnode a(10);
	Node *q=a.p;
	for (int i = 0; i < 10; ++i)
	{
		q->data=i;
		q=q->next;
	}
	a.show();
	a.insert(1,99);
	a.show();
	// a.insert(11,90);
	// a.show();
	a.del(1);
	a.show();
	a.deld(0);
	a.show();
	// a.deld(7);
	// a.show();
	// a.del(1);
	// a.deld(0);
	// a.show();
	// system("pause");
	return 0;
}
