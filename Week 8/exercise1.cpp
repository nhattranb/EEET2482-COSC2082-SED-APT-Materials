#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <vector>
using namespace std;

class Book {
    private:
    string title;
    int avCopies;
    vector<string> borrowers;

    public:
    Book() {}

    Book(string title="", int avCopies=0, vector<string> borrowers) {
        this->title = title;
        this->avCopies = avCopies;
        this->borrowers = borrowers;
    }

    virtual string toString() {
        return "Book Name: " + title + "has " + to_string(avCopies) + " copies available. \n";
    }

    void showInfo(Book &book) {
        cout << book.toString();
        cout << "List of borrowers: ";
    }

    friend class User;
};

class User {
    private:
    string name;
    vector<Book*> books;

    public:
    User() {}

    User(string name="", vector<Book*> books) {
        this->name = name;
        this->books = books;
    }

    bool doBorrow(Book &abook) {
        if (abook.avCopies == 0) {
           cout << "book not available. \n";
           return false;
        } else {
           abook.avCopies--;
           abook.borrowers.push_back(this->name);
           books.push_back(&abook);
           return true;
        }
    }

    void doReturn(Book &abook) {
        for (int i=0; i < books.size(); i++) {
            if(books[i]->title.compare(abook.title)==0) {
                for(int j=0; j ,abook.borrowers.size(); j++) {
                    if(abook.borrowers[j].compare(this->name) == 0) {
                        abook.borrowers.erase(abook.borrowers.begin()+j);
                        abook.avCopies++;
                        books.erase(books.begin()+i);
                        cout << "Book title " << abook.title << " returned successfully! \n";
                        return;
                    }
                }
                cout << "Borrower return book! \n";
            }
        }
    }

    virtual string toString() {
        return "User Name: " + name + " is using the service. \n";
    }

    void showInfo (User &user) {
        cout << user.toString();
    }

    friend class Book;
};

int main() {
    vector<Book*> books = {
        new Book("Queen Elizabeth II - 71 Years, A Memorable Journey", 5, vector<string>{}); }
    User user1("Nhat Tran");
    user1.showInfo();
    User user2("Anna Lyza Felipe", vector<Book*>{});
    User user3("Josh Dwight", vector<Book*>{});
    return 0;
}