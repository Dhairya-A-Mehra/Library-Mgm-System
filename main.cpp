#include <iostream>
#include <vector>
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
        cout << "Enter the name of the author: ";
        cin >> auth;
        cout << "Enter the ISBN: ";
        cin >> ISBN;
        cout << "Enter the genre: ";
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

    void getdata() override
    {
        book::getdata();
        cout << "Enter the Subject Name: ";
        cin >> subject;
        cout << "Enter the edition of the book: ";
        cin >> edition;
    }

    void putdata() override
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

    void getdata() override
    {
        book::getdata();
        cout << "Enter the name of publication: ";
        cin >> publication;
    }

    void putdata() override
    {
        book::putdata();
        cout << "Publications: " << publication << endl;
    }
};

class reference_book : public book
{
public:
    char publication[100];
    float edition;

    void getdata() override
    {
        book::getdata();
        cout << "Enter the name of the publication: ";
        cin >> publication;
        cout << "Enter the edition of the book: ";
        cin >> edition;
    }

    void putdata() override
    {
        book::putdata();
        cout << "Publication: " << publication << endl;
        cout << "Edition: " << edition << endl;
    }
};

class fiction : public book
{
public:
    void getdata() override
    {
        book::getdata();
    }

    void putdata() override
    {
        book::putdata();
    }
};

class thriller : public book
{
public:
    void getdata() override
    {
        book::getdata();
    }

    void putdata() override
    {
        book::putdata();
    }
};

int main()
{
    vector<book*> library;

    cout << "Library Management System" << endl;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Add Textbook" << endl;
        cout << "2. Add Novel" << endl;
        cout << "3. Add Reference Book" << endl;
        cout << "4. Add Fiction Book" << endl;
        cout << "5. List Books" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
                library.push_back(new textbook());
                library.back()->getdata();
                break;

            case 2:
                library.push_back(new novel());
                library.back()->getdata();
                break;

            case 3:
                library.push_back(new reference_book());
                library.back()->getdata();
                break;

            case 4:
                library.push_back(new fiction());
                library.back()->getdata();
                break;

            case 5:
                cout << "\nList of Books:" << endl;
                for (const auto& item : library)
                {
                    item->putdata();
                    cout << endl;
                }
                break;

            case 0:
                // Clean up memory
                for (auto item : library)
                {
                    delete item;
                }
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
