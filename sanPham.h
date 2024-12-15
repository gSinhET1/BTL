#ifndef SANPHAM_H_INCLUDED
#define SANPHAM_H_INCLUDED

class SanPham {
    int id;
    char name[50];
    char loai[30];
    int size;
    int soluong;
    long price;

public:
    void nhapThongTin();
    void hienThiThongTin();
    long layGia() const;
    int layID() const;
    void nhapThongTin(int id, const char* name, const char* loai, int size, int soluong, long price);
};


#endif // SANPHAM_H_INCLUDED
