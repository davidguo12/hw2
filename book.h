#ifndef BOOK_H
#define BOOK_H
#include "product.h"

class Book : public Product {
public:

    Book(std::string author, std::string ISBN, std::string category, std::string name, double price, int qty);

    ~Book();

    std::string getAuthor() const;

    std::string getISBN() const;

    std::set<std::string> keywords() const;

    std::string displayString() const;

    void dump(std::ostream &os) const;

protected:
    std::string author_;
    std::string isbn_;
};

#endif