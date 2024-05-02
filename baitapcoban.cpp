#include <iostream>
#include <string.h>
using namespace std;
struct Ngay
{
	int x,y,z;
};
struct Sinhvien
{
	char maSV[9];
	char hoTen[50]; 
	int gioiTinh; 
	Ngay ngaySinh; 
	char diaChi[100]; 
	char lop[12]; 
	char khoa[7];
};
struct Node
{   Sinhvien data;
	Node* next;
};
Node* creatNode(Sinhvien a)
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
void themdau(linklish& A, Node* N)
{
	if (A.dau == NULL)
	{
		A.dau = N;
		A.cuoi = N;
	}
	else
	{   
		N->next= A.dau;		
		A.dau= N;
	}
	
}
void thembatky(linklish& A, Node* N)
{
	Node* b;
	b = A.dau;
	while(b->next != NULL)
	{   
		if (strcmp(b->next->data.maSV, N->data.maSV) >= 0) break;
		b = b->next;
	}
	if (b==A.dau & A.dau->data.maSV== N->data.maSV) 
	{
		N->next= b;
		A.dau = N;	
	}
	else
	{
		N->next= b->next;
		b->next = N;
	}
}
void xuatSV(Sinhvien a)
	{
	cout<<"Ma sinh vien: "<<a.maSV<<endl;
	cout<<"Ho va ten: "<<a.hoTen<<endl;
	cout<<"Gioi tinh 0 la nam va 1 la nu: "<<a.gioiTinh<<endl;
	cout<<"Ngay/thang/nam sinh: "<<a.ngaySinh.x<<"/"<<a.ngaySinh.y<<"/"<<a.ngaySinh.z<<endl;
	cout<<"Dia chi: "<<a.diaChi<<endl;
	cout<<"Lop: "<<a.lop<<endl;
	cout<<"Khoa: "<<a.khoa<<endl;
	}
void xuat(linklish A)
{
	Node* t;
	int h=1;
	t = A.dau;
	while(t != NULL)
	{   
	    cout<<"STT: "<<h<<endl;
		xuatSV(t->data);
		t = t->next;
		h = h + 1;
	}
}
Sinhvien nhapSV()
	{
	Sinhvien a;
	cout<<"Nhap ma sinh vien: ";
	cin.getline(a.maSV,9);
	cout<<"Nhap ho va ten: ";
	cin.getline(a.hoTen,50);
	cout<<"Nhap gioi tinh 0 la nam va 1 la nu: ";
	cin>>a.gioiTinh;
	cout<<"Nhap ngay/thang/nam sinh: ";
	cin>>a.ngaySinh.x>>a.ngaySinh.y>>a.ngaySinh.z;
	cin.ignore();
	cout<<"Nhap dia chi: ";
	cin.getline(a.diaChi,100);
	cout<<"Nhap lop: ";
	cin.getline(a.lop,12);
	cout<<"Nhap khoa: ";
	cin.getline(a.khoa,7);
	return a;
	}
void sapxep(linklish& a)
{   
    Node* i; Node* j;
	Sinhvien t;
	for(i = a.dau;i != NULL;i = i->next)
	for(j = i->next;j!= NULL;j = j->next)
	if (strcmp(i->data.maSV,j->data.maSV) > 0)
	{
		t = i->data;
		i->data=j->data;
		j->data=t;
	}
}
void sapxep1(linklish& a)
{   
    Node* i; Node* j;
	Sinhvien t;
	for(i = a.dau;i != NULL;i = i->next)
	for(j = i->next;j!= NULL;j = j->next)
	if (i->data.ngaySinh.x > j->data.ngaySinh.x)
	{
		t = i->data;
		i->data=j->data;
		j->data=t;
	}
}
void xuat1(linklish A)
{
	Node* t;
	int h=1,g = 0,k=0;
	t = A.dau;
	while(t != NULL)
	{ 
	  if(t->next == NULL && g == 1)  
		{
		cout<<"STT: "<<h<<endl;
		h = h + 1;
		xuatSV(t->data);
		break;
		}
	else
	{
	  if(t->next==NULL) break;
	  if (t->data.ngaySinh.x == t->next->data.ngaySinh.x)
	  	{
		    cout<<"STT: "<<h<<endl;
		    h = h + 1;
			xuatSV(t->data);
			k = 1;
			g = 1;
		}	
		else 
		if (g == 1)	
		{
		cout<<"STT: "<<h<<endl;
		xuatSV(t->data);
		h = h + 1;
		g = 0;
		}
	t = t->next;
	}
	}
	if (k == 0) cout<<"khong tim thay"<<endl;
}
void xoaNode(linklish& a)
{
	Node* i;
	int t = 0;
	while(a.dau->data.ngaySinh.x== a.dau->next->data.ngaySinh.x)
	{
		a.dau = a.dau->next;
		t = 1;
	}
	if (t == 1) a.dau = a.dau->next;
	i = a.dau;
	t = 0;
    while (i->next != NULL) 
    {
    while (i->next->data.ngaySinh.x == i->next->next->data.ngaySinh.x && i->next->next != a.cuoi)
	{   
		i->next = i->next->next;
		t = 1;
	} 
	if (i->next->next == a.cuoi && a.cuoi->data.ngaySinh.x == i->next->data.ngaySinh.x) 
	{  
		a.cuoi = i;
		i->next = NULL;
		break;
	} 
	if ( t == 1) i->next = i->next->next;
	if (i->next->next == a.cuoi && a.cuoi->data.ngaySinh.x == i->next->data.ngaySinh.x) 
	{  
		a.cuoi = i;
		i->next = NULL;
	} 
	if (i->next->next == a.cuoi) break;
	i = i->next;
    }
}
int main()
{   
    struct Sinhvien a;
    string t;
	linklish A;
	creatlinklish(A);
	t = "N";
	cout<<"Nhap thong tin sinh vien: "<<endl;
	while(t != "Y")
	{
		themdau(A,creatNode(nhapSV()));
		cout<<"Nhap N neu ban muon nhap them Sinhvien, Y neu ban ko muon nhap them Sinhvien"<<endl;
		getline(cin,t);
	}
	sapxep(A);
	xuat(A);
	cout<<"Nhap them sinh vien: "<<endl;thembatky(A,creatNode(nhapSV()));
	cout<<"Danh sach sinh vien sau khi them: "<<endl;
	xuat(A);
	cout<<"Sinh vien co cung ngay sinh: "<<endl;
    sapxep1(A); xuat1(A);
    cout<<"Danh sach sau khi xoa: "<<endl;
    xoaNode(A); xuat(A);
   
}

