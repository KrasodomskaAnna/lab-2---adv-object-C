#include "Book.h"

Book::Book() : autor("-"), title("-") {};
Book::Book(const string& author, const string& title) : autor(author), title(title) {};
Book::Book(string&& author, string&& title) : autor(author), title(title) {};

Book::Book(const Book& other) : autor(other.autor), title(other.title) {};

Book::Book(Book &&other) {
    this->autor = other.autor;
    this->title = other.title;
    other.autor = nullptr;
    other.title = nullptr;
}

// operator kopiujacy
Book& Book::operator=(const Book& right) {
    Book tmp = right;
    swap(this->autor, tmp.autor);
    swap(this->title, tmp.title);
    return *this;
}
// operator przenoszacy
Book& Book::operator=(Book&& right) {
    swap(this->autor,right.autor);
    swap(this->title, right.title);
    return *this;
}



string Book::GetAuthor() const {
    return this->autor;
}
string Book::GetTitle() const {
    return this->title;
}

void Book::SetAuthor(const string& author) {
    this->autor = author;
}
void Book::SetTitle(const string& title) {
    this->title = title;
}
void Book::SetAuthor(string&& author) {
    this->autor = author;
}
void Book::SetTitle(string&& title){
    this->title = title;
}