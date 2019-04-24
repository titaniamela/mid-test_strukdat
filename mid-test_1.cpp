/*
Nama        : Shania Salsabila
NPM         : 140810180014
Kelas	    : B
Deskripsi   : UTS
Tanggal     : 24 April 2019
*/
#include<iostream>
#include<iomanip>

using namespace std;

struct ElemtList{
	char nama[50];
	char namaOrang[50];
	int jumlah;
	int harga;
	ElemtList* next;
};

typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First){
	First=NULL;
}

void createElemt(pointer& pBaru){
	pBaru = new ElemtList;
	cout<<"Nama Makanan     : ";
	cin.getline(pBaru->nama,50);
	cout<<"Jumlah           : ";
	cin>>pBaru->jumlah;
	cout<<"Harga satuan     : ";
	cin>>pBaru->harga;
	pBaru->next=NULL;
}

void insertLast(List& First, pointer pBaru){
	pointer last;
	if(First==NULL){
		First=pBaru;
	}
	else{
		last=First;
		while (last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void sort(List& First,pointer pBantu){
	int tukar,temp;
	pointer terbesar,pNull=NULL;
	if(First==NULL){
		return;
	}
		do{
		tukar=0;
		pBantu=First;
		while(pBantu->next!=NULL){
			if(pBantu->jumlah > pBantu->next->jumlah){
				swap(pBantu->jumlah,pBantu->next->jumlah);
				tukar=1;
			}
			pBantu=pBantu->next;
		}
		pNull=pBantu;
		}while(tukar);
	}

void swap(pointer a,pointer b){
	int temp = a->;
	a->info = b->info;
	b->info = temp;
}

void traversal(List First,pointer pBantu){
	int i=1;
	if(First==NULL){
		cout<<"List kosong"<<endl;
	}
	else{
		pBantu=First;
		cout<<"---------------------------------------------"<<endl;
		cout<<"No"<<"Nama Makanan"<<"Harga"<<endl;
		cout<<"---------------------------------------------"<<endl;
		do{
			cout<<i++<<pBantu->nama<<pBantu->harga<<endl;
			cout<<"---------------------------------------------"<<endl;
			pBantu=pBantu->next;
		}while(pBantu!=NULL);
	}
}

int main(){
	int n;
	List a;
	pointer b;
	createList(a);
	cout<<"Banyak pesanan = ";cin>>n;
	for(int i=0;i<n;i++){
		createElemt(b);
		insertLast(a,b);
	}
	sort(a,b);
	traversal(a);
}
