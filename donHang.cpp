#include <iostream>
#include <fstream>
#include <cstring>
#include "donHang.h"

using namespace std;

DonHang::DonHang() : soLuongSanPham(0) {}

void DonHang::taoDonHang() {
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

void DonHang::hienThiDonHang() {
    cout << "=== Thong Tin Don Hang ===\n";
    for (int i = 0; i < soLuongSanPham; ++i) {
        danhSachSanPham[i].hienThiThongTin();
        cout << "----------------------------\n";
    }
}

long DonHang::tinhTongGiaTri() const {
    long tongGiaTri = 0;
    for (int i = 0; i < soLuongSanPham; ++i) {
        tongGiaTri += danhSachSanPham[i].layGia();
    }
    return tongGiaTri;
}

void DonHang::suaThongTinSanPham() {
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

void DonHang::xoaSanPham() {
    int id;
    cout << "Nhap ID san pham muon xoa: ";
    cin >> id;

    for (int i = 0; i < soLuongSanPham; ++i) {
        if (danhSachSanPham[i].layID() == id) {
            for (int j = i; j < soLuongSanPham - 1; ++j) {
                danhSachSanPham[j] = danhSachSanPham[j + 1];
            }
            soLuongSanPham--;
            cout << "San pham da duoc xoa.\n";
            return;
        }
    }
    cout << "Khong tim thay san pham voi ID: " << id << endl;
}

void DonHang::timKiemSanPham() {
    int id;
    cout << "Nhap ID san pham muon tim: ";
    cin >> id;

    for (int i = 0; i < soLuongSanPham; ++i) {
        if (danhSachSanPham[i].layID() == id) {
            danhSachSanPham[i].hienThiThongTin();
            return;
        }
    }
    cout << "Khong tim thay san pham voi ID: " << id << endl;
}

void DonHang::luuDonHang() {
    ofstream file("donhang.txt");
    if (!file) {
        cout << "Khong mo duoc file de ghi.\n";
        return;
    }

    file << soLuongSanPham << endl;
    for (int i = 0; i < soLuongSanPham; ++i) {
        file << danhSachSanPham[i].layID() << endl;
        file << danhSachSanPham[i].layTen() << endl;
        file << danhSachSanPham[i].layLoai() << endl;
        file << danhSachSanPham[i].laySize() << endl;
        file << danhSachSanPham[i].laySoLuong() << endl;
        file << danhSachSanPham[i].layGia() << endl;
    }
    file.close();
    cout << "Don hang da duoc luu vao file.\n";
}

void DonHang::taiDonHang() {
    ifstream file("donhang.txt");
    if (!file) {
        cout << "Khong mo duoc file de doc.\n";
        return;
    }

    file >> soLuongSanPham;
    for (int i = 0; i < soLuongSanPham; ++i) {
        int id, size, soluong;
        long price;
        char name[50], loai[30];

        file >> id;
        file.ignore();
        file.getline(name, 50);
        file.getline(loai, 30);
        file >> size >> soluong >> price;

        SanPham sp;
        sp.nhapThongTin(id, name, loai, size, soluong, price);
        danhSachSanPham[i] = sp;
    }
    file.close();
    cout << "Don hang da duoc tai tu file.\n";
}
