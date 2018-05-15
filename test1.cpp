#include<iostream>// THU VIEN C++
#include<vector>// KHAI BAO THU VIEN CUA VECTOR
#include<string>//KHAI BAO THU VIEN CUA CHUOI
#include<stdlib.h>//
#include <ctime>
using namespace std;// SU DUNG STD-CIN COUT
class NgayThangNam
{
public:
	NgayThangNam();// KHAI BAO HAM KHOI TAO MAC DINH NGAY THANG NAM
	~NgayThangNam();// HAM HUY DE HUY
	friend istream& operator >>(istream &,NgayThangNam &);// TOAN TU NHAP XUAT
	friend ostream& operator <<(ostream &,NgayThangNam);//
private: // KHAI BAO CAC THUOC TINH
	int Ngay_,Thang_,Nam_; // KHAI BAO BIEN NGAY ,THANG, NAM KIEU INT
};

NgayThangNam::NgayThangNam()// DINH NGHIA CHO HAM KHOI TAO MAC DINH
{
	Ngay_=Thang_=Nam_=0;// KHOI TAO TAT CA BAN DAU =0
}
NgayThangNam::~NgayThangNam()// DINH NGHIA CHO HAM HUY-
{
}
istream& operator>>(istream &is,NgayThangNam &ngay)// TOAN TU NHAP XUAT
{
	cout<<"\nNhap Ngay :";is>>ngay.Ngay_; cout<<"\nNhap Thang :";is>>ngay.Thang_; cout<<"\nNhap Nam: ";is>>ngay.Nam_;// XUAT RA- NHAP VAO
	return is;
}
ostream& operator<<(ostream &os,NgayThangNam ngay)//HAM TOAN TU NHAP XUAT
{
	os<<ngay.Ngay_<<"/"<<ngay.Thang_<<"/"<<ngay.Nam_<<endl;// XUAT RA NGAY THANG NAM
	return os;// TRA VE 
}
class SoTietKiem
{
public:
	virtual void Nhap();// PHAI DUNG HAM AO DE TY KE THUA
	virtual void Xuat();
	virtual unsigned int TinhTienLai()=0;//KIEU SO NGUYEN K DAU
protected:// KHAI BAO THUOC TINH
	string CMND_,Ten_;// KHAI BAO BIEN KIEU STRING
	unsigned int TienGui_;// KHAI BAO BIEN TIEN GUI KIEU SO' DUONG
	NgayThangNam ngay_;// VIEN' NGAY KIEU NGAYTHANGNAM
	float LaiXuat_;
	int n_;
};
void SoTietKiem::Nhap()// TRUY XUAT  GOI DEN HAM NHAP CUA LOP SOTIETKIEM
{
	cout<<"\nNhap Ten :";fflush(stdin);getline(cin,Ten_);// VI DUNG KIEU STRING NEN PHAI DUNG FFLUSH ,GETLINE
	cout<<"\nNhap CMND :";getline(cin,CMND_);
	cout<<"\nNhap Tien gui:";cin>>TienGui_;
	cout<<"\nNhap Ngay Lam So:";cin>>ngay_;
	cout<<"\nNhap Lai xuat (%): ";cin>>LaiXuat_;
	cout<<"\nNhap So thang can tinh Lai:";cin>>n_;
}
void SoTietKiem::Xuat()
{
	cout<<"\nTen :"<<Ten_;
	cout<<"\nCMND :"<<CMND_;
	cout<<"\nTien gui:"<<TienGui_;
	cout<<"\nNgay Lam So: "<<ngay_;
	cout<<"\nLai Xuat: "<<LaiXuat_<<"%";
}
class SoCoKyHan:public SoTietKiem// KE THUA 
{
public:
	void Nhap();
	void Xuat();
	unsigned int TinhTienLai();
private:
int KyHan_;
};
void SoCoKyHan::Nhap()
{
	SoTietKiem::Nhap();// GOI HAM NHAP C
	cout<<"\nNhap Ky Han :";cin>>KyHan_;
	
}
unsigned int SoCoKyHan::TinhTienLai()// TRUY XUAT GOI DEN HAM TINHTIENLAI CUA LOP SOCOKYHAN
{
	if(n_>KyHan_)//KTRA NEU SO THANG CAN TINH LAI~ NHAP VAO LOP HON KY HAN
		return LaiXuat_*n_*TienGui_;// THI TRA VE LAI SUAT *SO THANG CAN TINH LAI*TIEN GUI
	else
		return 0;
}
void SoCoKyHan::Xuat()
{
	cout<<"\n*********************";
	SoTietKiem::Xuat();
	cout<<"\nKy Han :"<<KyHan_;
	cout<<"\nTien Lai :"<<TinhTienLai();
}
class SoKhongKyHan:public SoTietKiem// KE THUA LOP SOTIETKIEM
{
	int n;
public:
	void Nhap();
	void Xuat();
	
	unsigned int TinhTienLai();
};
unsigned int SoKhongKyHan::TinhTienLai()
{

	return LaiXuat_*TienGui_*n;
}
void SoKhongKyHan::Nhap()
{

	SoTietKiem::Nhap();
		
}
void SoKhongKyHan::Xuat()
{
	SoTietKiem::Xuat();
	cout<<"\nTien Lai "<<TinhTienLai();
}
class CNganHang
{
public:
	void NhapDanhSach();
	void XuatDanhSach();
	void TinhTongTienLai();
private:
	vector<SoTietKiem*> sotietkiem_;
};
void CNganHang::NhapDanhSach()
{
	int choose;
	SoTietKiem* sotietkiem;
	do
	{
		system("cls");
		cout<<"\n1.Them so co ky han.";
		cout<<"\n2.Them so khong ky han.";
		cout<<"\n3.QuayLai!";
		cin>>choose;
		switch (choose)
		{
		case 1:
			{
				sotietkiem=new SoCoKyHan;
				sotietkiem->Nhap();
				sotietkiem_.push_back(sotietkiem);
			}
			break;
		case 2:
			{
				sotietkiem=new SoKhongKyHan;
				sotietkiem->Nhap();
				sotietkiem_.push_back(sotietkiem);
			}
			break;
		default:
			break;
		}
	} while (choose!=3);
}
void CNganHang::XuatDanhSach()
{
	system("cls");
	cout<<"\nDanh sach so:\n";
	for(int i=0;i<sotietkiem_.size();i++)
	{
		sotietkiem_[i]->Xuat();
	}
	system("pause>pls");
}
void CNganHang::TinhTongTienLai()
{
	system("cls");
	unsigned int S=0;
	for(int i=0;i<sotietkiem_.size();i++)
	{
		S+=sotietkiem_[i]->TinhTienLai();
	}
	cout<<"\nTong Tien Lai: "<<S;
	system("pause>pls");
}
void Menu(CNganHang nganhang)
{
	int choose;
	do
	{
		system("cls");
		cout<<"\n1.Them So";
		cout<<"\n2.Xuat Danh sach so";
		cout<<"\n3.Tinh tong lai";
		cout<<"\n4.Thoat";
		cin>>choose;
		switch (choose)
		{
		case 1:
				nganhang.NhapDanhSach();
			break;
		case 2:
			nganhang.XuatDanhSach();
			break;
		case 3:
			nganhang.TinhTongTienLai();
			break;
		default:
			break;
		}
	} while (choose!=4);
}
int main()
{
	
	CNganHang nganhang;
	Menu(nganhang);
	system("pause");
	return 0;
}
