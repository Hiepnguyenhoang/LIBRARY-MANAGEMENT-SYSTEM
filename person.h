#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include"book.h"

using namespace std;

class Person{
    protected:
        int id;
        string full_name;
        string cccd;
        string phone_number ;
        string date_of_birth;
        string email;
        string account;
        string password;
        string borrow;
    public:
        Person() {
            full_name = "";
            cccd = "";
            date_of_birth = "";
            phone_number = "";
            email = "";
            account = "";
            password = "";
            borrow = "";
        }
        
        string Getfull_name();

        string Getcccd();

        string Getphone_number ();

        string Getdate_of_birth();

        string Getemail();

        string Getaccount();

        string Getpassword();

        string GetBorrow();

        int GetID();

        void setFullname(string& name);

        void setCCCD(string& cccdNumber);

        void setDateOfBirth(string& dob);

        void setPhoneNumber(string& phone);

        void setEmail(string& emailAddress);

        void setAccount(string& acc);

        void setPassword(string& pass);

        void setID(int &ID);

        void setBorrow(string& Borrow);
    
        void borrowBook(vector<book>& listbook);

        bool searchBook(vector<book>& listbook);

        void returnBook(vector<book>& listbook);

        void addAccount();

        virtual void set_info();

        virtual void print_info(vector<book> listbook);

        void editInformation();
};

class Student : public Person{
    private:
        string student_id;
        string class_name;
        int cohort; // Khóa
        string school;
        string department;
    public:
        Student() : cohort(0) {
            student_id = "";
            class_name = "";
            school = "";
            department = "";
        }

        string getStudent_id();

        string getClass_name();

        int getCohort();

        string getSchool();

        string getDepartment();

        void setStudentID(const string& id);

        void setClassName(const string& className);

        void setCohort(int cohortValue);

        void setSchool(const string& schoolName);

        void setDepartment(const string& departmentName);

        void set_info() override;

        void editInformation();
        
        void print_info(vector<book> listbook) override;

        void display();
};

class Staff : public Person{
    private:
        string staff_id;
        string school;
        string department;
        string office;

    public:

        Staff() {
            staff_id = "";
            school = "";
            department = "";
            office = "";
        }

        string getStaffID();

        string getSchool();

        string getDepartment();

        string getOffice();

        void setStaffID(const string& id);

        void setSchool(const string& schoolName);

        void setDepartment(const string& departmentName);

        void setOffice(const string& officeLocation);

        void print_info(vector<book> listbook) override;

        void set_info() override;

        void bookManager(vector<book>& listbook);

        void Statistical(vector<book> listbook, vector<Student> listUser);

        bool searchUser(vector<Student>& listUser);
        
        void print_infoUser(vector<Student>& listUser, vector<book>& listbook);

        void deleteUser(vector<Student>& listUser, vector<book>& listbook);

        void editInfor();
};