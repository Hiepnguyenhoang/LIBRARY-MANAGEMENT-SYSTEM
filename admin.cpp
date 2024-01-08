#include <iostream>
#include <conio.h>
#include"book.h"
#include"person.h"
#include"book.cpp"
#include"person.cpp"
#include"file.cpp"
#include <chrono>
#include <thread>

void Vekhung(){
    std::cout <<"\t\t\t\t\t================================================="<<"\n";
    std::cout <<"\t\t\t\t\t|\t\t  Library System   \t\t|" << std::endl;
    std::cout <<"\t\t\t\t\t================================================="<<"\n";
}

void Register(Staff& s, string &username, string &password) {
    int i = 0;
    for(i=0;i< sf.size();i++){ 
        if(sf[i].Getaccount() == username){
            cout << "\t\t\t\t\tTai khoan da ton tai " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return;
        }
    }
    system("cls");
    Vekhung();
    s.setAccount(username);
    s.setPassword(password);
    cout << "\t\t\t\t\t\t     Dang ki thanh cong!" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    s.set_info();
    sf.push_back(s);
    updateFile3(sf);
}

bool Login(const string username, string password){
    for(auto& staff : sf ){ 
        if(staff.Getaccount() == username && staff.Getpassword() == password){
            return true;
            break;
        }
    }
    cout << "\t\t\t\t\t\tTai khoan hoac mat khau sai" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return false;
}

void changePassword(Staff* &s, string username, string currentPassword, string newPassword) {
    if (s->Getpassword() == currentPassword) { 
        for(auto& staff : hs ){ 
            if(staff.Getaccount() == username ){
                staff.setPassword(newPassword);
            }
        }
        cout << "Doi mat khau thanh cong!" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        updateFile3(sf);
    } else {
        cout << "Sai mat khau hien tai! Khong the doi mat khau." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void displayMenu(char choice) {
    system("cls"); 
    Vekhung();
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

void displayMenuCustom(char choice)
{
	system("cls"); 
    Vekhung();
    std::cout << "\t\t\t\t\t|Ban dang nhap voi tu cach admin:\t\t|" <<std::endl;
    std::cout << "\t\t\t\t\t|\t\t\t\t\t\t|"<<"\n";
    std::cout << "\t\t\t\t\t|\t\t\t\t\t\t|"<<"\n";
    if (choice == '1') {
        std::cout << "\033[1;31m"; 
    }
    std::cout << "\t\t\t\t\t|\t1. Chinh sua thong tin       \t\t|" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '2') {
        std::cout << "\033[1;32m";
    }
    std::cout << "\t\t\t\t\t|\t2. Quan ly sach       \t\t\t|" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '3') {
        std::cout << "\033[1;33m"; 
    }
    std::cout << "\t\t\t\t\t|\t3. Thong ke      \t\t\t|" << std::endl;
    std::cout << "\033[0m";
    
    if (choice == '4') {
        std::cout << "\033[1;34m"; 
    }
    std::cout << "\t\t\t\t\t|\t4. Tim kiem sinh vien     \t\t|" << std::endl;
    std::cout << "\033[0m";
    
    if (choice == '5') {
        std::cout << "\033[1;35m"; 
    }
    std::cout << "\t\t\t\t\t|\t5. Dang xuat   \t\t\t\t|" << std::endl;
    std::cout << "\033[0m";
    std::cout << "\t\t\t\t\t|\t\t\t\t\t\t|"<<"\n";
    std::cout << "\t\t\t\t\t================================================="<<"\n";
}

void displayMenuCustom_2(char choice)
{
	system("cls"); 
    Vekhung();
    if (choice == '1') {
        std::cout << "\033[1;31m"; 
    }
    std::cout << "\t\t\t\t\t|\t1. Xem thong tin nguoi dung\t\t|" << std::endl;
    std::cout << "\033[0m"; 

    if (choice == '2') {
        std::cout << "\033[1;32m";
    }
    std::cout << "\t\t\t\t\t|\t2. Xoa tai khoan\t\t\t|" << std::endl;
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
	
	Staff myStaff;
    Staff *myStaffPtr = new Staff;
    string username, password, currentPassword, newPassword;
    docfile1(hs, sach);
    docfile2(sf);
    bool isLoggedIn = false; 
    bool isSearch = false; 

    char choice = '1';
    char keyPressed;

    while (true) 
	{
        displayMenu(choice);
       
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
                	case '1':
                		{   system("cls");
                            Vekhung();
                			std::string username, password;
	                        std::cout << "\t\t\t\t\tNhap ten dang nhap: ";
	                        std::cin >> username;
	                        std::cout << "\t\t\t\t\tNhap mat khau: ";
	                        std::cin >> password;
                            system("cls");
                            Vekhung();
	                        Register(myStaff, username, password); 
	                        break;
						}
                    case '2':
                        system("cls");
                        Vekhung();
                    	cout << "\t\t\t\t\tNhap ten dang nhap: ";
		                cin >> username;
		                cout << "\t\t\t\t\tNhap mat khau: ";
		                cin >> password;	
						
						if(Login(username,password))
						{
		                    isLoggedIn = true;
		
		                    for (auto& staff : sf) {
		                        if (staff.Getaccount() == username && staff.Getpassword() == password) 
								{
			                        myStaffPtr = &staff;
			                        break;
		                        }
	                    }	
						
						while (isLoggedIn)
						{
							displayMenuCustom(choice);
						    
					        keyPressed = _getch();
					        switch (keyPressed) 
							{
					            case 72: 
					                choice = (choice == '1') ? '5' : static_cast<char>(choice - 1);
					                break;
					            case 80:
					                choice = (choice == '5') ? '1' : static_cast<char>(choice + 1);
					                break;
					            case 13: 
					            	switch(choice)
					            	{
					            		case '1':
                                            system("cls");
                                            Vekhung();
					            			myStaffPtr -> print_info(sach);
				                            myStaffPtr -> editInfor();
                                            updateFile3(sf);
				                            break;
				                        case '2':
                                            system("cls");
                                            Vekhung();
				                            myStaffPtr->bookManager(sach);
				                            updateFile2(sach);
				                            break;
				                        case '3':
                                            system("cls");
                                            Vekhung();
				                            myStaffPtr->Statistical(sach, hs);
				                            break;
				                        case '4':
                                            system("cls");
                                            Vekhung();
				                            if(myStaff.searchUser(hs))
											{
                                                std::this_thread::sleep_for(std::chrono::seconds(5));
				                                isSearch = true;
				                                while(isSearch)
												{
				                                    displayMenuCustom_2(choice);
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
						                                    switch (choice)
						                                    {
							                                    case '1':
							                                        myStaffPtr -> print_infoUser(hs, sach); 
							                                    	break;
							                                    case '2':
							                                        myStaffPtr -> deleteUser(hs, sach); 
							                                        updateFile1(hs);
							                                    	break;
							                                    case '3': 
							                                        isSearch = false;
                                                                    break;     
															}
													}
												}
				                            }
                                            break;
				                        case '5':
					                        isLoggedIn = false;
                                            break;
				                        default :
                                            cout << "Lua chon khong hop le" << endl;
                                            std::this_thread::sleep_for(std::chrono::seconds(2));
					                        break;
                                    }
                                        
				                        }
				                        
									}
								}
								break; 
					            case '3':
					                return 0; 
                                    default:
                                    break;     
							}
						}
				}
		delete myStaffPtr;
		return 0;
	}