#include"book.h"

string book:: getName(){
    return name;
}

string book:: getAuthor(){
    return author;
}

string book:: getType(){
    return type;
}
    
string book:: getPublisher(){
    return publisher;
}

int book:: getYearPublished(){
    return yearPublished;
}

int book:: getNumber(){
    return number;
}

int book:: getID(){
    return ID;
}

void Vekhung2(){
    std::cout <<"\t\t\t\t\t================================================="<<"\n";
    std::cout <<"\t\t\t\t\t|\t\t  Library System   \t\t|" << std::endl;
    std::cout <<"\t\t\t\t\t================================================="<<"\n";
}

void book:: setName(string &nameBook){
    name = nameBook;
}

void book:: setAuthor(string &nameAuthor){
    author = nameAuthor;
}

void book:: setType(string &nameType){
    type = nameType;
}

void book:: setPublisher(string &namePublisher){
    publisher = namePublisher;
}

void book:: setYearpublisher(int &YearPublished){
    yearPublished = YearPublished;
}

void book:: setID(int &id){
    ID = id;
}

void book:: setNumber(int &Number){
    number = Number;
}

void book:: display(){
    cout << left << setw(8) << ID << setw(40) << name << setw(20) << type << setw(35) << author << setw(20) << number << endl;
}

void book:: showBookInformation(){
    system("cls");
    Vekhung2();
    cout << "\t\t\t\t\tThong tin sach la: "<< endl;
    cout << "\t\t\t\t\tID: " << ID << endl;
    cout << "\t\t\t\t\tTen sach: " << name << endl;
    cout << "\t\t\t\t\tTac gia: " << author << endl;
    cout << "\t\t\t\t\tNha xuat ban: " << publisher << endl;
    cout << "\t\t\t\t\tNam xuat ban: " << yearPublished << endl;
    cout << "\t\t\t\t\tSo luong sach: " << number << endl;
} 
        
void book:: addBook(){
    system("cls");
    Vekhung2();
    cout << "\t\t\t\t\tNhap thong tin sach muon them! "<< endl;
    
    cout << "\t\t\t\t\tTen sach: ";
    getline(cin,name);
    cout << "\t\t\t\t\tTac gia: ";
    getline(cin,author);
    cout << "\t\t\t\t\tThe loai: ";
    getline(cin,type);
    cout << "\t\t\t\t\tNha xuat ban: ";
    getline(cin,publisher);
    cout << "\t\t\t\t\tNam xuat ban ";
    cin >> yearPublished;
    cout << "\t\t\t\t\tSo luong sach: ";
    cin >> number;
    cout << endl;
}