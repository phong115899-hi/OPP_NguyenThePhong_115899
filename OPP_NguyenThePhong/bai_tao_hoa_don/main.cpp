
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class MatHang {
private:
    string tenMatHang;
    string dVT;
    int soLuong;
    double donGia;

public:
    void nhap() {
        cout << "Nhap ten san pham: ";
        getline(cin >> ws, tenSanPham);
        cout << "Nhap don vi tinh: ";
        getline(cin >> ws, donVT);
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap don gia: ";
        cin >> donGia;
    }
    double tinhThanhTien() {
        return soLuong * donGia;
    }
    void in(int soThuTu) {
        cout << left
             << setw(5) << soThuTu
             << setw(25) << tenSanPham
             << setw(12) << donViTinh
             << setw(10) << soLuong
             << setw(15) << fixed << setprecision(0)
             << donGia
             << setw(15) << tinhThanhTien()
             << endl;
    }
};

class HoaDon {
private:
    string soHoaDon;
    string ngayLap;
    string tenKhachHang;
    string diaChi;
    SanPham ds[100];
    int soSanPham;
    double thue;

public:
    HoaDon() {
        soSanPham = 0;
        thue = 0;
    }
    void nhapHoaDon() {
        cout << "\n===== NHAP HOA DON =====\n";
        cout << "Nhap so hoa don: ";
        getline(cin >> ws, soHoaDon);
        cout << "Nhap ngay lap: ";
        getline(cin >> ws, ngayLap);
        cout << "Nhap ten khach hang: ";
        getline(cin >> ws, tenKhachHang);
        cout << "Nhap dia chi: ";
        getline(cin >> ws, diaChi);
        cout << "Nhap so san pham: ";
        cin >> soMatHang;
        if (soMatHang < 0 || soMatHang > 100) {
            cout << "So san pham khong hop le!\n";
            soMatHang = 0;
            return;
        }
        for (int i = 0; i < soMatHang; i++) {
            cout << "\n--- San pham " << i + 1 << " ---\n";
            ds[i].nhap();
        }
        cout << "Nhap thue GTGT (%): ";
        cin >> thue;
        cout << "\nNhap hoa don thanh cong!\n";
    }
    double tinhTongTien() {
        double tong = 0;
        for (int i = 0; i < soMatHang; i++) {
            tong += ds[i].tinhThanhTien();
        }
        return tong;
    }
    double tinhTienThue() {
        return tinhTongTien() * thueSuat / 100;
    }
    double tinhThanhToan() {
        return tinhTongTien() + tinhTienThue();
    }
    void inHoaDon() {
        cout << " HOA DON BAN HANG \n";
        cout << "So hoa don: " << soHoaDon << endl;
        cout << "Ngay lap: " << ngayLap << endl;
        cout << "Khach hang: " << tenKhachHang << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << left
             << setw(5) << "STT"
             << setw(25) << "Ten san pham"
             << setw(12) << "Don vi"
             << setw(10) << "So luong"
             << setw(15) << "Don gia"
             << setw(15) << "Thanh tien"
             << endl;
        for (int i = 0; i < soMatHang; i++) {
            ds[i].xuat(i + 1);
        }
        cout << fixed << setprecision(0);
        cout << "Tong tien hang: " << tinhTongTien() << " VND\n";
        cout << "Thue GTGT (" << thueSuat << "%): "
             << tinhTienThue() << " VND\n";
        cout << "Tong thanh toan: "
             << tinhThanhToan() << " VND\n";
    }
};
int main() {
    HoaDon hoaDon;
    hoaDon.nhapHoaDon();
    hoaDon.inHoaDon();
    return 0;
}
