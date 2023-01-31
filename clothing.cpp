#include "clothing.h"
#include "product.h"

using namespace std;

Clothing::Clothing(std::string brand, std::string size, std::string category, std::string name, double price, int qty)
        : Product(category, name, price, qty),
          brand_(brand),
          size_(size) {
}

Clothing::~Clothing() {

}

std::string Clothing::getBrand() const {
    return brand_;
}

std::string Clothing::getSize() const {
    return size_;
}

std::set<std::string> Clothing::keywords() const {
    std::set<string> allKeyWords;
    std::string rawKeywords = "";
    rawKeywords = getName() + " " + getBrand();
    allKeyWords = parseStringToWords(rawKeywords);
    return allKeyWords;
}

std::string Clothing::displayString() const {
    return getName() + "\n" + "Size: " + getSize() + " Brand: " + getBrand() + "\n" + to_string(getPrice()) + " " +
           to_string(getQty()) + " left.";
}

void Clothing::dump(std::ostream &os) const {
    Product::dump(os);
    os << size_ + "\n" + brand_ << endl;
}