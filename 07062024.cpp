

#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

// Số lượng sản phẩm tối đa trong đơn hàng
const int MAX_SAN_PHAM = 100;


class SanPham {
    int id;
    char name[50];
    char loai[30]; // danh cho nguoi lon, tre em, phu nu....
    int size;
    int soluong;
    long price;
    static SanPham danhSachSanPham[MAX_SAN_PHAM]; // Mảng lưu trữ danh sách sản phẩm
    static int soLuongSanPham; // Biến đếm số lượng sản phẩm trong danh sách


public:
    // Hàm để nhập thông tin sản phẩm
    void nhapThongTin() {
        cout << "Nhap ID san pham: ";
        cin >> id;
        cout << "Nhap ten san pham: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Nhap loai san pham: ";
        cin.getline(loai, 30);
        cout << "Nhap size san pham: ";
        cin >> size;
        cout << "Nhap so luong san pham: ";
        cin >> soluong;
        cout << "Nhap gia san pham: ";
        cin >> price;
        danhSachSanPham[soLuongSanPham++] = *this;
    }
     // Hàm để hiển thị thông tin sản phẩm
    void hienThiThongTin() {
        cout << "==========================" << endl;
        cout << "ID: "<< id << endl;
        cout << " Ten san pham:  " << name << endl;
        cout << "Loai san pham: " << loai << endl;
        cout << "Size san pham: " << size << endl;
        cout << "So luong san pham: " << soluong << endl;
        cout << "Gia san pham: " << price << endl;
        cout << "=========================="<< endl;
    }
     static void hienThiDanhSachSanPham() {
        cout << "=== Danh sach san pham ===" << endl;
        for (int i = 0; i < soLuongSanPham; ++i) {
            cout << "San pham thu " << i + 1 << ":" << endl;
            danhSachSanPham[i].hienThiThongTin();
        }
    }

    long layGia() const {
        return price;
    }
    int layID() const {
        return id;
    }
     void suaThongTinSanPham() {
       int id;
       cout << "Nhap ID san pham muon sua: ";
       cin >> id;

       for (int i = 0; i < soLuongSanPham; ++i) {
        if (danhSachSanPham[i].layID() == id) {
            cout << "Nhap thong tin moi cho san pham:\n";
            danhSachSanPham[i].nhapThongTin();
            cout << "Thong tin san pham da duoc cap nhat.\n";
            return;
        }
    }
    cout << "Khong tim thay san pham voi ID: " << id << endl;
}
};
SanPham SanPham::danhSachSanPham[MAX_SAN_PHAM];
int SanPham::soLuongSanPham = 0;

class DonHang {
    SanPham danhSachSanPham[MAX_SAN_PHAM];
    int soLuongSanPham;

public:
    DonHang() : soLuongSanPham(0) {}

    void taoDonHang() {
        if (soLuongSanPham >= MAX_SAN_PHAM) {
            cout << "Da vuot qua so luong san pham toi da trong don hang.\n";
            return;
        }
        SanPham sp;
        cout << "Hay lua chon san pham muon mua:" << endl;
        sp.nhapThongTin();
        danhSachSanPham[soLuongSanPham++] = sp;
        cout << "San pham da duoc them vao don hang.\n";
    }

    void hienThiDonHang() {
        cout << "=== Thong Tin Don Hang ===\n";
        for (int i = 0; i < soLuongSanPham; ++i) {
            danhSachSanPham[i].hienThiThongTin();
            cout << "----------------------------\n";
        }
    }

    long tinhTongGiaTri() const {
        long tongGiaTri = 0;
        for (int i = 0; i < soLuongSanPham; ++i) {
            tongGiaTri += danhSachSanPham[i].layGia();
        }
        return tongGiaTri;
    }
};
void hienThiMenu() {
    cout << "================================" << endl;
    cout << "|| 1. QUAN LY KHO HANG         ||" << endl;
    cout << "|| 2. QUAN LY BAN HANG         ||" << endl;
    cout << "|| 3. EXIT                     ||" << endl;
    cout << "================================" << endl;
}
void menudonhang(){
	cout << "================================" << endl;
    cout << "|| 1. NHAP DON HANG MOI        ||" << endl;
    cout << "|| 2. LICH SU MUA HANG         ||" << endl;
    cout << "|| 3. EXIT                     ||" << endl;
    cout << "================================" << endl;
}
void menuquanly(){
    cout << "================================" << endl;
    cout << "|| 1. QUAN LY KHO HANG         ||" << endl;
    cout << "|| 2. TIM KIEM SAN PHAM        ||" << endl;
    cout << "|| 4. CHINH SUA KHO HANG       ||" << endl;
    cout << "|| 3. EXIT                     ||" << endl;
    cout << "================================" << endl;
}
int main() {
    DonHang donHang;
    int lc1, lc2;
    SanPham sp1;
    while (true) {
        hienThiMenu();
        cout << "Nhap lua chon: ";
        cin >> lc1;
         _getch();
        system("cls");
        switch (lc1) {
            case 1:
                  menuquanly();
                 cout << "Nhap lua chon: ";
                  cin >> lc2;
                  _getch();
                  system("cls");
                  switch (lc2) {
                      case 1:
                         
                       break;
                      case 2:
                        
                        break;
                      case 3:
                       break;
                      default:
                       cout << "Lua chon khong hop le. Vui long chon lai.\n";
                  }
                  break;
            case 2:
                menudonhang();
                cout << "Nhap lua chon: ";
                  cin >> lc2;
                  _getch();
                  system("cls");
                  switch (lc2) {
                      case 1:
                       
                       break;
                      case 2:
                        
                        break;
                      case 3:
                       break;
                      default:
                       cout << "Lua chon khong hop le. Vui long chon lai.\n";
                  }
                  break;
            case 3:
                break;
             default:
                       cout << "Lua chon khong hop le. Vui long chon lai.\n";   
        }
        cout << "Nhan phim bat ky de tiep tuc...";
        _getch();
        system("cls");
    }

    return 0;
}

