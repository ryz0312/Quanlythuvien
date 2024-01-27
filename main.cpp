#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Book {
 string isbn;
 string title;
 string subject;
 string author;
 string publisher;
 string date;
 int pages;
 int copies;
};
struct User {
 int userid;
 string username;
 string password;
 string role;
};
vector<Book> books;
vector<User> users;
void hien_thi_nguoi_dung(const User& user) {
 cout << "ID: " << user.userid << "\n";
 cout << "Ten truy cap: " << user.username << "\n";
 cout << "Mat khau: " << user.password << "\n";
 cout << "Cap nguoi dung: " << user.role << "\n";
}
void sua_nguoi_dung(const string& username) {
 cout << "===== SUA NGUOI DUNG =====\n";
 cout << "Nhap thong tin nguoi dung:\n";
 User newUser;
 cout << "Ten truy cap: ";
 cin >> newUser.username;
 cout << "Mat khau: ";
 cin >> newUser.password;
 cout << "Cap nguoi dung (user hoac admin): ";
 cin >> newUser.role;
 for (auto& user : users) {
 if (user.username == username) {
 newUser.userid = user.userid;
 user = newUser;
 cout << "Sua nguoi dung thanh cong.\n";
 hien_thi_nguoi_dung(user);
 return;
 }
 }
 cout << "Khong tim thay nguoi dung voi ten '" << username << "'\n";
}
void xoa_nguoi_dung(const string& username) {
 auto it = find_if(users.begin(), users.end(),
 [username](const User& user) { return user.username == username; });
 if (it != users.end()) {
 users.erase(it);
 cout << "Da xoa nguoi dung co ten '" << username << "'\n";
 } else {
 cout << "Khong tim thay nguoi dung voi ten '" << username << "'\n";
 }
}
void tim_kiem_nguoi_dung() {
 do {
 string username;
 bool found = false;
 cout << "===== TIM KIEM NGUOI DUNG =====\n";
 cout << "Nhap ten nguoi dung: ";
 cin >> username;
 for (const auto& user : users) {
 if (user.username == username) {
 hien_thi_nguoi_dung(user);
 found = true;
 }
 }
 char choice;
 if(!found)
 cout << "Khong tim thay nguoi dung voi ten: '" << username << "'\n";
 cout << "1. Tim kiem nguoi dung khac" << endl;
 cout << "2. Tro ve trang chu" << endl;
 if(found){
 cout << "3. Xoa nguoi dung" << endl;
 cout << "4. Sua nguoi dung" << endl;
}
 cout << "Nhap lua chon cua ban: ";
 cin >> choice;
 switch (choice) {
 case '1':
 break;
 case '2':
 return;
 case '3':
 if(found){
 xoa_nguoi_dung(username);
 return;
}
else{
cout << "Lua chon khong hop le. Vui long nhap lai.\
n";
 break;
}
 case '4':
 if(found){
 sua_nguoi_dung(username);
 return;
}else{
cout << "Lua chon khong hop le. Vui long nhap lai.\
n";
 break;
}
 default:
 cout << "Lua chon khong hop le. Vui long nhap lai.\n";
 break;
 }
 } while (true);
}
void them_nguoi_dung() {
cout << "===== THEM NGUOI DUNG =====\n";
 User newUser;
 cout << "Nhap thong tin nguoi dung:\n";
newUser.userid = users.size() + 1;
 cout << "Ten truy cap: ";
cin >> newUser.username;
 cout << "Mat khau: ";
cin >> newUser.password;
 cout << "Cap nguoi dung (user hoac admin): ";
cin >> newUser.role;
 users.push_back(newUser);
 cout << "Them nguoi dung thanh cong.\n";
}
void hien_thi_sach(const Book& book) {
 cout << "ISBN: " << book.isbn << "\n";
 cout << "Ten sach: " << book.title << "\n";
 cout << "Chu de: " << book.subject << "\n";
 cout << "Tac gia: " << book.author << "\n";
 cout << "Nha xuat ban: " << book.publisher << "\n";
 cout << "Ngay xuat ban: " << book.date << "\n";
 cout << "So trang: " << book.pages << "\n";
 cout << "So ban copy: " << book.copies << "\n";
}
void xoa_sach(const string& title) {
 auto it = find_if(books.begin(), books.end(),
 [title](const Book& book) { return book.title == title; });
 if (it != books.end()) {
 books.erase(it);
 cout << "Da xoa sach co tieu de '" << title << "'\n";
 } else {
 cout << "Khong tim thay sach voi tieu de '" << title << "'\n";
 }
}
void sua_sach(const string& title) {
 cout << "===== SUA SACH =====\n";
 Book newBook;
 cout << "Nhap thong tin sach:\n";
 cout << "ISBN: ";
cin >> newBook.isbn;
 cout << "Ten sach: ";
cin.ignore();
getline(cin, newBook.title);
 cout << "Chu de: ";
getline(cin, newBook.subject);
 cout << "Tac gia: ";
getline(cin, newBook.author);
 cout << "Nha xuat ban: ";
getline(cin, newBook.publisher);
 cout << "Ngay xuat ban: ";
cin >> newBook.date;
 cout << "So trang: ";
cin >> newBook.pages;
 cout << "So ban copy: ";
cin >> newBook.copies;
 for (auto& book : books) {
 if (book.title == title) {
 book = newBook;
 cout << "Sua sach thanh cong.\n";
 hien_thi_sach(book);
 return;
 }
 }
 cout << "Khong tim thay sach voi tieu de '" << title << "'\n";
}
void tim_kiem_sach(string role){
do {
 string title, subject, author, publisher, date;
        bool found = false;
        cout << "===== TIM KIEM SACH =====\n";
        cout << "Nhap tieu de sach (de trong neu khong tim kiem theo tieu de): ";
        cin.ignore();
        getline(cin, title);
        cout << "Nhap chu de sach (de trong neu khong tim kiem theo chu de): ";
        getline(cin, subject);
        cout << "Nhap tac gia sach (de trong neu khong tim kiem theo tac gia): ";
        getline(cin, author);
        cout << "Nhap nha xuat ban sach (de trong neu khong tim kiem theo nha xuat ban): ";
        getline(cin, publisher);
        cout << "Nhap nam xuat ban sach (de trong neu khong tim kiem theo nam xuat ban): ";
        getline(cin, date);

        for (const auto& book : books) {
            if ((title.empty() || book.title.find(title) != string::npos) &&
                (subject.empty() || book.subject.find(subject) != string::npos) &&
                (author.empty() || book.author.find(author) != string::npos) &&
                (publisher.empty() || book.publisher.find(publisher) != string::npos) &&
                (date.empty() || book.date.find(date) != string::npos)) {
                hien_thi_sach(book);
                found = true;
            }
        }
 char choice;
 if(!found)
 cout << "Khong tim thay sach voi tieu de: '" << title << "'\n";
 cout << "1. Tim kiem sach khac" << endl;
 cout << "2. Tro ve trang chu" << endl;
 if(found && role == "admin"){
 cout << "3. Xoa sach" << endl;
 cout << "4. Sua sach" << endl;
}
 cout << "Nhap lua chon cua ban: ";
 cin >> choice;
 switch (choice) {
 case '1':
 break;
 case '2':
 return;
 case '3':
 if(found && role == "admin"){
 xoa_sach(title);
 return;
}else{
cout << "Lua chon khong hop le. Vui long nhap lai.\
n";
 break;
}
 case '4':
 if(found && role == "admin"){
 sua_sach(title);
 return;
 }else{
 cout << "Lua chon khong hop le. Vui long nhap lai.\n";
 break;
}
 default:
 cout << "Lua chon khong hop le. Vui long nhap lai.\n";
 break;
 }
 } while (true);
}
void them_sach(){
cout << "===== THEM SACH =====\n";
Book newBook;
 cout << "Nhap thong tin sach:\n";
 cout << "ISBN: ";
cin >> newBook.isbn;
 cout << "Ten sach: ";
cin.ignore();
getline(cin, newBook.title);
 cout << "Chu de: ";
getline(cin, newBook.subject);
 cout << "Tac gia: ";
getline(cin, newBook.author);
 cout << "Nha xuat ban: ";
getline(cin, newBook.publisher);
 cout << "Ngay xuat ban: ";
cin >> newBook.date;
 cout << "So trang: ";
cin >> newBook.pages;
 cout << "So ban copy: ";
cin >> newBook.copies;
 books.push_back(newBook);
 cout << "Sach da duoc them thanh cong.\n";
}
void dang_nhap(bool& is_logined, string& role) {
 cout << "===== DANG NHAP =====\n";
 string username, password;
 do {
 cout << "Nhap ten tai khoan: ";
 cin >> username;
 cout << "Nhap mat khau: ";
 cin >> password;
 for (const auto& user : users) {
 if (user.username == username && user.password == password) {
 is_logined = true;
 role = user.role;
 cout << "Dang nhap thanh cong" << endl;
 return;
 }
 }
 char choice;
 cout << "Thong tin tai khoan hoac mat khau khong chinh xac." << endl;
 cout << "1. Nhap lai thong tin" << endl;
 cout << "2. Tro ve trang chu" << endl;
 cout << "Nhap lua chon cua ban: ";
 cin >> choice;
 switch (choice) {
 case '1':
 break;
 case '2':
 return;
 default:
 cout << "Lua chon khong hop le. Vui long nhap lai.\n";
 break;
 }
 } while(true);
}
void dang_xuat(bool& is_logined, string& role){
is_logined = false;
role = "user";
cout << "Dang xuat thanh cong" << endl;
}
void hien_thi_menu(const vector<string>& menu) {
 for (const auto& item : menu) {
 cout << item << "\n";
 }
}
void hien_thi_danh_sach_sach() {
    if (books.empty()) {
        cout << "Khong co sach nao trong thu vien.\n";
    } else {
        cout << "===== DANH SACH SACH =====\n";
        for (const auto& book : books) {
            hien_thi_sach(book);
            cout << "\n";
        }
    }
}
void tao_du_lieu(){
 User user1;
 user1.userid = 1;
 user1.username = "admin";
 user1.password = "adminpass1";
 user1.role = "admin";
 users.push_back(user1);

 Book book1;
 book1.isbn = "DS001";
 book1.title = "Dai so";
 book1.publisher = "NXB GD";
 book1.subject = "Dai cuong";
 book1.author = "Nguyen Van A";
 book1.date = "22-06-2008";
 book1.pages = 230;
 book1.copies = 3;
 books.push_back(book1);
}
int main() {
tao_du_lieu();
 char choice;
 bool is_logined = false;
 string role = "user";
 vector<string> menu_user = {"1. Tim kiem sach","6. Hien thi danh sach sach"};
 vector<string> menu_admin = {"1. Tim kiem sach", "2. Them sach", "3. Tim kiem nguoi dung", "4. Them nguoi dung","6. Hien thi danh sach sach" } ;
 vector<string> menu = menu_user;
 do {
 menu = role == "admin" ? menu_admin : menu_user;
 cout << "===== CHUONG TRINH QUAN LY THU VIEN =====\n";
 hien_thi_menu(menu);
 cout << (is_logined ? "x. Dang xuat\n" : "y. Dang nhap\n");
 cout << "0. Thoat\n";
 cout << "Nhap lua chon cua ban: ";
 cin >> choice;
 switch (choice) {
 case '1':
 tim_kiem_sach(role);
 break;
 case '2':
 if (role == "admin") {
 them_sach();
 } else {
 cout << "Lua chon khong hop le. Vui long nhap lai.\n";
 }
 break;
 case '3':
 if (role == "admin") {
 tim_kiem_nguoi_dung();
 } else {
 cout << "Lua chon khong hop le. Vui long nhap lai.\n";
 }
 break;
 case '4':
 if (role == "admin") {
 them_nguoi_dung();
 } else {
 cout << "Lua chon khong hop le. Vui long nhap lai.\n";
 }
 break;
 case '6':
     if (role == "admin") {
 hien_thi_danh_sach_sach();;
 } else {
  hien_thi_danh_sach_sach();;
 }
 break;

 case 'y':
 if(is_logined == false){
 dang_nhap(is_logined, role);
}else{
cout << "Lua chon khong hop le. Vui long nhap lai.\n";
}
 break;
 case 'x':
 if(is_logined == true){
 dang_xuat(is_logined, role);
}else{
     cout << "Lua chon khong hop le. Vui long nhap lai.\n";
}
 break;
 case '0':
 cout << "Tam biet!\n";
 break;
 default:
 cout << "Lua chon khong hop le. Vui long nhap lai.\n";
 }
 } while (choice != '0');
 return 0;
}
