#include"book.h"
#include"person.h"
#include"book.cpp"
#include"person.cpp"
#include"file.cpp"
#include<conio.h>
#include <chrono>
#include <thread>

void Vekhung3(){
    std::cout <<"\t\t\t\t\t================================================="<<"\n";
    std::cout <<"\t\t\t\t\t|\t\t  Library System   \t\t|" << std::endl;
    std::cout <<"\t\t\t\t\t================================================="<<"\n";
}
void Register(Student& st, string &username, string &password) {
    int i = 0;
    for(i=0;i<size(hs);i++){  // Kiểm tra tài khoản đã tồn tại hay chưa
        if(hs[i].Getaccount() == username){
            cout << "\t\t\t\t\tTai khoan da ton tai! " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            return;
        }
    }
    system("cls");
    Vekhung3();
    st.setAccount(username);
    st.setPassword(password);
    cout << "\t\t\t\t\t\t     Dang ki thanh cong!" << endl;
    int newId = hs.back().GetID() + 1;
    st.setID(newId);
    st.set_info();
    hs.push_back(st);
    updateFile1(hs);
}

bool Login(const string username, string password){
    for(auto& student : hs ){  // Kiểm tra tài khoản, mật khẩu 
        if(student.Getaccount() == username && student.Getpassword() == password){
            return true;
            break;
        }
    }
    cout << "\t\t\t\t\tTai khoan hoac mat khau sai" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return false;
}

void changePassword(Student* &st, string username, string currentPassword, string newPassword) { // Đổi mật khẩu
    if (st->Getpassword() == currentPassword) { // Kiểm tra tài khoản, mật khẩu 
        for(auto& student : hs ){  // Cập nhật trong vector
            if(student.Getaccount() == username ){
                student.setPassword(newPassword);
            }
        }
        cout << "\t\t\t\t\tDoi mat khau thanh cong!" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        updateFile1(hs);
    } else {
        cout << "\t\t\t\t\tSai mat khau hien tai! Khong the doi mat khau." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}

void displayMenu1(char choice) {
    system("cls"); 
    Vekhung3();
    std::cout << "\t\t\t\t\t|\t\t\t\t\t\t|"<<"\n";
    std::cout << "\t\t\t\t\t|\t\t\t\t\t\t|"<<"\n";
    if (choice == '1') {
        std::cout << "\033[1;31m"; 
    }
    std::cout << "\t\t\t\t\t|\t\t1. Dang ky tai khoan\t\t|" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '2') {
        std::cout << "\033[1;32m";
    }
    std::cout << "\t\t\t\t\t|\t\t2. Dang nhap\t\t        |" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '3') {
        std::cout << "\033[1;34m"; 
    }
    std::cout << "\t\t\t\t\t|\t\t3. Thoat\t\t        |" << std::endl;
    std::cout << "\033[0m";
    std::cout << "\t\t\t\t\t|\t\t\t\t\t\t|"<<"\n";
    std::cout << "\t\t\t\t\t|\t\t\t\t\t\t|"<<"\n";
    std::cout << "\t\t\t\t\t================================================="<<"\n";

}

void displayMenuCustom1(char choice)
{
	system("cls"); 
    Vekhung3();
    std::cout << "\t\t\t\t\t|\t\t\t\t\t\t|"<<"\n";
    if (choice == '1') {
        std::cout << "\033[1;31m"; 
    }
    std::cout << "\t\t\t\t\t|\t1. Tra cuu sach     \t\t\t|" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '2') {
        std::cout << "\033[1;32m";
    }
    std::cout << "\t\t\t\t\t|\t2. Thong tin nguoi dung      \t\t|" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '3') {
        std::cout << "\033[1;33m"; 
    }
    std::cout << "\t\t\t\t\t|\t3. Doi mat khau      \t\t\t|" << std::endl;
    std::cout << "\033[0m";
    
    if (choice == '4') {
        std::cout << "\033[1;34m"; 
    }
    std::cout << "\t\t\t\t\t|\t4. Dang xuat      \t\t\t|" << std::endl;
    std::cout << "\033[0m";
    std::cout << "\t\t\t\t\t|\t\t\t\t\t\t|"<<"\n";
    std::cout << "\t\t\t\t\t================================================="<<"\n";
}

void displayEdit(char choice)
{
	system("cls"); 
    Vekhung3();
    if (choice == '1') {
        std::cout << "\033[1;31m"; 
    }
    std::cout << "\t\t\t\t\t|\t1. Chinh sua thong tin\t\t\t|" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '2') {
        std::cout << "\033[1;32m";
    }
    std::cout << "\t\t\t\t\t|\t2. Tra sach\t\t\t\t|" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '3') {
        std::cout << "\033[1;34m"; 
    }
    std::cout << "\t\t\t\t\t|\t3. Quay lai trang chu\t\t\t|" << std::endl;
    std::cout << "\033[0m";
    std::cout << "\t\t\t\t\t|\t\t\t\t\t\t|"<<"\n";
    std::cout << "\t\t\t\t\t================================================="<<"\n";

}

int main()
{
    
    string username, password, currentPassword, newPassword;
    Student myStudent;
    Student* myStudentPtr = new Student;
    docfile1(hs, sach);
    docfile2(sf);
    bool isLoggedIn = false; // Biến xác định đang trong đăng nhập 
    bool isEdit = false; // Biến xác định đang trong quá trình chỉnh sửa
    
    char choice = '1';
    char keyPressed;

    while (true) 
    {
        displayMenu1(choice);
        keyPressed = _getch(); 
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
            case '1':{
                system("cls");
                Vekhung3();
                std::string username, password;
                std::cout << "\t\t\t\t\tNhap ten dang nhap: ";
                std::cin >> username;
                std::cout << "\t\t\t\t\tNhap mat khau: ";
                std::cin >> password;
                system("cls");
                Vekhung3();
                Register(myStudent, username, password);
                break;
                }
            case '2':
                system("cls");
                Vekhung3();
                cout << "\t\t\t\t\tNhap ten dang nhap: ";
                cin >> username;
                cout << "\t\t\t\t\tNhap mat khau: ";
                cin >> password;

                if (Login(username, password)) 
                    {
                    isLoggedIn = true;
                    for (auto& student : hs) { // Xác định đối tượng đang sử dụng
                        if (student.Getaccount() == username && student.Getpassword() == password) 
                        {
                        myStudentPtr = &student;
                        break;
                        }
                    }
                

                    while(isLoggedIn)
                    {
							displayMenuCustom1(choice);
						    
					        keyPressed = _getch();
					        switch (keyPressed) 
							{
					            case 72: 
					                choice = (choice == '1') ? '4' : static_cast<char>(choice - 1);
					                break;
					            case 80:
					                choice = (choice == '4') ? '1' : static_cast<char>(choice + 1);
					                break;
                                case 13: 
                                    switch (choice)
                                    {
                                           case '1':
                                                  system("cls");
                                                  Vekhung3();
                                                  cout << "Cac sach hien co : " << endl; // Phần này học sau
                                                  cout << left << setw(8) << "ID"<< setw(41) << "Ten" << setw(24) << "The loai" << setw(25) << "Tac gia" << setw(25) << "So luong" << endl;
                                                  cout << setfill('-') << setw(112) << "-" << setfill(' ') << endl;

                                                  for (book& b : sach) {
                                                  b.display();
                                                  }
                                                  if(myStudentPtr->searchBook(sach)){
                                                  myStudentPtr->borrowBook(sach);
                                                  updateFile1(hs);
                                                  updateFile2(sach); 
                                                    }else{
                                                 break;
                                                    }            
                                                 break;

                                            case '2':
                                                 system("cls");
                                                 Vekhung3();
                                                 cout << "\t\t\t\t\tThong tin hien tai nguoi dung: \n";
                                                 myStudentPtr->print_info(sach);
                                                 std::this_thread::sleep_for(std::chrono::seconds(5));
                                                 isEdit = true;
                                                 while(isEdit){
                                                 displayEdit(choice);
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
                                                 myStudentPtr->editInformation();
                                                 updateFile1(hs);
                                                 updateFile2(sach);
                                                 break;
                                                 case '2':
                                                 myStudentPtr->returnBook(sach);
                                                 updateFile1(hs);
                                                 updateFile2(sach);
                                                 case '3':
                                                 isEdit = false;
                                                 break;
                                                default:
                                                cout << "\t\t\t\t\tLua chon khong hop le!" << endl;
                                                std::this_thread::sleep_for(std::chrono::seconds(3));
                                                break;
                                               }
                                            }
                                                 }
                                             break;
                        case '3': 
                            system("cls");
                            Vekhung3();
                            cout << "\t\t\t\t\tNhap mat khau hien tai: ";
                            cin >> currentPassword;
                            cout << "\t\t\t\t\tNhap mat khau moi: ";
                            cin >> newPassword;
                            changePassword(myStudentPtr, username, currentPassword, newPassword);
                            break;

                        case '4': 
                            isLoggedIn = false;
                            break;
                        default:
                            cout << "\t\t\t\t\tLua chon khong hop le!\n";
                            std::this_thread::sleep_for(std::chrono::seconds(5));
                            break;
                            }
                    
                        }
                    }
            break; 
            case '3':
                return 0;
                
            }
        }
    }
    }
    delete myStudentPtr;
    return 0;
}    
        