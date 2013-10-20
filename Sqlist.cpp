//Sqlist.cpp
#define LIST_INIT_SIZE 100/*初始分配空间*/
#define LISRINCREMENT 10/*单位空间增量*/
#include "iostream"
#include "cstdlib"
using namespace std;
class Sqlist {
public:
	int *elem;/*存储基址*/
	int length;  /*当前数据长度*/
	int listsize;/*当前储存容量*/
	Sqlist(){/*初始化顺序表（默认存储空间100）*/
		elem=(int*)malloc(LIST_INIT_SIZE*sizeof(int));
		length=0;
		listsize=LIST_INIT_SIZE;
	}
	Sqlist(int i){/*带参数i初始化顺序表（存储空间为i+10）*/
		elem=(int*)malloc((i+LISRINCREMENT)*sizeof(int));
		length=i;
		listsize=i+LISRINCREMENT;
	}
	void show(){/*显示顺序表所有数据*/
		for(int i=0;i<length;i++)
			cout<<elem[i]<<' ';
		cout<<endl;
	}
	
	bool insert(int x,int d){/*在顺序表第x位置插入数据d*/
		ifadd(1);
		for(int i=length;i+2>=x;i--){
			elem[i+1]=elem[i];
		}
		elem[x-1]=d;
		length++;
		return true;
	}
	bool del(int x){/*删除第x位置的元素*/
		for(int i=x-1;i<=length;i++)
			elem[i]=elem[i+1];
		length--;
		return true;
	}
	bool ifadd(int x){/*判断增加x个数据是否超出空间，是则开辟10个空间*/
		if(listsize<x+length){
			int* newbase=(int*)realloc(elem,(listsize+LISRINCREMENT)*sizeof(int));
			if(!newbase)
				exit (001);/*无法分配更多存储空间*/
			elem=newbase;
			listsize+=LISRINCREMENT;
		}
		else return false;
		ifadd(x);
		return true;
	}
	int locate(int x){/*在顺序表中查找数据x存在则返回位置i，不存在返回0*/
		for(int i=0;i<=length;i++){
			if(elem[i]==x)
				return i;
		}
		return 0;
	}
	void remove(){/*移除顺序表的存储空间*/
		free(elem); 
		elem=NULL;
		length=listsize=0;
	}
	void clean(){/*列表数据全部清零*/
		for(int i=0;i<=length;i++)
			elem[i]=0;
		length=0;
	}
};
int main(int argc, char const *argv[])
{
	Sqlist a;
	for(int i=0;i<6;i++)
		a.elem[i]=i;
	a.length=6;
	a.show();
	a.insert(3,9);
	a.show();
	a.del(3);
	a.show();
	cout<<a.locate(4)<<endl;
	cout<<a.locate(8)<<endl;
	a.clean();
	a.show();
	a.remove();
	a.show();
	return 0;
}
