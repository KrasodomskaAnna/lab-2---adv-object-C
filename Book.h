#ifndef LAB_2_BOOK_H
#define LAB_2_BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    Book();
    Book(const string& author, const string& title);
    Book(string&& author, string&& title);

    // konstruktor kopiujacy
    Book(const Book& other);
    // operator kopiujacy
    Book& operator=(const Book& right);

    // konstruktor przenoszacy
    Book(Book&& other);
    // operator przenoszacy
    Book& operator=(Book&& right);

    string GetAuthor() const;
    string GetTitle() const;

    void SetAuthor(const string& author);
    void SetTitle(const string& title);
    void SetAuthor(string&& author);
    void SetTitle(string&& title);
private:
    string autor;
    string title;
};


#endif //LAB_2_BOOK_H
