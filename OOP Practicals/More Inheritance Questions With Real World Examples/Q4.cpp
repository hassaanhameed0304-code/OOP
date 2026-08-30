#include <iostream>

using namespace std;

class Media {
protected:
    string title;
    bool isBorrowed;

public:
    Media(string t) : title(t), isBorrowed(false) {}

    virtual void borrowMedia() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << title << " has been borrowed.\n";
        } else {
            cout << title << " is already borrowed.\n";
        }
    }

    virtual void returnMedia() {
        if (isBorrowed) {
            isBorrowed = false;
            cout << title << " has been returned.\n";
        } else {
            cout << title << " was not borrowed.\n";
        }
    }

    virtual void displayInfo() const {
        cout << "Title: " << title << "\n"
             << "Status: " << (isBorrowed ? "Borrowed" : "Available") << "\n";
    }
    
    virtual ~Media() {}
};

class BookAttributes {
protected:
    string author;

public:
    BookAttributes(string a) : author(a) {}
};

class MagazineAttributes {
protected:
    int issueNumber;

public:
    MagazineAttributes(int i) : issueNumber(i) {}
};

class DVDAttributes {
protected:
    string director;

public:
    DVDAttributes(string d) : director(d) {}
};

class Book : public Media, public BookAttributes {
public:
    Book(string t, string a) : Media(t), BookAttributes(a) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << author << "\n\n";
    }
};

class Magazine : public Media, public MagazineAttributes {
public:
    Magazine(string t, int i) : Media(t), MagazineAttributes(i) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << "\n\n";
    }
};

class DVD : public Media, public DVDAttributes {
public:
    DVD(string t, string d) : Media(t), DVDAttributes(d) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << director << "\n\n";
    }
};

int main() {
    Book myBook("1997", "Charlie And Choclate Factory");
    Magazine myMagazine("V-Shine", 104);
    DVD myDVD("Home Alone", "Eternal Sunshine Of Spotless Mind");

    myBook.displayInfo();
    myMagazine.displayInfo();
    myDVD.displayInfo();

    myBook.borrowMedia();
    myBook.displayInfo();

    myBook.returnMedia();
    myBook.displayInfo();

    return 0;
}