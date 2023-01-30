//
// Created by test on 1/28/23.
//

#ifndef HW2_MOVIE_H
#define HW2_MOVIE_H
#include "product.h"

class Movie : public Product {
public:
    Movie(std::string genre, std::string rating, std::string category, std::string name, double price, int qty);

    ~Movie();

    std::string getGenre() const;

    std::string getRating() const;

    std::set<std::string> keywords() const;

    std::string displayString() const;

    void dump(std::ostream &os) const;

protected:
    std::string genre_;
    std::string rating_;
};

#endif //HW2_MOVIE_H
