#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#define MAX 100
void textcolor(int x){
	HANDLE y = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(y, x);
}
struct DoAn{
	char MaDoAn[20];
	char MaSinhVien[20];
	std::string TenGiaoVienHD;
	int diemso;
};
void flush_file(std::ifstream& f) { //Ham xoa dau ENTER trong file
	char c;
	while (f.get(c) && c != '\n' && c != std::ifstream::traits_type::eof());
}
//Yeu cau 1
int inputDoAn(DoAn* do_an, int* n, char file_input[]) {
	std::ifstream file;
	file.open(file_input);
	if (!file) {
		std::cout << "File khong ton tai";
		return 0;
	}
	file >> *n;
	flush_file(file);
	for (int i = 0; i < *n; i++) {
		file >> do_an[i].MaDoAn;
		file >> do_an[i].MaSinhVien;
		flush_file(file);
		getline(file, do_an[i].TenGiaoVienHD);
		file >> do_an[i].diemso;
		flush_file(file);
	}
	file.close();
	return 1;
}
void outputDoAn(DoAn do_an[], int *n){
	std::cout << "So luong do an: " << *n << '\n';
	std::cout << "Danh sach cac do an: \n";
	for (int i = 0; i < *n; i++){
		std::cout << "Do an thu " << i + 1 << std::endl;
		std::cout << "Ma do an: " << do_an[i].MaDoAn << std::endl;
		std::cout << "Ma sinh vien: " << do_an[i].MaSinhVien << std::endl;
		std::cout << "Ten giao vien huong dan: " << do_an[i].TenGiaoVienHD << std::endl;
		std::cout << "Diem so: " << do_an[i].diemso << std::endl << std::endl;
	}
}
//Yeu cau 2
void lietke2(DoAn do_an[], int n){
	int dem = 0;
	std::string tengiaovien;
	for (int j = 0; j < n; j++){
		tengiaovien = do_an[j].TenGiaoVienHD;
		for (int i = 0; i < n; i++)
			//if (do_an[i].TenGiaoVienHD.compare(tengiaovien) == 0)
			if (do_an[i].TenGiaoVienHD == tengiaovien)
				dem++;
		if (dem > 1) {
			std::cout << tengiaovien << std::endl;
		}
		dem = 0;
	}
}
//Yeu cau 3
int timmax(DoAn do_an[], int n){
	int max = do_an[0].diemso;
	for (int i = 0; i < n; i++)
		if (do_an[i].diemso > max)
			max = do_an[i].diemso;
	return max;
}
void xuatmasinhvien(DoAn do_an[], int n){
	for (int i = 0; i < n; i++){
		if (do_an[i].diemso == timmax(do_an, n)) {
			std::cout << do_an[i].MaSinhVien << '\n';
		}
	}
}
//Yeu cau 4
void lietke4(DoAn do_an[], int n){
		for (int i = 0; i < n; i++)
			std::cout << do_an[i].TenGiaoVienHD << std::endl;
}
void clearFile(char filename[]) {
	std::ofstream ofs;
	ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}
int select(){
	int o;
	std::cout << "Moi ban nhap yeu cau(Nhap so 0 de thoat chuong trinh): ";
	std::cin >> o;
	while (!(o >= 0 && o <= 6)){
		std::cout << "Yeu cau khong hop le, vui long ban nhap lai: ";
		std::cin >> o;
	}
	return o;
}
void program(){
	textcolor(12);
	DoAn do_an[MAX];
	char file_input[] = "KT1.txt";
	int n = 0;
	int o = select();
	switch (o) {
		case 1:{
					textcolor(14);
					if (inputDoAn(do_an, &n, file_input))
						std::cout << "Nhap danh sach cac do an thanh cong" << std::endl;
					outputDoAn(do_an, &n);
		}break;
		case 2:{
				   textcolor(9);
				   inputDoAn(do_an, &n, file_input);
				   std::cout << "Giao vien tham gia huong dan tu 2 do an tro len:\n";
				   lietke2(do_an, n);
		}break;
		case 3:{
				   textcolor(11);
				   inputDoAn(do_an, &n, file_input);
				   std::cout << "Cac ma sinh vien co diem do an lon nhat la: \n";
				   xuatmasinhvien(do_an, n);
		}break;
		case 4:{
				   textcolor(10);
				   inputDoAn(do_an, &n, file_input);
				   std::cout << "Cac giao vien co huong dan do an trong danh sach: \n";
				   lietke4(do_an, n);
		}break;
		case 5:{
				   inputDoAn(do_an, &n, file_input);

		}break;
		case 6:{
				   inputDoAn(do_an, &n, file_input);

		}break;
		default: {
					 std::cout << "Thoat chuong trinh trong ";
					 for (int i = 3; i >= 1; i--) {
						 std::cout << i;
						 Sleep(1000);
						 std::cout << '\b';
					 }
					 Sleep(500);
					 exit(0);
		}
			break;
	}
	
}
int main(){
	while (true)
		program();
	system("pause");
	return 0;
}
