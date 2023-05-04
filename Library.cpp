#include "Library.h"

Library::Library() : size(0), library(nullptr) {};
Library::Library(std::initializer_list<Book> list) : size(list.size()), library{new Book[size]} {
    size_t i = 0;
    for(auto& book: list) {
        library[i]=book;
        i++;
    }
};
// deap
Library::Library(const Library& orig) {
    this->size = orig.size;
    this->library = new Book[orig.size];
    for(int i = 0; i < size; ++i) {
        library[i]=orig.library[i];
    }
};
//Library::Library(const Library& orig) {
//    this->size = orig.size;
//    this->library = orig.library;
//}

Library& Library::operator=(const Library& right) {
    Library tmp = right;
    swap(this->size, tmp.size);
    swap(this->library, tmp.library);
    return *this;
};
Library& Library::operator=(Library&& right) {
    swap(this->size, right.size);
    swap(this->library, right.library);
    return *this;
};
Book& Library::operator[](std::size_t index) {
    return library[index];
};
Book& Library::operator[](std::size_t index) const {
    return library[index];
};

Library::Library(Library&& orig) {
    this->size=move(orig.size);
    this->library=move(orig.library);
};
Library::Library(size_t size) : size(size), library(new Book[size]) {};

size_t Library::GetSize() const {
    return this->size;
};
void Library::SetSize(size_t size) {
    this->size = size;
};

Library::~Library() {
    if(library != nullptr) {
        delete[] library;
    }
};