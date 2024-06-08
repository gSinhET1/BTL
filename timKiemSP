void timKiemSanPham() {
    	int id;
    	cout << "Nhap ID san pham muon tim: ";
        cin >> id;
        for (int i = 0; i < soLuongSanPham; ++i) {
            if (danhSachSanPham[i].layID() == id) {
                cout << "=== Thong tin san pham tim kiem ===\n";
                danhSachSanPham[i].hienThiThongTin();
                return;
            }
        }
        cout << "Khong tim thay san pham voi ID: " << id << endl;
    }
