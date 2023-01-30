#include "datastore.h"
#include <map>


#ifndef HW2_MYDATASTORE_H
#define HW2_MYDATASTORE_H

class MyDataStore : public DataStore {
public:
    MyDataStore();

    void addProduct(Product *p);

    void addUser(User *u);

    std::vector<Product *> search(std::vector<std::string> &terms, int type);

    void dump(std::ostream &ofile);

    void addProductToCart(std::string userName, Product* product);

protected:
    std::vector<Product *> allProducts;
//    std::vector<User *> allUsers;

    std::map<std::string, std::set<Product*>> keywordToProductMap;
    std::map<std::string, User*> usernameToUserMap;
};

#endif //HW2_MYDATASTORE_H

