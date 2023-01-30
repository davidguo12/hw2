//
// Created by test on 1/28/23.
//

#include "mydatastore.h"
#include "util.h"

using namespace std;

MyDataStore::MyDataStore() {

}

void MyDataStore::addProduct(Product *p){
    allProducts.push_back(p);

    std::map<std::string, std::set<Product*>>::iterator mapItr;

    std::set<std::string> keywords = p->keywords();
    typename std::set<std::string>::iterator it;
    for(it = keywords.begin(); it != keywords.end(); it++){
        std::string keyword = *it;
        mapItr = keywordToProductMap.find(keyword);
        if(mapItr != keywordToProductMap.end()){
            mapItr->second.insert(p);
        }else{
            std::set<Product*> actualProducts;
            actualProducts.insert(p);
            keywordToProductMap.insert({keyword, actualProducts});
        }
    }
}

void MyDataStore::addUser(User *u) {
    usernameToUserMap.insert({u->getName(), u});
}

std::vector<Product *> MyDataStore::search(std::vector<std::string> &terms, int type) {
    if(terms.size() == 0){
        std::vector<Product*> relevantProducts;
        return relevantProducts;
    }

    std::set<Product*> testRelevantProducts;
    std::map<std::string, std::set<Product*>>::iterator mapItr;
    for(string term : terms){
        mapItr = keywordToProductMap.find(term);
        if(mapItr == keywordToProductMap.end()){
            continue;
        }
        if(testRelevantProducts.empty()){
            testRelevantProducts = mapItr->second;
            continue;
        }
        if(type == 0){
            testRelevantProducts = setIntersection(testRelevantProducts, mapItr->second);
        }
        if(type == 1){
            testRelevantProducts = setUnion(testRelevantProducts, mapItr->second);
        }
    }
    std::vector<Product*> relevantProducts(testRelevantProducts.begin(), testRelevantProducts.end());
    return relevantProducts;
}

void MyDataStore::addProductToCart(std::string userName, Product *product) {
    std::map<std::string, User*>::iterator it;
    it = usernameToUserMap.find(userName);
    it->second->addToCart(product);
}


void MyDataStore::dump(std::ostream &ofile) {
    ofile << "<products>" << endl;
    for(Product* product: allProducts){
        product->dump(ofile);
    }
    ofile << "</products" << endl;
    ofile << "<users>" << endl;
    map<string, User*>::iterator it;
    for(it = usernameToUserMap.begin(); it != usernameToUserMap.end(); it++){
        it->second->dump(ofile);
    }
    ofile << "</users>" << endl;
    return;
}