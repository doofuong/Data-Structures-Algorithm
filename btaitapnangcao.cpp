#include <iostream>
using namespace std;
struct Node
{   
	int data;
	Node* next;
};
Node* creatNode(int a)
{   
    Node* t = new Node;
    t->data = a;
    t->next=NULL;
	return t;
}
struct linklish
{
	Node* dau;
	Node* cuoi;
};
void creatlinklish(linklish& A)
{
	A.cuoi = NULL;
	A.dau = NULL;
}
void themcuoi(linklish& A, Node* N)
{
	if (A.dau == NULL)
	{
		A.dau = N;
		A.cuoi = N;
	}
	else
	{   
		A.cuoi->next = N;
		A.cuoi = N;
		N->next = A.dau;		
	}	
}
void choi(linklish& a,int t)
{   
    Node* k;
    Node* h; 
	while (a.dau != a.cuoi)
	{   h = a.dau;
		for(int i = 1;i<=t;i++)
		{ 
		  if (i == t) k = h;
		  h = h->next;	
		}
	if (t == 0) 
	{
	a.cuoi->next = a.dau->next;	
	a.dau = a.dau->next;
	}
	else
	if(k == a.dau)
	{
	a.cuoi = a.dau;	
	a.dau->next = a.dau->next->next;
	a.dau = a.dau->next;
	}
	else
	{   
	    k->next = h->next;
	    a.dau = k->next;
	    a.cuoi = k;
	}
	}
	cout<<a.dau->data;
}
int main()
{
	int n,m;
	linklish A;
	creatlinklish(A);
	cout<<"Nhap N va M: ";
	cin>>n>>m;
    for(int i = 1; i <= n;i++)
	{
		themcuoi(A,creatNode(i));
	}
	choi(A,m);
}

