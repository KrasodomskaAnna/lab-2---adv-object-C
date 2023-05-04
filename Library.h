#ifndef LAB_2_LIBRARY_H
#define LAB_2_LIBRARY_H

#include "Book.h"
#include <initializer_list>
using namespace std;

class Library {
public:
    Library();
    Library(std::initializer_list<Book> list);
    Library(const Library& orig);
    Library(Library&& orig);
    Library(size_t size);

    Library& operator=(const Library& right);
    Library& operator=(Library&& right);
    Book& operator[](std::size_t index);
    Book& operator[](std::size_t index) const;

    size_t GetSize() const;
    void SetSize(size_t size);

    ~Library();
private:
    size_t size;
    Book* library;
};


#endif //LAB_2_LIBRARY_H
