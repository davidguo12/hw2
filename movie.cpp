//
// Created by test on 1/28/23.
//

#include "movie.h"
#include "product.h"

using namespace std;

Movie::Movie(std::string genre, std::string rating, std::string category, std::string name, double price, int qty)
        : Product(category, name, price, qty),
          genre_(genre),
          rating_(rating) {

}

Movie::~Movie(){

}

std::string Movie::getGenre() const {
    return genre_;
}

std::string Movie::getRating() const {
    return rating_;
}

std::set<std::string> Movie::keywords() const{
    std::set<string> allKeywords;
    std::string rawKeywords = "";
    rawKeywords = getName();
    allKeywords = parseStringToWords(rawKeywords);
    allKeywords.insert(convToLower(getGenre()));
    return allKeywords;
}

std::string Movie::displayString() const {
    return getName() + "\n" + "Genre: " + getGenre() + " Rating: " + getRating() + "\n" + to_string(getPrice()) + " " +
            to_string(getQty()) + " left.";
}

void Movie::dump(std::ostream &os) const{
    Product::dump(os);
    os << genre_ + "\n" + rating_ << endl;
}