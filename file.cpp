#include<iostream>
#include<string>
#include<vector>
#include"book.h"
#include"person.h"
#include<fstream>

using namespace std;

vector<Student> hs;
vector<Staff> sf;
vector<book> sach;

void docfile1(vector<Student> &hs,vector<book> &sach){
    ifstream ip("data.csv");
    string id1Str, username, password, hoten, cccd, date, email, phonenumber, id2, class_name, cohortStr, school, department, borrow;
    
    if (!ip.is_open()) {
        cout << "Khong the mo file." << endl;
        return;
    }

    while (ip.peek()!=EOF)
    {
        getline(ip >> std::ws, id1Str, ',');
        getline(ip >> std::ws, username, ','); // Loại bỏ khoảng trắng khi đọc
        getline(ip >> std::ws, password, ',');
        getline(ip >> std::ws, hoten, ',');
        getline(ip >> std::ws, cccd, ',');
        getline(ip >> std::ws, date, ',');
        getline(ip >> std::ws, email, ',');
        getline(ip >> std::ws, phonenumber, ',');
        getline(ip >> std::ws, id2, ',');
        getline(ip >> std::ws, class_name, ',');
        getline(ip >> std::ws, cohortStr, ',');
        getline(ip >> std::ws, school, ',');
        getline(ip >> std::ws, department, ',');
        getline(ip, borrow, '\n');

        int id1 = stoi(id1Str);
        int cohort = stoi(cohortStr); // Chuyển string sang int

	    Student st; 
        st.setID(id1);
        st.setAccount(username);
        st.setPassword(password);
        st.setFullname(hoten);
        st.setCCCD(cccd);
        st.setDateOfBirth(date);
        st.setEmail(email);
        st.setPhoneNumber(phonenumber);
        st.setStudentID(id2);
        st.setClassName(class_name);
        st.setCohort(cohort);
        st.setSchool(school);
        st.setDepartment(department);
        if (!borrow.empty()) {
            st.setBorrow(borrow);
        }
        hs.push_back(st);
    }
    ip.close();

    ifstream ip2("book.csv");
    string name, author, type, publisher, yearPublisherStr, numberStr, id2Str;
    
    while (ip2.peek()!=EOF)
    {
	    
        getline(ip2 >> std::ws, id2Str, ',');
	    getline(ip2 >> std::ws, name, ','); 
        getline(ip2 >> std::ws, type, ',');
        getline(ip2 >> std::ws, author, ',');
        getline(ip2 >> std::ws, publisher, ',');
        getline(ip2, yearPublisherStr, ',');
        getline(ip2, numberStr, '\n');

        int yearPublished = stoi(yearPublisherStr);
        int ID = stoi(id2Str);
        int number = stoi(numberStr);
        
        book b;
        b.setID(ID);
        b.setName(name);
        b.setType(type);
        b.setAuthor(author);
        b.setPublisher(publisher);
        b.setYearpublisher(yearPublished);
        b.setNumber(number);
        sach.push_back(b);
    }
    ip2.close();
}

void docfile2(vector<Staff> &sf){
    ifstream ip3("admin.csv");
    string username, password, hoten, cccd, date, email, phonenumber, id, school, department, office;
    
    if (!ip3.is_open()) {
        cout << "Khong the mo file." << endl;
        return;
    }

    while (ip3.peek()!=EOF)
    {
        getline(ip3 >> std::ws, username, ','); // Loại bỏ khoảng trắng khi đọc
        getline(ip3 >> std::ws, password, ',');
        getline(ip3 >> std::ws, hoten, ',');
        getline(ip3 >> std::ws, cccd, ',');
        getline(ip3 >> std::ws, date, ',');
        getline(ip3 >> std::ws, email, ',');
        getline(ip3 >> std::ws, phonenumber, ',');
        getline(ip3 >> std::ws, id, ',');
        getline(ip3 >> std::ws, school, ',');
        getline(ip3 >> std::ws, department, ',');
        getline(ip3 >> std::ws, office, '\n');

	    Staff st; 
        st.setAccount(username);
        st.setPassword(password);
        st.setFullname(hoten);
        st.setCCCD(cccd);
        st.setDateOfBirth(date);
        st.setEmail(email);
        st.setPhoneNumber(phonenumber);
        st.setStaffID(id);
        st.setSchool(school);
        st.setDepartment(department);
        st.setOffice(office);
        sf.push_back(st);
    }
    ip3.close();
}

void updateFile1(vector<Student>& hs) {
    ofstream outFile1("data.csv");

    if (!outFile1.is_open()) {
        cout << "Khong the mo file de ghi." << endl;
        return;
    }

    for (auto& student : hs) {
        outFile1 << student.GetID() << ',' << student.Getaccount() << ',' << student.Getpassword() << ',' << student.Getfull_name() << ',' << student.Getcccd() << ',' << student.Getdate_of_birth() << ',' << student.Getemail() << ',' << student.Getphone_number() << ',' << student.getStudent_id() << ',' << student.getClass_name() << ',' << student.getCohort() << ',' << student.getSchool() << ',' << student.getDepartment() << ',' << student.GetBorrow() << endl;
    }
    outFile1.close();
}

void updateFile2(vector<book>& b) {
    ofstream outFile2("book.csv");

    if (!outFile2.is_open()) {
        cout << "Khong the mo file de ghi." << endl;
        return;
    }

    for (auto& book : b) {
        outFile2 << book.getID() << ',' << book.getName() << ',' << book.getType() << ',' << book.getAuthor() << ',' << book.getPublisher() << ',' << book.getYearPublished() << ',' << book.getNumber() << endl;
    }
    outFile2.close();
}

void updateFile3(vector<Staff>& sf) {
    ofstream outFile3("admin.csv");

    if (!outFile3.is_open()) {
        cout << "Khong the mo file de ghi." << endl;
        return;
    }

    for (auto& staff : sf) {
        outFile3 << staff.Getaccount() << ',' << staff.Getpassword() << ',' << staff.Getfull_name() << ',' << staff.Getcccd() << ',' << staff.Getdate_of_birth() << ',' << staff.Getemail() << ',' << staff.Getphone_number() << ',' << staff.getStaffID() << ',' << staff.getSchool() << ',' << staff.getDepartment() << ',' << staff.getOffice() << endl;
    }
    outFile3.close();
}