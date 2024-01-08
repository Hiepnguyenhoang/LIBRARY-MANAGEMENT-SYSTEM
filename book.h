#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include"book.h"

using namespace std;

class book{
    private:
        string name;
        string author;
        string type;
        string publisher;
        int yearPublished;
        int number;
        int ID;
    public:
        book(){
            name = "";
            author = "";
            type = "";
            publisher = "";
            yearPublished = 0;
            number = 0;
            ID = 0;
        }

        string getName();

        string getAuthor();

        string getType();
    
        string getPublisher();

        int getYearPublished();

        int getNumber();

        int getID();

        void setName(string &name);

        void setAuthor(string &author);

        void setType(string &type);

        void setPublisher(string &publisher);

        void setYearpublisher(int &yearPublished);

        void setID(int &ID);

        void setNumber(int &Number);

        void display();

        void showBookInformation();
        
        void addBook();
};
