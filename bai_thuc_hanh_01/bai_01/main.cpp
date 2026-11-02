#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Xe {
private:
    int maXe;
    string loaiXe;
    int gioVao;
    int thoiGianDo;
    double phiDoXe;
    bool dangChiemCho;
public:
    Xe();
    Xe(int ma, const string& loai, int gio, int thoiLuong);
    int layMaXe() const;
    string layLoaiXe() const;
    int layGioVao() const;
    int layThoiGianDo() const;
    double layPhiDoXe() const;
    bool layDangChiemCho() const;
    void ganMaXe(int ma);
    void ganLoaiXe(const string& loai);
    void ganGioVao(int gio);
    void ganThoiLuongDo(int thoiLuong);
    void ganPhiDoXe(double phi);
    void ganDangChiemCho(bool trangThai);
    static string chuanHoaLoaiXe(const string& loai);
    static bool laLoaiXeHopLe(const string& loai);
    void tinhPhiDoXe();
    void hienThi() const;
};
Xe::Xe() {
        maXe = 0;
        loaiXe = "";
        gioVao = 0;
        thoiGianDo = 0;
        phiDoXe = 0.0;
        dangChiemCho = false;
}
Xe::Xe(int ma, const string& loai, int gio, int thoiLuong) {
    maXe = ma;
    loaiXe = chuanHoaLoaiXe(loai);
    gioVao = gio;
    thoiGianDo =thoiLuong;
    dangChiemCho = false;
    tinhPhiDoXe();
}

class BaiDoXe {
private:
    int maBai;
    char kichThuoc;
    Xe Xe1, Xe2, Xe3;
    bool coXe1, coXe2, coXe3;
public:
    BaiDoXe();
    BaiDoXe(int ma, char size);
    int layMaBai() const;
    char layKichThuoc() const;
    int laySucChua() const;
    int demXe() const;
    bool themXe(const Xe& v);
    bool xoaXe(int vID);
    bool coXeVoiMa(int vID) const;
    void hienThiThongTinBai() const;
    int hienThiXeTheoLoai(const string& loai) const;
    int demXeTheoLoai(const string& loai) const;
    double tongPhiTheoLoai(const string& loai) const;
};
BaiDoXe::BaiDoXe() {
    maBai = 0;
    kichThuoc = 'S';
    coXe1 = false;
    coXe2 = false;
    coXe3 = false;
}
BaiDoXe::BaiDoXe(int ma, char size) {
    maBai = Ma;
    kichThuoc = toupper(size);
    coXe1 = false;
    coXe2 = false;
    coXe3 = false;
}

class GiaoDien {
private:
    BaiDoXe baiDo1, baiDo2, baiDo3;
    bool coBai1, coBai2, coBai3;

    BaiDoXe& layBai(int vt);
    bool coBai(int vt) const;
    int timBaiTheoMa(int maBai);
    bool xeDaTonTai(int maXe);
    int docSo(const string& thongBao);

    void taoBaiMoi();
    void themXeVaoBai();
    void xoaBai();
    void layXeRa();
    void hienThiTatCaBai();
    void hienThiXeTheoBai();
    void lietKeTheoLoai();
    void baoCaoPhi();
    void baoCaoMotLoai(const string& loai);
public:
    GiaoDien();
    void runMenu();
};

GiaoDien::GiaoDien() {
    coBai1 = false;
    coBai2 = false;
    coBai3 = false;
}

BaiDoXe& GiaoDien::layBai(int vt) {
    if (vt == 1) return baiDo1;
    if (vt == 2) return baiDo2;
    return baiDo3;
}



int main() {
    GiaoDien gd;
    gd.runMenu();
    return 0;
}
