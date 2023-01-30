#include "user.h"
using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1)
{

}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type)
{

}

User::~User()
{

}


std::string User::getName() const
{
    return name_;
}

double User::getBalance() const
{
    return balance_;
}

void User::deductAmount(double amt)
{
    balance_ -= amt;
}

void User::dump(std::ostream& os)
{
    os << name_ << " "  << balance_ << " " << type_ << endl;
}

void displayProductsInCart(vector<Product*>& hits)
{
    int resultNo = 1;
    if (hits.begin() == hits.end()) {
        cout << "No results found!" << endl;
        return;
    }
    for(vector<Product*>::iterator it = hits.begin(); it != hits.end(); ++it) {
        cout << "Hit " << setw(3) << resultNo << endl;
        cout << (*it)->displayString() << endl;
        cout << endl;
        resultNo++;
    }
}

void User::addToCart(Product* product) {
    if(product == nullptr){
        return;
    }
    cart_.push_back(product);
}

void User::viewCart() {
    displayProductsInCart(cart_);
}

void User::buyCart() {
    for(Product* product : cart_){
        if(product->getQty() > 0 && product->getPrice() <= balance_){
            product->subtractQty(1);
            balance_ -= product->getPrice();
            cart_.erase(cart_.begin());
        }
    }
}