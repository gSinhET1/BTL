#include<iostream>
using namespace std;
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
    int luaChon;
    while (true) {
        hienThiMenu();
        cout << "Nhap lua chon: ";
        cin >> luaChon;
         _getch();
        system("cls");
        switch (luaChon) {
            case 1:
               
                break;
            case 2:
                
                break;
            case 3:
                
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
	
	
	
	
	
	
	
	
	
	return 0;
}
