#include "book.h"
#include "product.h"

using namespace std;

#if 1

Book::Book(std::string author, std::string ISBN, std::string category, std::string name, double price, int qty)
        : Product(category, name, price, qty),
          author_(author),
          isbn_(ISBN) {
}

Book::~Book() {

}

std::string Book::getAuthor() const {
    return author_;
}

std::string Book::getISBN() const {
    return isbn_;
}

std::set<std::string> Book::keywords() const {
    std::set<string> allKeywords;
    std::string rawKeywords = "";
    rawKeywords = getName() + " " + getAuthor();
    allKeywords = parseStringToWords(rawKeywords);
    allKeywords.insert(convToLower(getISBN()));
    return allKeywords;
}

std::string Book::displayString() const {
    return getName() + "\n" + "Author: " + getAuthor() + " ISBN: " + getISBN() + "\n" + to_string(getPrice()) + " " +
           to_string(getQty()) + " left.";
}

void Book::dump(std::ostream &os) const {
    Product::dump(os);
    os << isbn_ + "\n" + author_ << endl;
}

#endif