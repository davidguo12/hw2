//
// Created by test on 1/28/23.
//

#ifndef HW2_CLOTHING_H
#define HW2_CLOTHING_H

#include "product.h"

class Clothing : public Product {
public:
    Clothing(std::string brand, std::string size, std::string category, std::string name, double price, int qty);

    ~Clothing();

    std::string getBrand() const;

    std::string getSize() const;

    std::set<std::string > keywords() const;

    std::string displayString() const;

    void dump(std::ostream &os) const;


protected:
    std::string brand_;
    std::string size_;
};

#endif //HW2_CLOTHING_H
