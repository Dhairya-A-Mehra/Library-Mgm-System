#include <iostream>
using namespace std;

class book
{
    public:
    long long ISBN; 
    char auth[100];
    char bname[100];
    char genre[100];

    virtual void getdata()
    {
        cout << "Enter the name of the book: ";
        cin >> bname;
        cout << "\nEnter the name of the author: ";
        cin >> auth;
        cout << "\nEnter the ISBN: ";
        cin >> ISBN;
        cout << "\nEnter the genre:";
        cin >> genre;
    }
    virtual void putdata()
    {
        cout << "Book Name: " << bname << endl;
        cout << "Author: " << auth << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Genre: " << genre << endl;
    }
};

class textbook : public book
{
    public:
    char subject[100];
    float edition;

    virtual void getdata()
    {
        book::getdata();
        cout << "Enter the Subject Name: ";
        cin >> subject;
        cout << "\nEnter the edition of the book: ";
        cin >> edition;
    }
    virtual void putdata()
    {
        book::putdata();
        cout << "Subject: " << subject << endl;
        cout << "Edition: " << edition << endl;
    }
};

class novel : public book
{
    public:
    char publication[100];

    virtual void getdata()
    {
        book::getdata();
        cout << "\nEnter the name of publication: ";
        cin >> publication;
    }
    virtual void putdata()
    {
        book::putdata();
        cout << "Publications: " << publication << endl;
    }
};

class refrence_book : public book
{
    public:
    char publication[100];
    float edition;

    virtual void getdata()
    {
        book::getdata();
        cout << "\nEnter the name of the publication: ";
        cin >> publication;
        cout << "\nEnter the edition of the book: ";
        cin >> edition;
    }
    virtual void putdata()
    {
        book::putdata();
        cout << "Publication: " << publication << endl;
        cout << "Edition: " << edition << endl;
    }
};

class fiction : public book
{
    public:
    virtual void getdata()
    {
        book::getdata();
    }
    virtual void putdata()
    {
        book::putdata();
    }
};

class thriller : public book
{
    public:
    virtual void getdata()
    {
        book::getdata();
    }
    virtual void putdata()
    {
        book::putdata();
    }
};
