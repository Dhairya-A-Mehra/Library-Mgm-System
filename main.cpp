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

class BookIssuing {
public:
    static void issueBook(vector<book*>& library) {
        if (library.empty()) {
            cout << "Library is empty. Cannot issue a book." << endl;
            return;
        }

        cout << "Available Books:" << endl;
        for (int i = 0; i < library.size(); i++) {
            cout << i + 1 << ". ";
            library[i]->putdata();
        }

        int bookIndex;
        cout << "Enter the index of the book to issue (1-" << library.size() << "): ";
        cin >> bookIndex;

        if (bookIndex >= 1 && bookIndex <= library.size()) {
            cout << "You have issued the following book:" << endl;
            library[bookIndex - 1]->putdata();
            // You can add more logic here, such as updating the book's status.
        } else {
            cout << "Invalid book index. Please try again." << endl;
        }
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
        cout << "Publication: " << publication << endl;
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
        cout << "1. Issue a Book" << endl;
        cout << "2. Add a Book" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
                // Implement book issuing logic
                BookIssuing::issueBook(library);
                break;

            case 2:
                while (true) {
                    cout << "\nAdd a Book:" << endl;
                    cout << "1. Add Textbook" << endl;
                    cout << "2. Add Novel" << endl;
                    cout << "3. Add Reference Book" << endl;
                    cout << "4. Add Fiction Book" << endl;
                    cout << "0. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    int addChoice;
                    cin >> addChoice;

                    switch (addChoice) {
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

                        case 0:
                            // Return to the main menu
                            break;

                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }

                    // Ask if the user wants to add more books
                    cout << "Do you want to add more books? (1 for yes, 0 for no): ";
                    int addMore;
                    cin >> addMore;

                    if (addMore == 0) {
                        break; // Exit the add books loop
                    }
                }
                break;

            case 0:
                // Clean up memory and exit
               for (int i = 0; i < library.size(); i++)
                {
                    delete library[i];
                }
                cout << "Thanks for using this system." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
