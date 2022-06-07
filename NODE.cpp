#include <stdio.h>

struct NODE {
	int data;
	struct NODE *pNext;
};

struct LIST {
	NODE *pHead;
	NODE *pTail;	
};

void Init(LIST &l) {
	l.pHead = l.pTail = NULL;	
};

NODE* CreateNode() {
	int x;
	printf("Nhap gia tri cho node: ");
	scanf("%d", &x);
	NODE *p=new NODE;
	p->data=x;
	p->pNext=NULL;
	return p;	
}

void AddHead(LIST &l, NODE *p) {
	if (l.pHead==NULL)
		l.pHead=l.pTail=p;
	else {
		p->pNext=l.pHead;
		l.pHead=p;
	}
}

void AddTail(LIST &l, NODE *p){
    if (l.pHead==NULL) {
        l.pHead=p;
        l.pTail=p;
    }
    else {
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void HienThiDS(LIST &l){
	for (NODE *p=l.pHead; p!=NULL; p=p->pNext)
		printf("%d\t", p->data);
}
void DeleteHead(LIST &l){
	NODE *p=new NODE;
    p = l.pHead;
    l.pHead = l.pHead->pNext;
    p->pNext = NULL;
    delete p;
}

void DeleteTail(LIST &l)
{
    for(NODE *k = l.pHead; k != NULL; k = k ->pNext)
    {
        if(k->pNext == l.pTail)
        {
            delete l.pTail;
            k->pNext = NULL;
            l.pTail = k;
        }
    }
}

int main() {
	LIST l;
	Init(l);
	int n;
	printf("Nhap so luong phan tu cua danh sach: ");
	scanf("%d", &n);
	int i = 1;
	while (i<=n) {
		NODE *p=new NODE;
		p=CreateNode();
//		AddHead(l,p);
		AddTail(l,p); 
		i++;
	}
	printf("Danh sach da nhap: \t");
	HienThiDS(l);
	
//	DeleteHead(l);
	DeleteTail(l);
	printf("\nDanh sach da xoa: \t");
	HienThiDS(l);
}
