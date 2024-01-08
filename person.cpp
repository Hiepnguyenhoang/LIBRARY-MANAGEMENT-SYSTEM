#include"person.h"
#include"book.h"
#include <chrono>
#include <thread>

string Person::Getfull_name(){
    return full_name;
}

string Person::Getcccd(){
    return cccd;
}

string Person::Getphone_number (){
    return phone_number ;
}

string Person::Getdate_of_birth(){
    return date_of_birth;
}

string Person:: Getemail(){
    return email;
}

string Person:: Getaccount(){
    return account;
}      

string Person:: Getpassword(){
    return password;
}  

string Person:: GetBorrow(){
    return borrow;
}

int Person:: GetID(){
    return id;
}

void Vekhung1(){
    std::cout <<"\t\t\t\t\t================================================="<<"\n";
    std::cout <<"\t\t\t\t\t|\t\t  Library System   \t\t|" << std::endl;
    std::cout <<"\t\t\t\t\t================================================="<<"\n";
}

void displayThemxoa(char choice)
{
	system("cls"); 
    Vekhung1();
    if (choice == '1') {
        std::cout << "\033[1;31m"; 
    }
    std::cout << "\t\t\t\t\t|\t1. Them sach\t\t\t\t|" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '2') {
        std::cout << "\033[1;32m";
    }
    std::cout << "\t\t\t\t\t|\t2. Xoa sach\t\t\t\t|" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '3') {
        std::cout << "\033[1;34m"; 
    }
    std::cout << "\t\t\t\t\t|\t3. Quay lai trang chu\t\t\t|" << std::endl;
    std::cout << "\033[0m";
    std::cout << "\t\t\t\t\t|\t\t\t\t\t\t|"<<"\n";
    std::cout << "\t\t\t\t\t================================================="<<"\n";

}

void Person::setFullname(string& name) {
    full_name = name;
}

void Person:: setCCCD(string& cccdNumber) {
    cccd = cccdNumber;
}

void Person:: setDateOfBirth(string& dob) {
    date_of_birth = dob;
}

void Person:: setPhoneNumber(string& phone) {
    phone_number = phone;
}

void Person:: setEmail(string& emailAddress) {
    email = emailAddress;
}

void Person:: setAccount(string& acc) {
    account = acc;
}

void Person:: setPassword(string& pass) {
    password = pass;
}

void Person:: setID(int &ID){
    id = ID;
}

void Person:: setBorrow(string& Borrow){
    borrow = Borrow;
}

void Person:: borrowBook(vector<book>& listbook){
    int choice;
    bool found = false;
    string idStr;
    cout << "\t\t\t\t\tNhap vao ID sach ban muon muon: ";
    cin >> idStr;
    int id = stoi(idStr);
    vector<int> ID;
    int temp = 0;

    for (char c : borrow) {
        if (isdigit(c)){ // Nếu là số, cộng vào biến tạm
            temp = temp * 10 + (c - '0');
        }
        else if (c == ';') {
            ID.push_back(temp);
            temp = 0;
        }
    }

    if(ID.size() >= 5){
        cout << "\t\t\t\t\tBan dang muon 5 cuon, khong the muon them " << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return;
    }

    for(auto& b: listbook){
        if(b.getID() == id){
            found = true;
            for(auto& a: ID){
                if(a == id){
                    cout << "\t\t\t\t\tBan da muon sach " << b.getName() << " cua tac gia " << b.getAuthor() << endl;
                    cout << "\t\t\t\t\tBan co muon muon them! (Nhan 1 de xac nhan, 0 de huy) " << endl;
                    cin >> choice;
                    if(choice == 1){
                        borrow = borrow + idStr + ";";
                        cout << "\t\t\t\t\tMuon sach thanh cong!" << endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        int newNumber = b.getNumber() - 1;
                        b.setNumber(newNumber);
                        return;
                    }
                    if(choice == 0){
                        cout << "\t\t\t\t\tHuy thanh cong! " << endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        return;
                    }
                }
            }
            if(b.getNumber() > 0){
                cout << "\t\t\t\t\tBan dang muon sach: " << b.getName() << " cua tac gia " << b.getAuthor() << endl;
                cout << "\t\t\t\t\tNhan 1 de xac nhan, 0 de huy" << endl;
                cin >> choice;
                if(choice == 1){
                    borrow = borrow + idStr + ";";
                    cout << "\t\t\t\t\tMuon sach thanh cong!" << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    int newNumber = b.getNumber() - 1;
                    b.setNumber(newNumber);
                }
                if(choice == 0){
                    cout << "\t\t\t\t\tHuy thanh cong! " << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    break;
                }
            }else{
                cout << "\t\t\t\t\tSo luong sach khong du!" << endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
        }
    }
    if(!found){
        cout << "\t\t\t\t\tSo ID khong hop le hoac khong tim duoc sach co ID tren! "  << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    
}

bool Person:: searchBook(vector<book>& listbook){
    string idStr;
    string name,author,type;
    vector<book> listbookfound;
    set<string> listauthorfound;
    set<string> listtypefound;
    int choice;
    cout << "\n" << endl;
    cout << "1. Tim kiem theo ten sach" << endl;
    cout << "2. Tim kiem theo tac gia " << endl;
    cout << "3. Tim kiem theo the loai" << endl;
    cout << "Nhap vao lua chon cua ban: ";
    cin >> choice;

    bool found = false;
    switch (choice){
        case 1:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap ten sach muon tim: ";
            cin.ignore();
            getline(cin, name);
            for(book& b : listbook){
                if (b.getName().find(name) != string::npos) { // Nhập thành phần cũng có thể truy suất qua sách
                    if(!found){
                        cout << "\t\t\t\t\tCac ten sach ban muon tim: " << endl;
                        found = true;
                    }
                    listbookfound.push_back(b);
                }
            }
            if(found){
                cout << left << setw(8) << "ID"<< setw(41) << "Ten" << setw(24) << "The loai" << setw(25) << "Tac gia" << setw(25) << "So luong" << endl;
                cout << setfill('-') << setw(112) << "-" << setfill(' ') << endl;

                for (book& b : listbookfound) {
                    b.display();
                }
                cout << endl;
            }
            
            break;

        case 2:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap ten tac gia muon tim: ";
            cin.ignore();
            getline(cin, author);
            for(book& b : listbook){
                if (b.getAuthor().find(author) != string::npos) { // Nhập thành phần cũng có thể truy suất qua sách
                    if(!found){
                        cout << "\t\t\t\t\tCac tac pham cua tac gia ban muon tim: " << endl;
                        found = true;
                    }
                    listauthorfound.insert(b.getAuthor());
                }
            }
            if(found){
                cout << left << setw(8) << "ID"<< setw(41) << "Ten" << setw(24) << "The loai" << setw(25) << "Tac gia" << setw(25) << "So luong" << endl;
                cout << setfill('-') << setw(112) << "-" << setfill(' ') << endl;
            
                for (auto& a: listauthorfound){
                    for (book& b : listbook) {
                        if(b.getAuthor() == a){
                            b.display();
                        }
                    }
                }  
                cout << endl;
            }
            
            break;
                    
        case 3:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap ten the loai muon tim: ";
            cin.ignore();
            getline(cin, type);
            for(book& b : listbook){ // Kiểu như list b trỏ heap
                if (b.getType().find(type) != string::npos) { // Nhập thành phần cũng có thể truy suất qua sách
                    if(!found){
                        found = true;
                    }
                    listtypefound.insert(b.getType());
                }
            }

            if(found){
                cout << left << setw(8) << "ID"<< setw(41) << "Ten" << setw(24) << "The loai" << setw(25) << "Tac gia" << setw(25) << "So luong" << endl;
                cout << setfill('-') << setw(112) << "-" << setfill(' ') << endl;
            
                for (auto& a: listtypefound){
                    for (book& b : listbook) {
                        if(b.getType() == a){
                            b.display();
                        }
                    }
                }  
                cout << endl;
            }
        
            break;

        default:
            cout << "\t\t\t\t\tLua chon khong hop le!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return false;
    }
    if (!found) {
        cout << "\t\t\t\t\tKhong tim thay ket qua ban muon tim! " << endl << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return false;
    }else{
        return true;
    }
}

void Person:: returnBook(vector<book>& listbook){
    bool found = false;
    int idBookReturn;
    vector<int> ID;

    if (borrow.empty()) {
        cout << "\t\t\t\t\tBan dang khong muon sach nao! " << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return;
    }

    cout << "\t\t\t\t\tNhap vao ID sach muon tra: ";
    cin >> idBookReturn;
    string result;
    int temp = 0;

    int i = 0; // Biến để theo dõi vị trí trong chuỗi

    while (i < borrow.size()) {
        if (isdigit(borrow[i])) {
            temp = temp * 10 + (borrow[i] - '0');
            i++;
        }
        else if (borrow[i] == ';') {
            if (temp != idBookReturn) {
                ID.push_back(temp);
                result += to_string(temp) + ";";
            }
            if (temp == idBookReturn) {
                ID.push_back(temp);
            }
            temp = 0; // Đặt lại biến tạm và chuyển sang ký tự tiếp theo
            i++;
        }
        else {
            result += borrow[i];
            i++;
        }
    }

    for(int i = 0; i < ID.size(); i++){
        if(idBookReturn == ID[i]){
            found = true;
            for(auto& b: listbook){
                if(b.getID() == idBookReturn){
                    int newNumber = b.getNumber() + 1;
                    b.setNumber(newNumber);   
                }
            }
        }
    }

    setBorrow(result);
    if(found){
        cout << "\t\t\t\t\tTra sach thanh cong !" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }else{
        cout << "\t\t\t\t\tID sach tra khong dung hoac khong co trong danh sach muon!" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void Person:: set_info(){
    cout << "\n";
    cout << "\t\t\t\t\tNhap thong tin nguoi dung: " << endl;
    cin.ignore();
    cout << "\t\t\t\t\tHo va ten: ";
    getline(cin,full_name);
    cout << "\t\t\t\t\tSo dien thoai: ";
    getline(cin,phone_number );
    cout << "\t\t\t\t\tSo can cuoc cong dan: ";
    getline(cin,cccd);
    cout << "\t\t\t\t\tNgay thang nam sinh: ";
    getline(cin,date_of_birth);
    cout << "\t\t\t\t\tEmail: ";
    getline(cin,email);
}

void Person:: print_info(vector<book> listbook){ // Hiển thị thông tin người dùng
    cout << "\t\t\t\t\tHo va ten: " << full_name << endl;
    cout << "\t\t\t\t\tCan cuoc cong dan: " << cccd << endl;
    cout << "\t\t\t\t\tNgay thang nam sinh: " << date_of_birth << endl;
    cout << "\t\t\t\t\tSo dien thoai: " << phone_number  << endl;
    cout << "\t\t\t\t\tEmail: " << email << endl;
    cout << "\t\t\t\t\tTen tai khoan: " << account << endl;
    cout << "\t\t\t\t\tMat khau: ";
    for(int i=0;i< password.length();i++){
        cout << "*";
    }
    cout << endl;
}

// Student

string Student:: getStudent_id(){
    return student_id;
}

string Student:: getClass_name(){
    return class_name;
}

int Student:: getCohort(){
    return cohort;
}

string Student:: getSchool(){
    return school;
}

string Student:: getDepartment(){
    return department;
}

void Student:: setStudentID(const string& id) {
    student_id = id;
}

void Student:: setClassName(const string& className) {
    class_name = className;
}

void Student:: setCohort(int cohortValue) {
    cohort = cohortValue;
}

void Student:: setSchool(const string& schoolName) {
    school = schoolName;
}

void Student:: setDepartment(const string& departmentName) {
    department = departmentName;
}

void Student:: set_info(){
    Person::set_info();
    cout << "\t\t\t\t\tMSSV: ";
    getline(cin,student_id);
    cout << "\t\t\t\t\tLop: ";
    getline(cin,class_name);
    while (true) {
        cout << "\t\t\t\t\tKhoa: ";
        if (cin >> cohort) {
            // Nếu là số nguyên, thoát khỏi vòng lặp
            break;
        } else {
            cin.clear(); // Xóa đầu lỗi khi nhập str vào int
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Xóa bỏ dữ liệu nhập đầu vào lỗi
            cout << "\t\t\t\t\tKhoa nhap khong hop le. Vui long nhap mot so nguyen." << endl;
        }
    }
    cin.ignore();
    cout << "\t\t\t\t\tTruong: ";
    getline(cin,school);
    cout << "\t\t\t\t\tKhoa: ";
    getline(cin,department);
}

void Student:: editInformation() {
    cout << "\t\t\t\t\tChinh sua thong tin ca nhan:" << endl;
    cout << "\t\t\t\t\t1. Sua ten" << endl;
    cout << "\t\t\t\t\t2. Sua so dien thoai" << endl;
    cout << "\t\t\t\t\t3. Sua ngay sinh" << endl;
    cout << "\t\t\t\t\t4. Sua CCCD" << endl;
    cout << "\t\t\t\t\t5. Sua Email" << endl;
    cout << "\t\t\t\t\t6. Sua MSSV" << endl;
    cout << "\t\t\t\t\t7. Sua ten lop hoc" << endl;
    cout << "\t\t\t\t\t8. Sua khoa hoc" << endl;
    cout << "\t\t\t\t\t9. Sua truonng hoc" << endl;
    cout << "\t\t\t\t\t10. Sua khoa" << endl;
    cout << "\t\t\t\t\tNhap lua chon cua ban: ";
    int choice;
    cin >> choice;
    cin.ignore(); // Để xóa bộ đệm sau khi nhập lựa chọn số

    switch (choice) {
        case 1:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap ten moi: ";
            getline(cin, full_name);
            cout << "\t\t\t\t\tTen da duoc cap nhat!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 2:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap so dien thoai moi: ";
            getline(cin, phone_number );
            cout << "\t\t\t\t\tSo dien thoai da duoc cap nhat!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 3:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap ngay sinh moi: ";
            getline(cin, date_of_birth);
            cout << "\t\t\t\t\tNgay sinh da duoc cap nhat!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 4:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap CCCD moi: ";
            getline(cin,cccd);
            cout << "\t\t\t\t\tCCCD da duoc cap nhat!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 5:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap vao email moi: ";
            getline(cin,email);
            cout << "\t\t\t\t\tEmail da duoc cap nhat! " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 6:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap vao MSSV moi: ";
            getline(cin,student_id);
            cout << "\t\t\t\t\tMSSV da duoc cap nhat! " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 7:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap vao lop hoc moi: ";
            getline(cin,class_name);
            cout << "\t\t\t\t\tLop hoc da duoc cap nhat! " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 8:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap vao khoa moi: ";
            cin >> cohort;
            cout << "\t\t\t\t\tKhoa da duoc cap nhat! " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 9:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap vao truong hoc moi: ";
            getline(cin,school);
            cout << "\t\t\t\t\tTruong hoc da duoc cap nhat! " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 10:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap vao khoa moi: ";
            getline(cin,department);
            cout << "\t\t\t\t\tKhoa hoc da duoc cap nhat! " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        default:
            cout << "\t\t\t\t\tLua chon khong hop le" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
    }
}

void Student:: print_info(vector<book> listbook) { 
    Person::print_info(listbook); // Call the base class print_info first
    cout << "\t\t\t\t\tMSSV: " << student_id << endl;
    cout << "\t\t\t\t\tLop: " << class_name << endl;
    cout << "\t\t\t\t\tKhoa: " << cohort << endl;
    cout << "\t\t\t\t\tTruonng: " << school << endl;
    cout << "\t\t\t\t\tKhoa: " << department << endl;
    vector<int> ID;
    int temp = 0;
    for (char c : borrow) {
        if (std::isdigit(c)){ // Nếu là số, cộng vào biến tạm
            temp = temp * 10 + (c - '0');
        }
        else if (c == ';') {
            ID.push_back(temp);
            temp = 0;
        }
    }
    cout << "\t\t\t\t\tSo sach dang muon: " << ID.size() << endl;
    if(ID.size() > 0){
        cout << "\t\t\t\t\tDanh sach cac sach dang muon: " << endl;
        cout << left << setw(8) << "ID"<< setw(40) << "Ten" << setw(24) << "The loai" << setw(25) << "Tac gia" << setw(25) << "So luong" << endl;
        cout << setfill('-') << setw(112) << "-" << setfill(' ') << endl;
        for(auto& i: ID){
            for(auto& b: listbook){
                if(b.getID() == i){
                    b.display();
                }
            }
        }
    }
}

void Student:: display(){
    cout << left << setw(8) << id << setw(35) << account << setw(15) << password << setw(15) << full_name << endl;
}

string Staff:: getStaffID() {
    return staff_id;
}

string Staff:: getSchool() {
    return school;
}

string Staff:: getDepartment() {
    return department;
}

string Staff:: getOffice() {
    return office;
}

void Staff:: setStaffID(const string& id) {
    staff_id = id;
}

void Staff:: setSchool(const string& schoolName) {
    school = schoolName;
}

void Staff:: setDepartment(const string& departmentName) {
    department = departmentName;
}

void Staff:: setOffice(const string& officeLocation) {
    office = officeLocation;
}

void Staff:: set_info(){
    Person::set_info();
    cout << "\t\t\t\t\tMa giang vien: ";
    getline(cin,staff_id);
    cout << "\t\t\t\t\tTruong: ";
    getline(cin,school);
    cout << "\t\t\t\t\tKhoa: ";
    getline(cin,department);
    cout << "\t\t\t\t\tPhong lam viec: ";
    getline(cin,office);
}

void Staff:: print_info(vector<book> listbook) {
    Person::print_info(listbook);
    cout << "\t\t\t\t\tMa so giang vien: " << staff_id << endl;
    cout << "\t\t\t\t\tTruong: " << school << endl;
    cout << "\t\t\t\t\tKhoa: " << department << endl;
    cout << "\t\t\t\t\tPhong lam viec: " << office << endl;
    cout << "\n" << endl;
}

void Staff:: bookManager(vector<book>& listbook){
    bool found = false;
    book Newbook;
    int id;
    char choice = '1';
    char keyPressed;
    while(true){
    displayThemxoa(choice);
    keyPressed = _getwch(); 
    switch (keyPressed) 
    {
        case 72: 
                choice = (choice == '1') ? '3' : static_cast<char>(choice - 1);
                break;
            case 80:
                choice = (choice == '3') ? '1' : static_cast<char>(choice + 1);
                break;
            case 13:
                switch(choice)
       {        
        case '1':
            Newbook.addBook();
            id = listbook.back().getID() + 1;
            Newbook.setID(id);
            listbook.push_back(Newbook);
            cout << "\t\t\t\t\tThem sach thanh cong! " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        return;
        case '2':
            system("cls");
            Vekhung1();
            cout <<"\n";
            cout << "\t\t\t\t\tCac sach hien co la: " << endl; // Phần này học sau
            cout << "\n" << endl;
            cout <<  left << setw(8) << "ID"<< setw(41) << "Ten" << setw(24) << "The loai" << setw(25) << "Tac gia" << setw(25) << "So luong sach" << endl;
            cout <<  setfill('-') << setw(112) << "-" << setfill(' ') << endl;

            for (book& b : listbook) {
                b.display();
            }
            cout <<"\n";
            cout << "\t\t\t\t\tNhap id sach muon xoa: ";
            cin >> id;
            for(auto& b: listbook){
                if(b.getID() == id){
                    listbook.erase(listbook.begin() + id - 1);
                    found = true;
                }
            }
            if(found){
                cout << "\t\t\t\t\tXoa sach thanh cong! " << endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                return;
            }else{
            
                cout << "\t\t\t\t\tId sach khong ton tai! " << endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                return;
            }
            
        case '3':
            return;
        default:
            cout << "\t\t\t\t\tLua chon khong hop le!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
        }
    }
}
}

void Staff:: Statistical(vector<book> listbook, vector<Student> listUser){
    cout <<"\t\t\t\t\tSo sach: " << listbook.size() << endl;
    cout <<"\t\t\t\t\tSo nguoi dung: " << listUser.size() << endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

bool Staff:: searchUser(vector<Student>& listUser){
    string name;
    bool found = false;
    set<string> listnamefound;
    cout << "\t\t\t\t\tNhap vao ten nguoi muon tim: ";
    cin.ignore();
    getline(cin,name);
    for(auto& a : listUser){
        if (a.Getfull_name().find(name) != string::npos) { // Nhập thành phần cũng có thể truy suất qua sách
            if(!found){
                system("cls");
                Vekhung1();
                cout << "\t\t\t\t\tCac ten nguoi ban muon tim: " << endl;
                cout << "\n" << endl;
                found = true;
            }
            listnamefound.insert(a.Getfull_name());
        }
    }

    if (found) {
        cout << left << setw(8) << "ID"<< setw(32) << "Tai khoan" << setw(18) << "Mat khau" << setw(25) << "Ho va Ten" << endl;
        cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
            
        for (auto& b: listnamefound){
            for (auto& a : listUser) {
                if(a.Getfull_name() == b){
                    a.display();
                }
            }
        }
        return true;
    }else{
        cout << "\t\t\t\t\tKhong tim thay ket qua ban muon tim" << endl << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return false;
    }
}

void Staff:: print_infoUser(vector<Student>& listUser, vector<book>& listbook){
    int id;
    system("cls");
    Vekhung1();
    cout << "\t\t\t\t\tNhap vao ID nguoi dung ban muon xem chi tiet: ";
    cin >> id;
    bool found = false;
    for (auto& a: listUser) {
        if(a.GetID() == id){
            a.print_info(listbook);
            std::this_thread::sleep_for(std::chrono::seconds(3));
            found = true;
        }
    }
    
    if(!found){
        
        cout << "\t\t\t\t\tID nguoi dung khong hop le hoac khong ton tai nguoi dung !" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void Staff:: deleteUser(vector<Student>& listUser, vector<book>& listbook){
    int id;
    system("cls");
    Vekhung1();
    cout << "\t\t\t\t\tNhap vao ID nguoi dung muon xoa: ";
    cin >> id;
    bool found = false;
    for (auto& a: listUser) {
        if(a.GetID() == id){
            found = true;
        }
    }
    if(!found){
        cout << "\t\t\t\t\tID nguoi dung khong hop le hoac khong tim duoc nguoi dung co ID nhu tren!" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }else{
        listUser.erase(listUser.begin() + id - 1);
        cout << "\t\t\t\t\tXoa nguoi dung thanh cong! " << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void Staff:: editInfor() {
    cout << "\t\t\t\t\tChinh sua thong tin ca nhan:" << endl;
    cout << "\t\t\t\t\t1. Sua ten" << endl;
    cout << "\t\t\t\t\t2. Sua so dien thoai" << endl;
    cout << "\t\t\t\t\t3. Sua ngay sinh" << endl;
    cout << "\t\t\t\t\t4. Sua CCCD" << endl;
    cout << "\t\t\t\t\t5. Sua Email" << endl;
    cout << "\t\t\t\t\t6. Sua ma so giang vien" << endl;
    cout << "\t\t\t\t\t7. Sua truong" << endl;
    cout << "\t\t\t\t\t8. Sua khoa" << endl;
    cout << "\t\t\t\t\t9. Sua phong lam viec" << endl;
    cout << "\t\t\t\t\tNhap lua chon cua ban: ";
    int choice;
    cin >> choice;
    cin.ignore(); // Để xóa bộ đệm sau khi nhập lựa chọn số
    
    switch (choice) {
        case 1:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap ten moi: ";
            getline(cin, full_name);
            cout << "\t\t\t\t\tTen da duoc cap nhat!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 2:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap so dien thoai moi: ";
            getline(cin, phone_number );
            cout << "\t\t\t\t\tSo dien thoai duoc cap nhat!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 3:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap ngay sinh moi: ";
            getline(cin, date_of_birth);
            cout << "\t\t\t\t\tNgay sinh da duoc cap nhat!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 4:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap vao CCCD moi: ";
            getline(cin,cccd);
            cout << "\t\t\t\t\tCCCD da duoc cap nhat!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 5:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap vao email moi: ";
            getline(cin,email);
            cout << "\t\t\t\t\tEmail da duoc cap nhat! " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 6:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap vao ma so giang vien moi: ";
            getline(cin,staff_id);
            cout << "\t\t\t\t\tMa so giang vien da duoc cap nhat! " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 7:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap vao truong moi: ";
            getline(cin,school);
            cout << "\t\t\t\t\tTruong da duoc cap nhat! " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 8:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap vao khoa moi: ";
            getline(cin,department);
            cout << "\t\t\t\t\tKhoa da duoc cap nhat! " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        case 9:
            system("cls");
            Vekhung1();
            cout << "\t\t\t\t\tNhap vao phong lam viec moi: ";
            getline(cin,office);
            cout << "\t\t\t\t\tPhong lam viec da duoc cap nhat! " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
        default:
            cout << "\t\t\t\t\tLua chon khong hop le!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
    }
}