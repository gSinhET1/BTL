//Restaurant bill
#include<iostream>
#include<string.h>
#include<stdlib.h>// su dung cho lenh exit
using namespace std;
struct items{
    char item[20];
    float price;
    int qty;
};

struct orders{
    char ten[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};
//HIển thị đơn hàng
void Taodonhang(char name[50],char date[30]){
    cout <<"\n\n";
        cout << "\t    Bitis shop ";
        cout << "\n\t   -----------------";
        cout << "\nNgay:" << date;
        cout << "\nDon hang cua: " << name;
        cout << "\n";
        cout << "---------------------------------------\n";
        cout << "San pham\t";
        cout << "So luong\t";
        cout << "Gia\t\t";
        cout << "\n---------------------------------------";
        cout << "\n\n";
}
void taothanhoadon(char item[30],int qty, float price){
    cout << item; 
        cout << "\t\t" << qty; 
        cout << "\t\t" << qty * price; 
        cout << "\n";
}
void taochanhoadon(float total){
    cout << "\n";
    float dis = 0.1*total;
    float netTotal=total-dis;
    float cgst=0.08*netTotal,grandTotal=netTotal + cgst;//netTotal + cgst + sgst
    cout <<"---------------------------------------\n";
    cout <<"Sub Total\t\t\t" << total;                
    cout <<"\nGiam gia 10%\t\t\t" << dis << "%" ;
    cout <<"\n\t\t\t\t-------";
    cout <<"\nNet Total\t\t\t" << netTotal;
    cout <<"\nVAT 8%\t\t\t\t" << cgst << "% " ;
    cout <<"\n---------------------------------------";
    cout <<"\nGrand Total\t\t\t" << grandTotal;
    cout <<"\n---------------------------------------\n";
}
int main(){
    
    int opt,n;
    struct orders ord;
    struct orders order;
    char saveBill = 'y',contFlag = 'y';
    char name[50];
    FILE *fp;
       //dashboard
    while(contFlag == 'y'){
    system("cls");
    float total = 0;
    int invoiceFound = 0;
    cout <<"\t============BITIS============";
    cout <<"\n\nXIn vui long nhap lua chọn cua ban";
    cout <<"\n\n1.Tao hoa don";
    cout <<"\n2.Hien thi tat ca hoa don";
    cout <<"\n3.Tim kiem hoa don";
    cout <<"\n4.Exit";
    cout <<"\n\nNhap lua chon cua ban:\t";
    cin >> opt;
    fgetc(stdin);
    switch(opt){
        case 1:
        system("cls");
        cout <<"\nTen khach hang:\t";
        fgets(ord.ten,50,stdin);
        ord.ten[strlen(ord.ten)-1] = 0;
        strcpy(ord.date,__DATE__);
        cout <<"\nSo luong san pham:\t";
        cin >> n;
        ord.numOfItems = n;
        for(int i=0;i<n;i++){
            fgetc(stdin);
            cout <<"\n\n";
            cout <<"San pham so " << i+1  << ":"<< "\t" ;
            fgets(ord.itm[i].item,20,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            cout <<"SO luong:\t";
            cin >> ord.itm[i].qty;
            cout <<"Gia tien 1 san pham:\t";
            cin >> ord.itm[i].price;
            total += ord.itm[i].qty * ord.itm[i].price;
        }

        Taodonhang(ord.ten,ord.date);
        for(int i=0;i<ord.numOfItems;i++){
            taothanhoadon(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
        }
        taochanhoadon(total);

        cout <<"\nBạn có muốn lưu hóa đơn [y/n]:\t";
        cin >> saveBill;

        if(saveBill == 'y'){
            fp = fopen("BitisBill.dat","a+");
            fwrite(&ord,sizeof(struct orders),1,fp);
            if(fwrite != 0)
            cout <<"\nLuu thanh cong";
            else 
            cout <<"\nError saving";
            fclose(fp);
        }
        break;

        case 2:
        system("cls");
        fp = fopen("BitisBill.dat","r");
        cout <<"\n  *****Your Previous Invoices*****\n";
        while(fread(&order,sizeof(struct orders),1,fp)){
            float tot = 0;
            Taodonhang(order.ten,order.date);
            for(int i=0;i<order.numOfItems;i++){
                taothanhoadon(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                tot+=order.itm[i].qty * order.itm[i].price;
            }
            taochanhoadon(tot);
        }
        fclose(fp);//lenh de dong 1 tep da mo
        break;

        case 3:
        cout <<"Ten khach hang:\t";
        //fgetc(stdin);
        fgets(name,50,stdin);
        name[strlen(name)-1] = 0;
        system("cls");
        fp = fopen("BitisBill.dat","r");
        cout <<"\t*****Hoa don cua *****" << name;
        while(fread(&order,sizeof(struct orders),1,fp)){
            float tot = 0;
            if(!strcmp(order.ten,name)){
            Taodonhang(order.ten,order.date);
            for(int i=0;i<order.numOfItems;i++){
                taothanhoadon(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                tot+=order.itm[i].qty * order.itm[i].price;
            }
            taochanhoadon(tot);
            invoiceFound = 1;
            }
        
        }
        if(!invoiceFound){
            cout <<"Sorry the invoice for %s doesnot exists",name;
        }
        fclose(fp);
        break;

    case 4:
    cout <<"\n\t\t Bye Bye :)\n\n";
    exit(0);
    break;

    default:
    cout <<"Lua chon khong hop le";
    break;
    }
    cout <<"\nBạn có muốn thực hiện thao tác khác?[y/n]:\t";
    cin >> contFlag;
    }
    cout <<"\n\t\t Bye Bye :)\n\n";
    cout <<"\n\n";

    return 0;
}