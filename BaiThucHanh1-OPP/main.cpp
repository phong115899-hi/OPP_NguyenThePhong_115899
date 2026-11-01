#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Xe {
private:
    int MaXe;
    string LoaiXe;
    int GioVao;
    int ThoiGianDo;
    double PhiDoXe;
    bool DangChiemCho;
public:
    Xe();
    Xe(int Ma, const string& Loai, int Gio, int ThoiLuong);
    int LayMaXe() const;
    string LayLoaiXe() const;
    int LayGioVao() const;
    int LayThoiGianDo() const;
    double LayPhiDoXe() const;
    bool LayDangChiemCho() const;
    void GanMaXe(int ma);
    void GanLoaiXe(const string& loai);
    void GanGioVao(int gio);
    void GanThoiLuongDo(int thoiLuong);
    void GanPhiDoXe(double phi);
    void GanDangChiemCho(bool trangThai);
    static string ChuanHoaLoaiXe(const string& loai);
    static bool LaLoaiXeHopLe(const string& loai);
    void TinhPhiDoXe();
    void HienThi() const;
};
Xe() {
        vehicleID = 0;
        vehicleType = "";
        entryTime = 0;
        parkingDuration = 0;
        parkingFee = 0.0;
        isOccupied = false;
}
Xe(int Ma, const string& Loai, int Gio, int ThoiLuong) {
    MaXe = Ma;
    LoaiXe = ChuanHoaLoaiXe(loai);
    GioVao = Gio;
    ThoiGianDo =ThoiLuong;
    DangChiemCho = false;
    TinhPhiDoXe();
}

class BaiDoXe {
private:
    int MaBai;
    char KichThuoc;
    Xe Xe1, Xe2, Xe3;
    bool CoXe1, CoXe2, CoXe3;
public:
    BaiDoXe();
    BaiDoXe(int Ma, char size);
    int LayMaBai() const;
    char LayKichThuoc() const;
    int LaySucChua() const;
    int DemXe() const;
    bool ThemXe(const Xe& v);
    bool XoaXe(int vID);
    bool CoXeVoiMa(int vID) const;
    void HienThiThongTinBai() const;
    int HienThiXeTheoLoai(const string& loai) const;
    int DemXeTheoLoai(const string& loai) const;
    double TongPhiTheoLoai(const string& loai) const;
};
BaiDoXe() {
    MaBai = 0;
    KichThuoc = 'S';
    coXe1 = false;
    coXe2 = false;
    coXe3 = false;
}
BaiDoXe(int ma, char size) {
    MaBai = Ma;
    TichThuoc = toupper(size);
    CoXe1 = false;
    CoXe2 = false;
    CoXe3 = false;
}

class GiaoDien {
private:
    BaiDoXe BaiDo1, BaiDo2, BaiDo3;
    bool CoBai1, CoBai2, CoBai3;

    BaiDoXe& LayBai(int vt);
    bool CoBai(int vt) const;
    int TimBaiTheoMa(int maBai);
    bool XeDaTonTai(int maXe);
    int DocSo(const string& thongBao);

    void TaoBaiMoi();
    void ThemXeVaoBai();
    void XoaBai();
    void LayXeRa();
    void HienThiTatCaBai();
    void HienThiXeTheoBai();
    void LietKeTheoLoai();
    void BaoCaoPhi();
    void BaoCaoMotLoai(const string& loai);
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


