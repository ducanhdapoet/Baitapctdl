#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct GioHang {
    string sanPham;
    int soLuong;
    double giaDonVi;
    double tongTien;
    GioHang(string sp, int sl, double gia) {
        sanPham = sp;
        soLuong = sl;
        giaDonVi = gia;
        tongTien = soLuong * giaDonVi;
    }
};
double tinhTongTien(queue<GioHang>& hangDoi) {
    double tong = 0;
    queue<GioHang> tam = hangDoi;
    while (!tam.empty()) {
        tong += tam.front().tongTien;
        tam.pop();
    }
    return tong;
}
int demSanPhamA(queue<GioHang>& hangDoi) {
    int tongA = 0;
    queue<GioHang> tam = hangDoi;
    while (!tam.empty()) {
        if (tam.front().sanPham == "A") {
            tongA += tam.front().soLuong;
        }
        tam.pop();
    }
    return tongA;
}
void thanhToan(queue<GioHang>& hangDoi) {
    if (!hangDoi.empty()) {
        cout << "Thanh toan: " << hangDoi.front().sanPham 
             << ", So luong: " << hangDoi.front().soLuong 
             << ", Tong tien: " << hangDoi.front().tongTien << endl;
        hangDoi.pop();
    } else {
        cout << "Hang doi rong!" << endl;
    }
}
int main() {
    queue<GioHang> hangDoi;
    hangDoi.push(GioHang("A", 5, 10.0));
    hangDoi.push(GioHang("B", 3, 20.0));
    hangDoi.push(GioHang("A", 2, 10.0));
    hangDoi.push(GioHang("C", 1, 50.0));
    thanhToan(hangDoi);
    thanhToan(hangDoi);
    double tongTien = tinhTongTien(hangDoi);
    cout << "Tong tien thu duoc: " << tongTien << endl;
    int soLuongA = demSanPhamA(hangDoi);
    cout << "So luong san pham A da ban: " << soLuongA << endl;
    return 0;
}
