
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define MAX_PRODUCTS 100
    #define MAX_ORDERS 100

    // Định nghĩa lớp Product
    typedef struct {
        int id;
        char name[50];
        char category[30];
        int size;
        char color[20];
        int quantity;
        float price;
    } Product;

    // Định nghĩa lớp Order
    typedef struct {
        int orderId;
        int productId;
        int quantity;
    } Order;

    // Định nghĩa lớp Store chứa các danh sách sản phẩm và đơn hàng
    typedef struct {
        Product products[MAX_PRODUCTS];
        Order orders[MAX_ORDERS];
        int productCount;
        int orderCount;
    } Store;

    // Khởi tạo cửa hàng
    void initStore(Store* store) {
        store->productCount = 0;
        store->orderCount = 0;
    }

    // Thêm sản phẩm
    void addProduct(Store* store) {
        if (store->productCount >= MAX_PRODUCTS) {
            printf("Khong the them san pham moi, da dat gioi han.\n");
            return;
        }
        Product p;
        p.id = store->productCount + 1;
        getchar();
        printf("Nhap ten san pham: ");
        fgets(p.name, sizeof(p.name), stdin);
        printf("Nhap danh muc san pham: ");
        fgets(p.category, sizeof(p.category), stdin);
        printf("Nhap kich co: ");
        scanf("%d", &p.size);
        printf("Nhap mau sac: ");
        getchar();
        fgets(p.color, sizeof(p.color), stdin);
        printf("Nhap so luong: ");
        scanf("%d", &p.quantity);
        printf("Nhap gia: ");
        scanf("%f", &p.price);

        store->products[store->productCount] = p;
        store->productCount++;
        printf("Da them san pham thanh cong.\n");
    }

    // Hiển thị sản phẩm
    void displayProducts(const Store* store) {
        for (int i = 0; i < store->productCount; i++) {
            printf("ID: %d, Ten: %s, Danh muc: %s, Kich co: %d, Mau sac: %s, Soluong: %d, Gia: %.2f\n",
                   store->products[i].id, store->products[i].name, store->products[i].category, store->products[i].size,
                   store->products[i].color, store->products[i].quantity, store->products[i].price);
        }
    }

    // Cập nhật tồn kho
    void updateStock(Store* store) {
        int id, newQuantity;
        printf("Nhap ID san pham ton kho: ");
        scanf("%d", &id);
        printf("Nhap so luong moi: ");
        scanf("%d", &newQuantity);

        for (int i = 0; i < store->productCount; i++) {
            if (store->products[i].id == id) {
                store->products[i].quantity = newQuantity;
                printf("Da cap nhat so luong ton kho.\n");
                return;
            }
        }
        printf("Khong tim thay san pham voi ID da nhap.\n");
    }

    // Tạo đơn hàng
    void createOrder(Store* store) {
        if (store->orderCount >= MAX_ORDERS) {
            printf("Khong the tao don hang moi, da toi gioi han.\n");
            return;
        }
        Order o;
        o.orderId = store->orderCount + 1;
        printf("Nhap ID san pham: ");
        scanf("%d", &o.productId);
        printf("Nhap so luong: ");
        scanf("%d", &o.quantity);

        for (int i = 0; i < store->productCount; i++) {
            if (store->products[i].id == o.productId) {
                if (store->products[i].quantity < o.quantity) {
                    printf("So luong khong du de tao don hang.\n");
                    return;
                } else {
                    store->products[i].quantity -= o.quantity;
                    store->orders[store->orderCount] = o;
                    store->orderCount++;
                    printf("Da tao don hang thanh cong.\n");
                    return;
                }
            }
        }
        printf("Khong tim thay san pham voi ID da nhap.\n");
    }

    int main() {
        Store store;
        initStore(&store);

        int choice;
        while (1) {
            printf("\n1. Them san pham\n2. Hien thi san pham\n3. Cap nhat ton kho\n4. Tao don hang\n5. Exit\n");
            printf("Nhap lua chon cua ban: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    addProduct(&store);
                    break;
                case 2:
                    displayProducts(&store);
                    break;
                case 3:
                    updateStock(&store);
                    break;
                case 4:
                    createOrder(&store);
                    break;
                case 5:
                    return 0;
                default:
                    printf("Lua chon khong hop le   .\n");
            }
        }
        return 0;
    }

