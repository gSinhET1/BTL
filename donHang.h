#ifndef DONHANG_H_INCLUDED
#define DONHANG_H_INCLUDED
#include "SanPham.h"

const int MAX_SAN_PHAM = 100;

class DonHang {
    SanPham danhSachSanPham[MAX_SAN_PHAM];
    int soLuongSanPham;

public:
    DonHang();
    void taoDonHang();
    void hienThiDonHang();
    long tinhTongGiaTri() const;
    void suaThongTinSanPham();
    void xoaSanPham();
    void timKiemSanPham();
    void luuDonHang();
    void taiDonHang();
};

#endif // DONHANG_H_INCLUDED
