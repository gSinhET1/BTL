#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

const int MAX_SAN_PHAM = 100;


class SanPham {
    int id;
    char name[50];
    char loai[30]; // danh cho nguoi lon, tre em, phu nu....
    int size;
    int soluong;
    long price;
    static SanPham danhSachSanPham[MAX_SAN_PHAM];
    static int soLuongSanPham;


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
    void chinhSuaDonHang() {
        int id;
        cout << "Nhap ID san pham muon chinh sua trong don hang: ";
        cin >> id;
        for (int i = 0; i < soLuongSanPham; ++i) {
            if (danhSachSanPham[i].layID() == id) {
                cout << "Nhap thong tin moi cho san pham:\n";
                danhSachSanPham[i].nhapThongTin();
                cout << "Thong tin san pham trong don hang da duoc cap nhat.\n";
                return;
            }
        }
        cout << "Khong tim thay san pham voi ID: " << id << endl;
    }
};
void hienThiMenu() {
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "                         ================================" << endl;
    cout << "                         || 1. QUAN LY KHO HANG         ||" << endl;
    cout << "                         || 2. QUAN LY BAN HANG         ||" << endl;
    cout << "                         || 3. EXIT                     ||" << endl;
    cout << "                         ================================" << endl;
}
void menudonhang(){
	cout << "================================" << endl;
    cout << "|| 1. Dien thong tin don hang  ||" << endl;
    cout << "|| 2. Hien thi don hang        ||" << endl;
    cout << "|| 3. Lich su mua hang         ||" << endl;
    cout << "|| 4. Chinh sua don hang       ||"<< endl;
    cout << "|| 4. EXIT                     ||" << endl;
    cout << "================================" << endl;
}
void menuquanly(){
    cout << "================================" << endl;
    cout << "|| 1. Them thong tin san pham  ||" << endl;
    cout << "|| 2. Hien thi san pham        ||" << endl;
    cout << "|| 3. Tim kiem san pham        ||" << endl;
    cout << "|| 4. Chinh sua thong tin sp   ||" << endl;
    cout << "|| 5. EXIT                     ||" << endl;
    cout << "================================" << endl;
}
int main() {
    DonHang donHang;
    int luaChon;
    SanPham sp1;
    int lc1, lc2;
    while (true) {
        hienThiMenu();
        cout << "Nhap lua chon: ";
        cin >> lc1;
        _getch();
        system("cls");
        switch (lc1) {
            case 2:
                do {
                    menudonhang();
                    cout << "Nhap lua chon: ";
                    cin >> lc2;
                    _getch();
                    system("cls");
                    switch (lc2) {
                        case 1:
                            donHang.taoDonHang();
                            break;
                        case 2:
                            donHang.hienThiDonHang();
                            break;
                        case 3:
                            cout << "\n chuc nang chua duoc cap nhat";
                            break;
                        case 4:
                            break;
                        default:
                            cout << "Lua chon khong hop le. Vui long chon lai.\n";
                    }
                    system("cls");
                } while (lc2 != 4);
                break;
            case 1:
                do {
                    menuquanly();
                    cout << "Nhap lua chon: ";
                    cin >> lc2;
                    _getch();
                    system("cls");
                    switch (lc2) {
                        case 1:
                            char c;
                            do {
                                sp1.nhapThongTin();
                                cout << "Ban co muon tiep tuc them san pham khong: Y/N?";
                                cin >> c;
                            } while (c == 'Y' || c == 'y');
                            break;
                        case 2:
                            sp1.hienThiDanhSachSanPham();
                            _getch();
                            break;
                        case 3:
                            cout << "\n chuc nang tim kiem san phan chua cap nhat";
                            break;
                        case 4:
                            sp1.suaThongTinSanPham();
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Lua chon khong hop le. Vui long chon lai.\n";
                    }
                    cout << "Nhan phim bat ky de tiep tuc...";
                    _getch();
                    system("cls");
                } while (lc2 != 5);
                break;
            case 3:
                exit(0);
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    }
}
