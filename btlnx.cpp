#include<bits/stdc++.h>
using namespace std;



// tim kiem theo ten sp
// sap xep theo thu tu giam dan cua don gia

// quan ly nhan vien 
struct nhanvien{
	int manv;
	char tennv[25];
	int tuoi;
	char gt[10], que[25], hcong[5];
	int  heSL,luong,TT;
};
struct nodenv{
	nhanvien infornv;
	struct nodenv*nvnext;
};
typedef struct list{
	nodenv*nvhead;
}LISTNV;
	LISTNV NV;
void khoitaonv(LISTNV &NV){
		NV.nvhead=NULL;
}
nodenv *newnodenv(nhanvien &nv){
	nodenv*p= new nodenv;
	p->infornv= nv;
	p->nvnext=NULL;
	return p;
}
void nhapnv( nhanvien &nv){
		fflush(stdin);
	cout<<"Ma nhan vien: ";
	cin>> nv.manv;
	cin.ignore();
		fflush(stdin);
	cout<<"Ten nhan vien: ";
	gets(nv.tennv);
		fflush(stdin);
	cout<<"Gioi tinh: ";
	gets(nv.gt);
		fflush(stdin);
	cout<<"Tuoi: ";
	cin>>nv.tuoi;
	cin.ignore();
		fflush(stdin);
	cout<<"Que quan: ";
	gets(nv.que);
		fflush(stdin);
	cout<<"Ca Lam(sang/chieu/toi): ";
	gets(nv.hcong) ;
		fflush(stdin);
	cout<<"He so luong: ";
	cin>>nv.heSL;
	nv.TT=nv.heSL*2300000;
	cout<<endl;
}
void hiennv(nhanvien nv){
 	cout<< setw(5)<< nv.manv<< setw(20)<<nv.tennv<< setw(19)<<nv.tuoi<< setw(19)<< nv.gt << setw(18)<<nv.que<<setw(18)<<setw(18)<<nv.hcong<<setw(18)<<nv.heSL*2300000<<endl;
}
int isemptynv(){
	if( NV.nvhead==NULL){
	return 0;
	}else{
	return 1;
	}
}
void deleteh(LISTNV &NV){
	nodenv*p;
	if(isemptynv() != NULL){
		p=NV.nvhead;
		NV.nvhead->nvnext=NV.nvhead;
		delete p;
	}else{
		cout<<"NULL!";
	}
}
void topnv(LISTNV NV){
	if(isemptynv()==0){
		cout<<"NULL!";
	}else{
		cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
		hiennv(NV.nvhead->infornv);
		}
}
void pushnv(nodenv*p){
	if(isemptynv()==0){
		NV.nvhead=p;
	}else{
			p->nvnext=NV.nvhead;
			NV.nvhead=p;
	}
}
void nhapdsnv(LISTNV &NV){
	int ok;
	nodenv*p;
	nhanvien nv;
	do{
		nhapnv(nv);
		p=newnodenv(nv);
		pushnv(p);
		p=p->nvnext;
		cout<<"CHON 1 NEU BAN MUON TIEP TUC , CHON 0 NEU BAN MUON KET THUC: ";
		
		cin>>ok;
		cout<<endl;
	}while( ok!=0);
}
void themnv(LISTNV &NV){
	int ok;
	nodenv*p;
	nhanvien nv;
	
		nhapnv(nv);
		p=newnodenv(nv);
		pushnv(p);
		p=p->nvnext;
		cout<<endl;
	
}
void capnhatnv(LISTNV &NV){
	int ok;
	nodenv*p= NV.nvhead;
	nhanvien nv;
	cout<<"Nhap ma nhan vien can cap nhat: ";cin>>ok;
	for(p;p!=NULL;p=p->nvnext)
	if(p->infornv.manv==ok){
		nhapnv(p->infornv);
		cout<<endl;}
		
	
}
void hiendsnv(LISTNV NV){
	nodenv*p=NV.nvhead;
	 cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;

	while(p!=NULL){
	hiennv(p->infornv);
	p=p->nvnext;
	}
}
void luufnv( LISTNV NV){
	nhanvien nv;
	nodenv*p=NV.nvhead;
	fstream finv;
	cin.ignore();
	char tenf[25];
	cout<<"Nhap ten file muon luu: ";
	gets(tenf);
	cout<<"luu thanh cong vao file "<<tenf<<endl<<endl;
	finv.open(tenf, ios :: app | ios :: binary);
	while(p!=NULL){
	finv.write((char*)&p->infornv, sizeof(nv));
	p=p->nvnext;
	}
finv.close();
}
void docfnv(LISTNV &NV){
	nhanvien nv;
	nodenv*p=NV.nvhead;
	cin.ignore();
	char tenf[25];
	cout<<"Nhap ten file muon mo: ";
	gets(tenf);
	fstream fonv;
	fonv.open(tenf, ios:: in | ios::binary);
	if( fonv.fail()){
	cout<<"Mo file loi!";
	}else{
	while(!fonv.eof()){
		fonv.read((char*)&nv, sizeof(nhanvien));
		p=newnodenv(nv);
	pushnv(p);
}
	hiendsnv(NV);
}
	fonv.close();
}
// tinh tong luong nhan vien
int sumluong( LISTNV NV){
	nodenv*p=NV.nvhead;
	int s=0;
	while(p!=NULL){
		p->infornv.luong=p->infornv.heSL*2300000;
		s+= p->infornv.luong;
		p=p->nvnext;
}
 cout<<"tong luong cua nhan vien la: "<<s<<endl;
return s;
}
double sumluong1( LISTNV NV){
	nodenv*p=NV.nvhead;
	double tb;
	int s=0, d=0;
	while(p!=NULL){
		p->infornv.luong=p->infornv.heSL*2300000;
		d++;
		s+= p->infornv.luong;
		p=p->nvnext;
} 
return tb=s/d;

}
// dem so nhan vien co do tuoi trong khoang t1 t2
void demnv( LISTNV NV){
	int d=0, t1, t2;
	cout<<"Nhap do tuoi nhan vien can tim \n ";
	cout<<" Nhap tuoi thap nhat: ";
	cin>> t1;
	cout<<" Nhap tuoi cao nhat: ";
	cin>>t2;
	nodenv*p=NV.nvhead;
	while(p!=NULL){
	if(p->infornv.tuoi>t1 && p->infornv.tuoi <t2){
	d++;
}
	p=p->nvnext;
}
	cout<<"So luong nhan vien co do tuoi tu "<< t1<<"-"<<t2<<": "<< d<<endl;
}
void demnv1( LISTNV NV){
	int d=0, t1, t2;
	cout<<"Nhap do tuoi nhan vien can tim \n ";
	cout<<" Nhap tuoi can tim: ";
	cin>> t1;
	
	nodenv*p=NV.nvhead;
	while(p!=NULL){
	if(p->infornv.tuoi==t1 ){
	d++;
}
	p=p->nvnext;
}	cout<<"So luong nhan vien co do tuoi "<< t1<<": "<< d<<endl;
}
void demnv2( LISTNV NV){
	int d=0, t1, t2;
	cout<<"Nhap do tuoi nhan vien can tim \n ";
	cout<<" Nhap he so luong can tim: ";
	cin>> t1;
	
	nodenv*p=NV.nvhead;
	while(p!=NULL){
	if(p->infornv.heSL==t1 ){
	d++;
}
	p=p->nvnext;
}	cout<<"So luong nhan vien co he so luong "<< t1<<": "<< d<<endl;
}




void searchname(LISTNV NV){
	nodenv*p=NV.nvhead;
	cin.ignore();
	char name[25];
	cout<<"Nhap ten nhan vien can tim : ";
	gets(name);
	cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
	while(p!=NULL){
		if( strstr(strlwr(p->infornv.tennv), strlwr(name)) != NULL){
		hiennv(p->infornv);
			}
		p=p->nvnext;
		}
}
void searchma1(LISTNV NV){
	nodenv*p=NV.nvhead;
	cin.ignore();
	int name;
	cout<<"Nhap ma nhan vien can tim : ";
	cin>>name;
	cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
	while(p!=NULL){
		if( name==p->infornv.manv){
		hiennv(p->infornv);
			}
		p=p->nvnext;
		}
}



void max(LISTNV NV)
{
    nodenv *p,*max;
    int dem;
    p=NV.nvhead;
    max=p;
    while (p!=NULL)
    {
        if(p->infornv.TT>max->infornv.TT)  { max=p; dem=0; }
        if(p->infornv.TT==max->infornv.TT) { max=p; dem++; }
        p=p->nvnext;
    }
    cout<<"\nnhan vien co luong cao nhat \n";
    cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
    if(dem==0)  hiennv(max->infornv); 
    else
    {
        nodenv *q=NV.nvhead;
        while (q!=NULL)
        {
            if(q->infornv.TT==max->infornv.TT) hiennv(q->infornv);
            q=q->nvnext;
        }
    }
}
void max1(LISTNV NV)
{
    nodenv *p,*max;
    int dem;
    p=NV.nvhead;
    max=p;
    while (p!=NULL)
    {
        if(p->infornv.tuoi>max->infornv.tuoi)  { max=p; dem=0; }
        if(p->infornv.tuoi==max->infornv.tuoi) { max=p; dem++; }
        p=p->nvnext;
    }
    cout<<"\nnhan vien co tuoi cao nhat \n";
    cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
    if(dem==0)  hiennv(max->infornv); 
    else
    {
        nodenv *q=NV.nvhead;
        while (q!=NULL)
        {
            if(q->infornv.tuoi==max->infornv.tuoi) hiennv(q->infornv);
            q=q->nvnext;
        }
    }
}
void min2(LISTNV NV)
{
    nodenv *p,*max;
    int dem;
    p=NV.nvhead;
    max=p;
    while (p!=NULL)
    {
        if(p->infornv.tuoi<max->infornv.tuoi)  { max=p; dem=0; }
        if(p->infornv.tuoi==max->infornv.tuoi) { max=p; dem++; }
        p=p->nvnext;
    }
    cout<<"\nnhan vien co tuoi cao nhat \n";
    cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
    if(dem==0)  hiennv(max->infornv); 
    else
    {
        nodenv *q=NV.nvhead;
        while (q!=NULL)
        {
            if(q->infornv.tuoi==max->infornv.tuoi) hiennv(q->infornv);
            q=q->nvnext;
        }
    }
}
//Hien nhan vien co luong thap nhat
int minlg(LISTNV NV){
	nodenv*p=NV.nvhead;
	NV.nvhead->infornv.luong=NV.nvhead->infornv.heSL;
	int minn=NV.nvhead->infornv.luong;
	while(p!=NULL){
		p->infornv.luong=p->infornv.heSL;
		minn=min(p->infornv.luong, minn);
		p=p->nvnext;
}
		return minn;
}
void hienmin(LISTNV NV){
	nodenv*p=NV.nvhead;
	int minn=minlg(NV);
 cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
	while(p!=NULL){
		p->infornv.luong=p->infornv.heSL;
		if(p->infornv.luong==minn){
		hiennv(p->infornv);
		}
	p=p->nvnext;
	}
}

void pop(LISTNV &NV){
	nodenv*p;
	if(isemptynv()!=NULL){
	p=NV.nvhead;
	NV.nvhead=NV.nvhead->nvnext;
	delete p;
	}else{
	cout<<"NULL";
	}
}
void sapxepnv(LISTNV & NV)
{
	nodenv *p = NV.nvhead , *q;
//cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
	while(p!=NULL)
	{
		q=p->nvnext;
		while(q!=NULL)
		{
			if(p->infornv.TT < q->infornv.TT)
			swap(p->infornv,q->infornv);
			
			q=q->nvnext;
		}
		p=p->nvnext;
	}
}
void sapxepnv1(LISTNV & NV)
{
	nodenv *p = NV.nvhead , *q;
//cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
	while(p!=NULL)
	{
		q=p->nvnext;
		while(q!=NULL)
		{
			if(p->infornv.TT > q->infornv.TT)
			swap(p->infornv,q->infornv);
			
			q=q->nvnext;
		}
		p=p->nvnext;
	}
}
void sapxepnv2(LISTNV & NV)
{
	nodenv *p = NV.nvhead , *q;
//cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
	while(p!=NULL)
	{
		q=p->nvnext;
		while(q!=NULL)
		{
			if(p->infornv.manv < q->infornv.manv)
			swap(p->infornv,q->infornv);
			
			q=q->nvnext;
		}
		p=p->nvnext;
	}
}
void sapxepnv3(LISTNV & NV)
{
	nodenv *p = NV.nvhead , *q;
///cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
	while(p!=NULL)
	{
		q=p->nvnext;
		while(q!=NULL)
		{
			if(p->infornv.manv > q->infornv.manv)
			swap(p->infornv,q->infornv);
		
			q=q->nvnext;
		}
		p=p->nvnext;
	}
}

void thongke(LISTNV NV){
	nodenv*p=NV.nvhead;
	cin.ignore();
	char name[25];
	cout<<"Nhap ten nhan vien can tim : ";
	gets(name);
	cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
	while(p!=NULL){
		if( strstr(strlwr(p->infornv.que), strlwr(name)) != NULL){
		hiennv(p->infornv);
			}
		p=p->nvnext;
		}
}
void thongke1( LISTNV NV){
	int d=0, t1, t2;
	char t3[20];
	cout<<"Nhap do tuoi nhan vien can tim \n ";
	cout<<" Nhap tuoi thap nhat: ";
	cin>>t1;
	cout<<" Nhap tuoi cao nhat: ";
	cin>>t2;
	nodenv*p=NV.nvhead;
	 cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
	while(p!=NULL){
	if(p->infornv.tuoi>t1 && p->infornv.tuoi <t2){
	d++;
	hiennv(p->infornv);
}
	p=p->nvnext;
}
	
}
void thongke2( LISTNV NV){
	int d=0, t1, t2;
	
	cout<<" Nhap tuoi can tim: ";
	cin>> t1;
	
	nodenv*p=NV.nvhead;
	cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
	while(p!=NULL){
	if(p->infornv.tuoi==t1 ){
	d++;
	hiennv(p->infornv);
}
	p=p->nvnext;
}	cout<<"So luong nhan vien co do tuoi "<< t1<<": "<< d<<endl;
}
void thongke3( LISTNV NV){
	int d=0, t1, t2;
	
	cout<<" Nhap he so luong can tim: ";
	cin>> t1;
	
	nodenv*p=NV.nvhead;
	cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
	while(p!=NULL){
	if(p->infornv.heSL==t1 ){
	d++;
	hiennv(p->infornv);
}
	p=p->nvnext;
}
}
void thongke4( LISTNV NV){
	int d=0, t1, t2;
	
	cout<<"Nhap he so luong nhan vien can tim \n ";
	cout<<" Nhap he so luong thap nhat: ";
	cin>>t1;
	cout<<" Nhap he so luong cao nhat: ";
	cin>>t2;
	nodenv*p=NV.nvhead;
	 cout<< setw(5)<< " Ma nv"<< setw(20)<<"Ten nv"<<setw(19)<<"tuoi"<< setw(18)<< "Gioi tinh" << setw(18)<<"Que quan"<< setw(18)<< "Ca Lam"<<setw(18)<<"Luong"<<endl;
	while(p!=NULL){
	if(p->infornv.heSL>t1 && p->infornv.heSL <t2){
	d++;
	hiennv(p->infornv);
}
	p=p->nvnext;
}
	
}




// quan li san pham
struct sanpham{
	int maSp;
	char NXS[25];
	char tenSP[25], tennv[25];
	int solg, dongia, tien;
	int ngays, thangs, nams;
};
struct nodes{
	sanpham infors;
	struct nodes*snext;
};
typedef struct stack{
	nodes*shead;
}STACK;
	STACK S;
void khoitaos(STACK &S){
	S.shead=NULL;
}
void nhapsanpham(sanpham &sp){
	cout<<"Ma san pham: ";
	cin>> sp.maSp;
		fflush(stdin);
	cout<<"Ten san pham: ";
	gets(sp.tenSP);
		fflush(stdin);
	cout<<"Ten hang san xuat: ";
	gets(sp.NXS);
		fflush(stdin);
	cout<<"Ten nhan vien nhap kho: ";
	gets(sp.tennv);
		fflush(stdin);
	cout<<"Ngay nhap kho\n ";
	cout<<" ngay nhap(dd): ";
	cin>> sp.ngays;
		fflush(stdin);
	cout<<"  nam nhap(mm): ";
	cin>>sp.thangs;
	fflush(stdin);
	cout<<"  nam nhap(yyyy): ";
	cin>>sp.nams;
	fflush(stdin);
	cout<<"So luong: ";
	cin>>sp.solg;
		fflush(stdin);
	cout<<"Don gia: ";
	cin>>sp.dongia;
		fflush(stdin);
	sp.tien=sp.dongia*sp.solg;
}
void hiensanpham(sanpham sp){
//	cout<<setw(5)<< "Ma san pham"<<setw(16)<< "Ten san pham"<<setw(20)<<"Ten hang san xuat"<<setw(16)<<"Ten Nhan vien"<<setw(21)<<"Ngay nhap"<<setw(17)<<"So luong"<<setw(16)<<"Don gia"<< endl;
	cout<<setw(5)<<sp.maSp<<setw(16)<<sp.tenSP<<setw(20)<<sp.NXS <<setw(16)<<sp.tennv<<setw(21)<<sp.ngays<<"/"<<sp.thangs<<"/"<<sp.nams<<setw(17)<<sp.solg<<setw(16)<<sp.dongia<<endl;
}
nodes *newnodes( sanpham &sp){
	nodes* p= new nodes;
	if(p==NULL){
		
	cout<< "CHON 1 DE TIEP TUC , 0 DE DUNG LAI: ";
}
	p->infors= sp;
	p->snext=NULL;
	return p;
}
int isemptys(){
	if(S.shead==NULL){
	return 0;
}else return 1;
}
void pushs( nodes*neww){
	if(isemptys()==0){
	S.shead=neww;
}else{
	neww->snext=S.shead;
	S.shead=neww;
	}
}
void nhapdssanpham(STACK &S){
	nodes*p;
	sanpham sp;
	int ok;
	do{
		nhapsanpham(sp);
		p=newnodes(sp);
		pushs(p);
		cout<<endl;
		cout<<"CHON 1 DE TIEP TUC , 0 DE DUNG LAI: ";
		cin>> ok;
		cout<<endl;
	}while(ok!=0);
}
void themsp(STACK &S){
	nodes*p;
	sanpham sp;
	

		nhapsanpham(sp);
		p=newnodes(sp);
		pushs(p);
		cout<<endl;
	
		cout<<endl;
	
}
void hiendssanpham( STACK S){
	nodes*p=S.shead;
	cout<<setw(5)<< "Ma san pham"<<setw(16)<< "Ten san pham"<<setw(20)<<"Ten hang san xuat"<<setw(16)<<"Ten Nhan vien"<<setw(21)<<"Ngay nhap"<<setw(17)<<"So luong"<<setw(16)<<"Don gia"<< endl;

	while(p!=NULL){
		hiensanpham(p->infors);
		p=p->snext;
	}
}
void pops(STACK &S){
	if(isemptys()==0){
	cout<<"NULL";
	}else{
	nodes*p= S.shead;
	S.shead=S.shead->snext;
	delete p;
}
}


void luufsach(STACK S){
	sanpham sp;
	nodes*p=S.shead;
	cin.ignore();
	cout<<"Nhap ten file muon luu: ";
	
	char tenf[25];
	gets(tenf);
	cout<<"Luu thanh cong vao file "<<tenf<<endl;
	fstream fis;
	fis.open(tenf, ios:: app |ios:: binary);
while(p!=NULL){
		fis.write((char*)&p->infors, sizeof(sanpham));
	p=p->snext;
}
	fis.close();
}
void docfsach( STACK &S){
	nodes*p;
	sanpham sp;
	cin.ignore();
	char tenf[25];
	cout<<"Nhap ten file muon doc: ";
	gets(tenf);
	fstream fos;
	fos.open(tenf, ios::in | ios::binary);
if(fos.fail()){
	cout<<"Loi Mo Tep!";
}else{
while(!fos.eof()){
	fos.read((char*)&sp, sizeof(sanpham));
	p=newnodes(sp);
	pushs(p);
}
}
	fos.close();
}

int sumslg(STACK S){
	nodes*p=S.shead;
	int s=0;
while(p!=NULL){
	s+= p->infors.solg;
	p=p->snext;
}
	return s;
}
void tongnxsx( STACK S){
	nodes*p=S.shead;
	int d=0, tong=0;
	cin.ignore();
	char hsx[25];
	cout<<"Nhap ten hang san xuat: ";
	gets(hsx);
while(p!=NULL){
if(strcmp(p->infors.NXS, hsx)==0){
	d++;tong+=p->infors.solg;
	}
	p=p->snext;
	}
	cout<<"So san pham cua hang do la "<< hsx<<" : "<< tong<<endl;
}
void samenxb( STACK S){
	nodes*p=S.shead;
	int d=0;
	cin.ignore();
	char hsx[25];
	cout<<"Nhap ten hang san xuat: ";
	gets(hsx);
while(p!=NULL){
if(strcmp(p->infors.NXS, hsx)==0){
	d++;
	}
	p=p->snext;
	}
	cout<<"So san pham cua hang do la "<< hsx<<" : "<< d<<endl;
}
void sameyear(STACK S){
	sanpham sp;
	nodes*p=S.shead;
	int namx, d=0, tong=0;
	cout<<"Nhap nam nhap hang can tim: ";
	cin>>namx;
while(p!=NULL){
if(p->infors.nams==namx){
		d++;
		tong+=p->infors.solg;
	}
		p=p->snext;
	}
		cout<<"So luong san pham nhap nam "<< namx<<" : "<< tong<<endl; 
}
void demg1g2(STACK S){
	nodes*p=S.shead;
	int g1, g2, d=0, tong =0;
	cout<<"Nhap khoang nam\n ";
	cout<<" khoang dau: ";
	cin>> g1;
	cout<<"  khoang cuoi: ";
	cin>>g2;
	cout<<setw(5)<< "Ma san pham"<<setw(16)<< "Ten san pham"<<setw(16)<<"Ten hang san xuat"<<setw(16)<<"Ten Nhan vien"<<setw(21)<<"Ngay nhap"<<setw(17)<<"So luong"<<setw(16)<<"Don gia"<< endl;
while(p!=NULL){
	if(p->infors.nams>g1 && p->infors.nams<g2){
			d++;
		tong+=p->infors.solg;
	}
		p=p->snext;
	} 
	cout<<"so luong san pham tu nam: "<<g1<<" den nam: "<<g2<<" la: "<<tong<<endl;
}
int mindg(STACK S){
	nodes*p=S.shead;
	int minndg=S.shead->infors.dongia;
while(p!=NULL){
	minndg=min(p->infors.dongia, minndg);
	p=p->snext;
	}
	return minndg;
}
void hienmindg(STACK S){
	nodes*p=S.shead;
	int minndg=mindg(S);
	cout<<"Thong tin san pham co so luong it nhat: "<<endl;
	cout<<setw(5)<< "Ma san pham"<<setw(16)<< "Ten san pham"<<setw(16)<<"Ten hang san xuat"<<setw(16)<<"Ten Nhan vien"<<setw(21)<<"Ngay nhap"<<setw(17)<<"So luong"<<setw(16)<<"Don gia"<< endl;
	

while(p!=NULL){
	if(p->infors.dongia==minndg){
		hiensanpham(p->infors);
		}
	p=p->snext;
	}
}

int maxdg( STACK S){
	nodes*p=S.shead;
	int maxx=-1;
while(p!=NULL){
	maxx=max(p->infors.dongia, maxx);
	p=p->snext;
	}
	return maxx;
}
void hienmaxdg(STACK S){
	nodes*p=S.shead;
	int maxx=maxdg(S);
	cout<<"Thong tin san pham co so luong nhieu nhat: "<<endl;
cout<<setw(5)<< "Ma san pham"<<setw(16)<< "Ten san pham"<<setw(16)<<"Ten hang san xuat"<<setw(16)<<"Ten Nhan vien"<<setw(21)<<"Ngay nhap"<<setw(17)<<"So luong"<<setw(16)<<"Don gia"<< endl;
while(p!=NULL){
	if( p->infors.dongia==maxx){
		hiensanpham(p->infors);
		}
		p=p->snext;
	}
}


int minslg(STACK S){
	nodes*p=S.shead;
	int minn=S.shead->infors.solg;
while(p!=NULL){
	minn=min(p->infors.solg, minn);
	p=p->snext;
	}
	return minn;
}
void hienmins(STACK S){
	nodes*p=S.shead;
	int minn=minslg(S);
	cout<<"Thong tin san pham co so luong it nhat: "<<endl;
	cout<<setw(5)<< "Ma san pham"<<setw(16)<< "Ten san pham"<<setw(16)<<"Ten hang san xuat"<<setw(16)<<"Ten Nhan vien"<<setw(21)<<"Ngay nhap"<<setw(17)<<"So luong"<<setw(16)<<"Don gia"<< endl;
	

while(p!=NULL){
	if(p->infors.solg==minn){
		hiensanpham(p->infors);
		}
	p=p->snext;
	}
}
int maxslg( STACK S){
	nodes*p=S.shead;
	int maxx=-1;
while(p!=NULL){
	maxx=max(p->infors.solg, maxx);
	p=p->snext;
	}
	return maxx;
}
void hienmaxs(STACK S){
	nodes*p=S.shead;
	int maxx=maxslg(S);
	cout<<"Thong tin san pham co so luong nhieu nhat: "<<endl;
cout<<setw(5)<< "Ma san pham"<<setw(16)<< "Ten san pham"<<setw(16)<<"Ten hang san xuat"<<setw(16)<<"Ten Nhan vien"<<setw(21)<<"Ngay nhap"<<setw(17)<<"So luong"<<setw(16)<<"Don gia"<< endl;
while(p!=NULL){
	if( p->infors.solg==maxx){
		hiensanpham(p->infors);
		}
		p=p->snext;
	}
}
void hieng1g2(STACK S){
	nodes*p=S.shead;
	int g1, g2;
	cout<<"Nhap khoang nam\n ";
	cout<<" khoang dau: ";
	cin>> g1;
	cout<<"  khoang cuoi: ";
	cin>>g2;
	cout<<setw(5)<< "Ma san pham"<<setw(16)<< "Ten san pham"<<setw(16)<<"Ten hang san xuat"<<setw(16)<<"Ten Nhan vien"<<setw(21)<<"Ngay nhap"<<setw(17)<<"So luong"<<setw(16)<<"Don gia"<< endl;
while(p!=NULL){
	if(p->infors.nams>g1 && p->infors.nams<g2){
		hiensanpham(p->infors);
	}
		p=p->snext;
	}
}

// tang dan theo so luong
void sapxep3(STACK S)
{
	nodes *p = S.shead , *q;

	while(p!=NULL)
	{
		q=p->snext;
		while(q!=NULL)
		{
			if(p->infors.solg > q->infors.solg)
			swap(p->infors,q->infors);
			q=q->snext;
		}
		p=p->snext;
	}
}
// giam dan theo ao luong
void sapxep4(STACK S)
{
	nodes *p = S.shead , *q;

	while(p!=NULL)
	{
		q=p->snext;
		while(q!=NULL)
		{
			if(p->infors.solg < q->infors.solg)
			swap(p->infors,q->infors);
			q=q->snext;
		}
		p=p->snext;
	}
}
	
// sap xep tang dan theo don gia




void sapxep2(STACK S)
{
	nodes *p = S.shead , *q;
	
	while(p!=NULL)
	{
		q=p->snext;
		while(q!=NULL)
		{
			if(p->infors.dongia > q->infors.dongia)
			swap(p->infors,q->infors);
			q=q->snext;
		}
		p=p->snext;
	}
}


// sap xep theo giam dan theo ten
void sapxep1(STACK S)
{
	nodes *p = S.shead , *q;
	
	while(p!=NULL)
	{
		q=p->snext;
		while(q!=NULL)
		{
			if(p->infors.dongia < q->infors.dongia)
			swap(p->infors,q->infors);
			q=q->snext;
		}
		p=p->snext;
	}
}
// tim san pham theo ten

void searchtens(STACK S){
	nodes*p=S.shead;
	cin.ignore();
	char names[25];
	cout<<"Nhap ten san pham: ";
	gets(names);
cout<<setw(5)<< "Ma san pham"<<setw(16)<< "Ten san pham"<<setw(16)<<"Ten hang san xuat"<<setw(16)<<"Ten Nhan vien"<<setw(21)<<"Ngay nhap"<<setw(17)<<"So luong"<<setw(16)<<"Don gia"<< endl;
while(p!=NULL){
		if(strstr(strlwr(p->infors.tenSP), strlwr(names))!=NULL){
		hiensanpham(p->infors);
}
		p=p->snext;
}
}


// tìm san pham theo ma

 
void searchma(STACK S){
	nodes*p=S.shead;
	cin.ignore();
	int ma;
	cout<<"Nhap ma san pham: ";
	cin>>ma;
cout<<setw(5)<< "Ma san pham"<<setw(16)<< "Ten san pham"<<setw(16)<<"Ten hang san xuat"<<setw(16)<<"Ten Nhan vien"<<setw(21)<<"Ngay nhap"<<setw(17)<<"So luong"<<setw(16)<<"Don gia"<< endl;
while(p!=NULL){
		if(ma==p->infors.maSp){
		hiensanpham(p->infors);
}
		p=p->snext;
}
}
void thongkensx( STACK S){
	nodes*p=S.shead;
	int d=0;
	cin.ignore();
	char hsx[25];
	cout<<"Nhap ten hang san xuat: ";
	gets(hsx);
while(p!=NULL){
if(strcmp(p->infors.NXS, hsx)==0){
	hiensanpham(p->infors);
	}
	p=p->snext;
	}
	
}
void thongkenamx(STACK S){
	sanpham sp;
	nodes*p=S.shead;
	int namx, d=0, tong=0;
	cout<<"Nhap nam nhap hang can tim: ";
	cin>>namx;
while(p!=NULL){
if(p->infors.nams==namx){
	hiensanpham(p->infors);
	
	}
		p=p->snext;
	}
		
}
void thongkeg1g2(STACK S){
	nodes*p=S.shead;
	int g1, g2, d=0, tong =0;
	cout<<"Nhap khoang nam\n ";
	cout<<" khoang dau: ";
	cin>> g1;
	cout<<"  khoang cuoi: ";
	cin>>g2;
	cout<<setw(5)<< "Ma san pham"<<setw(16)<< "Ten san pham"<<setw(16)<<"Ten hang san xuat"<<setw(16)<<"Ten Nhan vien"<<setw(21)<<"Ngay nhap"<<setw(17)<<"So luong"<<setw(16)<<"Don gia"<< endl;
while(p!=NULL){
	if(p->infors.nams>g1 && p->infors.nams<g2){
		hiensanpham(p->infors);
	}
		p=p->snext;
	} 

}
void thongkex1x2(STACK S){
	nodes*p=S.shead;
	int g1, g2, d=0, tong =0;
	cout<<"Nhap khoang don gia\n ";
	cout<<" khoang dau: ";
	cin>> g1;
	cout<<"  khoang cuoi: ";
	cin>>g2;
	cout<<setw(5)<< "Ma san pham"<<setw(16)<< "Ten san pham"<<setw(16)<<"Ten hang san xuat"<<setw(16)<<"Ten Nhan vien"<<setw(21)<<"Ngay nhap"<<setw(17)<<"So luong"<<setw(16)<<"Don gia"<< endl;
while(p!=NULL){
	if(p->infors.dongia>g1 && p->infors.dongia<g2){
		hiensanpham(p->infors);
	}
		p=p->snext;
	} 

}
void capnhat(STACK &S){
	int ma;
	nodes*p=S.shead;
	sanpham sp;
	cout<<"Nhap ma san pham can sua: "; cin>>ma;
  for(p;p!=NULL;p=p->snext)
	if(p->infors.maSp==ma){
		nhapsanpham(p->infors);
		cout<<endl;	
}
}
int main(){
	int chon;
do{
cout<<"\t\t\t\t\t\t==============>MENU<=============="<<endl;

	cout<<"\t\t\t\t\t\t1. Quan ly san pham."<< endl;
	cout<<"\t\t\t\t\t\t2. Quan ly nhan vien."<< endl;
	cout<<"\t\t\t\t\t\t0. Thoat!."<< endl;
	cout<<"\t\t\t\t\t\tBan chon: ";
	cin>>chon;
if(chon==1){
	int c2;
	sanpham sp;
	khoitaos(S);
do{
	cout<<endl;
	cout<<"\n \t\t\t\t==============>MENU<=============="<<endl;
	cout<<"\t\t\t\t1. Doc DS san pham tu file."<< endl;
	cout<<"\t\t\t\t2. Nhap DS san pham."<< endl;
	cout<<"\t\t\t\t3. In DS san pham."<< endl;
	cout<<"\t\t\t\t4. Luu DS san pham vao file."<< endl;
	cout<<"\t\t\t\t5. cap nhat thong tin  san pham."<< endl;
	cout<<"\t\t\t\t6. Them  san pham."<< endl;
	cout<<"\t\t\t\t7. Tong, dem, trung binh"<< endl;
	cout<<"\t\t\t\t8. Hien thong tin san pham co so luong it nhat."<< endl;	
	cout<<"\t\t\t\t9.thong ke."<< endl;
	cout<<"\t\t\t\t10. Tim  san pham."<< endl;
	cout<<"\t\t\t\t11. Xoa thong tin san pham."<< endl;
	cout<<"\t\t\t\t12. sap xep san pham"<< endl;
	cout<<"\t\t\t\t0. Thoat!"<< endl;
	cout<<"\t\t\t\t Ban chon: ";
	cin>>c2;	
	switch(c2){
	
		break;
		case 1:
			docfsach(S);
			break;
		case 2:
			nhapdssanpham(S);
			break;
		case 3:
			hiendssanpham(S);
			break;
		case 4:
			luufsach(S);
			break;
		case 5: capnhat(S);cout<<endl;
			cout<<"Danh sach sau khi cap nhat thong tin"<<endl;
						hiendssanpham(S);break;
		case 6:
			themsp(S);break;
		case 7:
		
				int c6;
		do{
			cout<<"1.Tong so luong san pham"<<endl;
			cout<<"2.Dem so luong mat hang cung nha san xuat."<< endl;
			cout<<"3.Dem so luong san pham duoc san xuat vao nam x."<< endl;
			cout<<"4.Dem so luong san pham trong khoang nam x1 den x2."<<endl;
			cout<<"5.tong so luong san pham cua nha san xuat x."<<endl;
			cout<<"0. thoat"<<endl;
			cout<<"moi ban chon: "; cin>>c6;
			switch(c6){
				case 1:
					cout<<"Tong so luong san pham: "<<sumslg(S)<<endl;
			break;
				case 2:
						samenxb(S);
						break;
				case 3:sameyear(S);
						break;
				case 4: demg1g2(S);break;
				case 5: tongnxsx(S);break;
				case 0:	break;
				default :
					cout<<"Ban chon sai! Moi ban chon lai!"<<endl;
					break;
					
			}
		}while(c6!=0);
			case 0:
			break;
		default :
			cout<<"Ban chon sai! Moi ban chon lai!"<<endl;
			break;
	
		case 8:
			
			int c5;
		do{
			cout<<"1.san pham co so luong it nhat"<<endl;
			cout<<"2.san pham co so luong nhieu nhat"<<endl;
			cout<<"3.san pham co gia thap nhat"<<endl;
			cout<<"4.san pham co gia cao nhat"<<endl;
			cout<<"0. thoat"<<endl;
			cout<<"moi ban chon: "; cin>>c5;
			switch(c5){
				case 1:
					hienmins(S);
					break;
				case 2: 
					hienmaxs(S);
					break;
				case 3:
					hienmindg(S);
					break;
				case 4:
					hienmaxdg(S);
					break;	
				case 0:
					break;
				default :
					cout<<"Ban chon sai! Moi ban chon lai!"<<endl;
					break;
					
			}
		}while(c5!=0);
			break;
			
	
		case 9:
			
				int c7;
		do{
			cout<<"1.Thong ke san pham tu nam x1 den nam x2."<<endl;
			cout<<"2.Thong ke san pham cua nha san xuat x."<<endl;
			cout<<"3.Thong ke san pham san xuat trong nam x."<<endl;
			cout<<"4.Thong ke san pham san xuat tu nam x1 den nam x2."<<endl;
			cout<<"4.Thong ke san pham san xuat co gia tu x1 den nam x2."<<endl;
			cout<<"0. thoat"<<endl;
			cout<<"moi ban chon: "; cin>>c7;
			switch(c7){
				case 1:hieng1g2(S);
						break;
				case 2:thongkensx(S); break;
				case 3: thongkenamx(S);break;
				case 4:thongkeg1g2(S); break;
				case 5:thongkex1x2(S); break;
				case 0:	break;
				default :
					cout<<"Ban chon sai! Moi ban chon lai!"<<endl;
					break;
					
			}
		}while(c7!=0);
			break;
		
		case 10:
		
		int c3;
		do{
			cout<<"1.Tim theo ten"<<endl;
			cout<<"2.tim theo ma"<<endl;
			cout<<"0. thoat"<<endl;
			cout<<"moi ban chon: "; cin>>c3;
			switch(c3){
				case 1:
					searchtens(S);break;
				case 2:
					searchma(S);break;
				case 0:	break;
				default :
					cout<<"Ban chon sai! Moi ban chon lai!"<<endl;
					break;
					
			}
		}while(c3!=0);
			break;
		
		
		case 11:
			pops(S);
			cout<<"Danh sach san pham sau khi xoa dau: "<<endl;
			hiendssanpham(S);
			break;
	    case 12:
				int c4;
		do{
			cout<<"1.tang dan theo so luong"<<endl;
			cout<<"2.giam dan theo so luong"<<endl;
			cout<<"3. tang dan theo don gia"<<endl;
			cout<<"4.giam dan theo don gia"<<endl;
			cout<<"0. thoat"<<endl;
			cout<<"moi ban chon: "; cin>>c4;
			switch(c4){
				case 1:
						sapxep3(S);
						cout<<endl;
						cout<<"Danh sach sau khi sap xep tang dan theo don gia"<<endl;
						hiendssanpham(S);
						break;
					
					
				case 2:
						sapxep4(S);
						cout<<endl;
						cout<<"Danh sach sau khi sap xep tang dan theo don gia"<<endl;
						hiendssanpham(S);
						break;
					
				case 3:
					sapxep2(S);
						cout<<endl;
						cout<<"Danh sach sau khi sap xep tang dan theo don gia"<<endl;
						hiendssanpham(S);
						break;
				case 4:
						sapxep1(S);
						cout<<endl;
						cout<<"Danh sach sau khi sap xep giam dan theo don gia"<<endl;
						hiendssanpham(S);
						break;
				case 0:	break;
				default :
					cout<<"Ban chon sai! Moi ban chon lai!"<<endl;
					break;
					
			}
		}while(c4!=0);
			break;
		
	
}
}
	while(c2!=0);
}
	else if(chon==2){
		int c1;
		nhanvien nv;
		khoitaonv(NV);
do{
	cout<<"\t\t\t\t==============>MENU<=============="<<endl;
	cout<<"\t\t\t\t1. Doc DS nhan vien tu file."<<endl;
	cout<<"\t\t\t\t2. Nhap DS nhan vien."<< endl;
	cout<<"\t\t\t\t3. In DS nhan vien."<< endl;
	cout<<"\t\t\t\t4. Luu DS nhan vien vao file."<<endl;
	cout<<"\t\t\t\t5. them nhan vien."<< endl;
	cout<<"\t\t\t\t6. cap nhat thong tin nhan vien."<< endl;
	cout<<"\t\t\t\t7. Xoa nhan vien dau danh sach."<< endl;
	cout<<"\t\t\t\t8. tim nhan vien."<< endl;
	cout<<"\t\t\t\t9. sap xep."<< endl;
	cout<<"\t\t\t\t10. Tim kiem lon nhat, nho nhat."<< endl;
	cout<<"\t\t\t\t11. Tong, trung binh, dem."<< endl;
	cout<<"\t\t\t\t12. thong ke."<< endl;
	cout<<"\t\t\t\t0. Thoat!"<< endl;
	cout<<"\t\t\t\t Ban chon: ";
	cin>> c1;
	switch(c1){
		case 1:
			docfnv(NV);
			break;
		case 2:
			nhapdsnv(NV);
			break;
		case 3:
			hiendsnv(NV);
			break;
		case 4:
			luufnv(NV);
			break;
		case 5: 
		    themnv(NV);
		    break;
		case 6:
			capnhatnv(NV);break;
		case 7: 
			pop(NV);
			cout<<" DS sau khi xoa dau: "<< endl;
			hiendsnv(NV);
			break;
		case 8:
				int t1;
		do{
			cout<<"1.Tim theo ten"<<endl;
			cout<<"2.tim theo ma"<<endl;
			cout<<"0. thoat"<<endl;
			cout<<"moi ban chon: "; cin>>t1;
			switch(t1){
				case 1:
					searchname(NV);break;
				case 2:
					searchma1(NV);break;
				case 0:	break;
				default :
					cout<<"Ban chon sai! Moi ban chon lai!"<<endl;
					break;
					
			}
		}while(t1!=0);
			break;
		case 9:
					int t2;
		do{
			cout<<"1.giam dan theo luong"<<endl;
			cout<<"2.tang dan theo luong"<<endl;
			cout<<"3.giam dan theo ma"<<endl;
			cout<<"4.tang dan theo ma"<<endl;
			cout<<"0. thoat"<<endl;
			cout<<"moi ban chon: "; cin>>t2;
			switch(t2){
				case 1:
					sapxepnv(NV); 
					hiendsnv(NV);
					break;
				case 2:
					sapxepnv1(NV);hiendsnv(NV);break;
				case 3:
					sapxepnv2(NV);hiendsnv(NV);break;
				case 4:
					sapxepnv3(NV);hiendsnv(NV);break;
				case 0:	break;
				default :
					cout<<"Ban chon sai! Moi ban chon lai!"<<endl;
					break;
					
			}
		}while(t2!=0);
			break;
			

	
		case 10:
					int t3;
		do{
			cout<<"1.nhan vien co luong cao nhat"<<endl;
			cout<<"2.nhan vien co luong thap nhat"<<endl;
			cout<<"3.nhan vien co tuoi cao nhat"<<endl;
			cout<<"4.nhan vien co tuoi thap nhat"<<endl;
			cout<<"0. thoat"<<endl;
			cout<<"moi ban chon: "; cin>>t3;
			switch(t3){
				case 1:
						max(NV);
						break;
				case 2:
						hienmin(NV);
						break;
				case 3:
						max1(NV);
						break;
				case 4:
						min2(NV);
						break;
				case 0:	break;
				default :
					cout<<"Ban chon sai! Moi ban chon lai!"<<endl;
					break;
					
			}
		}while(t3!=0);
			break;
		
		case 11:
					int t4;
		do{
			cout<<"1.Tong luong cua nhan vien"<<endl;
			cout<<"2.Trung binh tien luong cua nha vien"<<endl;
			cout<<"3.dem so nhan vien co do tuoi tu x1 den x2"<<endl;
			cout<<"4.dem so nhan vien co tuoi x"<<endl;
			cout<<"5.dem so nhan vien co he so luong x"<<endl;
			cout<<"0. thoat"<<endl;
			cout<<"moi ban chon: "; cin>>t4;
			switch(t4){
				case 1:
						sumluong(NV);
						cout<<endl; break;
						break;
				case 2:
						cout<<"tb luong cua nhan vien la: "<<sumluong1(NV)<<endl; break;
				case 3:
						demnv(NV);
						break;
				case 4:
						demnv1(NV);
						break;
				case 5:
						demnv2(NV);
						break;
				case 0:	break;
				default :
					cout<<"Ban chon sai! Moi ban chon lai!"<<endl;
					break;
					
			}
		}while(t4!=0);
			break;
			
		
		
		case 12: 
					int t5;
		do{
			
			cout<<"1.thong ke nhan vien co que o tinh x"<<endl;
			cout<<"2.thong ke so nhan vien co do tuoi tu x1 den x2"<<endl;
			cout<<"3.thong ke so nhan vien co tuoi x"<<endl;
			cout<<"4.thong ke so nhan vien co he so luong x1 den x2"<<endl;
			cout<<"5.thong ke so nhan vien co he so luong x"<<endl;
			cout<<"0. thoat"<<endl;
			cout<<"moi ban chon: "; cin>>t5;
			switch(t5){
				case 1:
						thongke(NV); break;
						break;
				case 2:
						thongke1(NV); break;
				case 3:
						thongke2(NV);
						break;
				case 4:
						thongke4(NV);
						break;
				case 5:
						thongke3(NV);
						break;
				case 0:	break;
				default :
					cout<<"Ban chon sai! Moi ban chon lai!"<<endl;
					break;
					
			}
		}while(t5!=0);
			break;
	
			 
	
		case 0:
			break;
		default:
			cout<<"Ban chon sai! Moi ban chon lai!";
			break;
		}
	}
	while( c1!=0);
	} else if(chon==0){
		break;
	} else {
		cout<<"Ban chon sai! Moi ban chon lai!"<<endl;
		}
	}
while(true);
}

