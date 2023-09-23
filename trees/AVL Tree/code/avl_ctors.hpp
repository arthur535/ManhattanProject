#include "avl_class.h"
#include <iostream>
using namespace std;

template <typename T>
AVLTree<T>::AVLTree(){
    root = nullptr;
}

template <typename T>
AVLTree<T>::AVLTree(const AVLTree& oth){
    if(this != &oth){
        root = clone(oth.root);
    }
}

template <typename T>
AVLTree<T>::AVLTree(AVLTree&& rhs){
    if(this != &rhs){
        root = rhs.root;
        rhs.root = nullptr;
    }
}

template <typename T>
AVLTree<T>::AVLTree(T elem){
    root = new Node(elem);
}

template <typename T>
AVLTree<T>::AVLTree(initializer_list<T> list){
    root = nullptr;
    for (auto& ref : list) {
        insert(ref);
    }
}

template <typename T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree& oth){
    if (this == &oth){
        return *this;
    }
    if (root != nullptr){
        clear(root);
        root = nullptr;
    }
    root = clone(oth.root);
    return *this;
}

template <typename T>
AVLTree<T>& AVLTree<T>::operator=(AVLTree&& rhs){
    if (root != nullptr){
        clear(root);
        root = nullptr;
    }
    root = rhs.root;
    rhs.root = nullptr;
    return *this;
}

template <typename T>
AVLTree<T>::~AVLTree() {
    clear(root);
}
