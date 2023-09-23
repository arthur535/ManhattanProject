#include "bst_class.h"
#include <iostream>
//#define CTOR_S
using namespace std;

//default constructor
template<typename T>
BSTree<T>::BSTree() {
#ifdef CTOR_S
    cout << "default constructor" << endl;
#endif
}

//copy constructor
template<typename T>
BSTree<T>::BSTree(const BSTree& oth) {
    if (this != &oth) {
        root = clone(oth.root);
    }
}

//initializer list constructor
template<typename T>
BSTree<T>::BSTree(std::initializer_list<T> init) {
    for (auto& ref:init) {
        insert(ref,root);
    }
}

//move constructor
template<typename T>
BSTree<T>::BSTree(BSTree&& rhs) {
    if (this != &rhs) {
        root = rhs.root;
        rhs.root = nullptr;
    }
}

//copy assignment operator
template<typename T>
BSTree<T>& BSTree<T>::operator=(const BSTree& oth) {
    if (this != &oth) {
        root = clone(oth.root);
    }
    return *this;
}

//move assignment operator
template<typename T>
BSTree<T>& BSTree<T>::operator=(BSTree&& rhs) {
    if (this != &rhs) {
        root = rhs.root;
        rhs.root = nullptr;
    }
    return *this;
}

//destructor
template <typename T>
BSTree<T>::~BSTree<T>() {
    destruct(root);
}
