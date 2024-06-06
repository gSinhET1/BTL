#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

// Số lượng sản phẩm tối đa trong đơn hàng
const int MAX_SAN_PHAM = 100;

// Định nghĩa lớp SanPham
class SanPham {
    int id;
    char name[50];
    char loai[30]; // danh cho nguoi lon, tre em, phu nu....
    int size;
    int soluong;
    long price;

public:
    // Hàm để nhập thông tin sản phẩm
    void nhapThongTin() {
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
    }

    // Hàm để hiển thị thông tin sản phẩm
    void hienThiThongTin() {
        cout << "==========================" << endl;
        cout << "|| Ten san pham:  " << name << endl;
        cout << "Loai san pham: " << loai << endl;
        cout << "Size san pham: " << size << endl;
        cout << "So luong san pham: " << soluong << endl;
        cout << "Gia san pham: " << price << endl;
        cout << ""
    }

    // Hàm để lấy giá sản phẩm
    long layGia() const {
        return price;
    }
};

// Định nghĩa lớp DonHang
class DonHang {
    SanPham danhSachSanPham[MAX_SAN_PHAM];
    int soLuongSanPham;

public:
    DonHang() : soLuongSanPham(0) {}

    // Hàm để thêm sản phẩm vào đơn hàng
    void taoDonHang() {
        if (soLuongSanPham >= MAX_SAN_PHAM) {
            cout << "Da vuot qua so luong san pham toi da trong don hang.\n";
            return;
        }

        SanPham sp;
        sp.nhapThongTin();
        danhSachSanPham[soLuongSanPham++] = sp;
        cout << "San pham da duoc them vao don hang.\n";
    }

    // Hàm để hiển thị thông tin đơn hàng
    void hienThiDonHang() {
        cout << "=== Thong Tin Don Hang ===\n";
        for (int i = 0; i < soLuongSanPham; ++i) {
            danhSachSanPham[i].hienThiThongTin();
            cout << "----------------------------\n";
        }
    }

    // Hàm để tính tổng giá trị đơn hàng
    long tinhTongGiaTri() const {
        long tongGiaTri = 0;
        for (int i = 0; i < soLuongSanPham; ++i) {
            tongGiaTri += danhSachSanPham[i].layGia();
        }
        return tongGiaTri;
    }
};

// Hàm để hiển thị menu
void hienThiMenu() {
    cout << "================================" << endl;
    cout << "|| 1. Dien thong tin don hang  ||" << endl;
    cout << "|| 2. Hien thi do mua sp       ||" << endl;
    cout << "|| 2. Dien thong tin san pham  || "<< endl;
    cout << "|| 3. Thong tin san pham       ||" << endl;
    cout << "|| 4. Lich su mua hang         ||" << endl;
    cout << "|| 5. Sua Thong tin            ||" << endl;
    cout << "|| 6. Tim kiem san pham        ||" << endl;
    cout << "|| 7. Thoat                    ||" << endl;
    cout << "================================" << endl;
}

int main() {
    DonHang donHang;
    int luaChon;
    SanPham sp1;
    while (true) {
        hienThiMenu();
        cout << "Nhap lua chon: ";
        cin >> luaChon;
         _getch();
        system("cls");
        switch (luaChon) {
            case 1:
                donHang.taoDonHang();
                break;
            case 2:
                sp1.nhapThongTin();
                break;
            case 3:
                sp1.hienThiThongTin();
                break;
            case 4:
                cout << "Chuc nang lich su mua hang chua duoc trien khai.\n";
                break;
            case 5:
                cout << "Chuc nang sua thong tin chua duoc trien khai.\n";
                break;
            case 6:
                cout << "Chuc nang tim kiem san pham chua duoc trien khai.\n";
                break;
            case 7:
                cout << "Thoat chuong trinh.\n";
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
        cout << "Nhan phim bat ky de tiep tuc...";
        _getch();
        system("cls");
    }

    return 0;
}
