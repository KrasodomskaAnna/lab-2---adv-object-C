#include <iostream>
#include "Library.h"

std::ostream& operator<<(std::ostream& ostr, const Book& book){
    ostr << "\n Autor: " << book.GetAuthor() << "\n Tytul: " << book.GetTitle() << "\n";
    return ostr;
}

std::ostream& operator<<(std::ostream& ostr, const Library& library){
    for(std::size_t i = 0; i < library.GetSize(); i++)
    {
        if(i > 0)
            ostr << ',';
        ostr << "\n Autor: " << library[i].GetAuthor() << "\n Tytul: " << library[i].GetTitle();
    }
    return ostr;
}

int main() {
    string a="Duma i Uprzedzenie", t="Jane Austen";
    Book e;
    cout << "e: "<< e << endl;
    Book b1 = {a, t};
    cout << "b1: "<< b1 << endl;
    Book b2 = {"Suzanne Collins","Hunger Games"};
    cout << "b2: "<< b2 << endl;
    Book b3 = b1;
    cout << "b3: "<< b3 << " b1: " << b1 << endl;
    e = std::move(b2);
    cout << "e: "<< e << " b2:" << b2 << endl;
    e.SetAuthor("Adam Mickiewicz");
    cout << "e: "<< e << endl;
    e.SetTitle("Dziady");
    cout << "e: "<< e << endl;

    cout << endl << endl << endl;

    {
        Library e;
        cout << "e: " << e << endl;
        //3-5 książek
        Library l1 = {{"Suzanne Collins", "Hunger Games Catching Fire"},
                      {"Suzanne Collins", "Hunger Games Mockingjay"},
                      {"Suzanne Collins", "Ballad of Songbirds and Snakes"}};
        cout << "l1: " << l1 << endl;
        Library l2(2);
        cout << "l2: " << l2 << endl;
        l2[0] = {"Cecilia Randall", "Hyperversum"};
        l2[1] = {"John Flanagan", "Ranger's Apprentice: The Ruins of Gorlan"};
        cout << "l2: " << l2 << endl;
        e = std::move(l2);
        cout << "e: " << e << " l2: " << l2 << endl;
        l1[0] = std::move(e[1]);
        cout << "l1: " << l1 << " e: " << e << endl;
        cout << "Przed:" <<  endl;
        cout <<"l1: " << l1 << "l2: " << l2 << endl;
        l1 = l2;
        cout << "Po:" <<  endl;
        cout <<"l1: " << l1 << "l2: " << l2 << endl;
    }

    return 0;
}
