#include "bst_class.h"
#include <iostream>

using namespace std;

//traversals
template <typename T>
void BSTree<T>::inorder_traversal() const {
    inorder_traversal(root);
}

template <typename T>
void BSTree<T>::preorder_traversal() const {
    preorder_traversal(root);
}

template <typename T>
void BSTree<T>::postorder_traversal() const {
    postorder_traversal(root);
}

template <typename T>
void BSTree<T>::levelorder_traversal() const {
    levelorder_traversal(root);
}

template <typename T>
uint BSTree<T>::get_height() const {
    return get_height(root);
}

//find_min function
template <typename T>
const T& BSTree<T>::find_min() const {
    if(find_min(root)){
        return find_min(root)->val;
    }
    return NULL;
}

//find_min function
template <typename T>
const T& BSTree<T>::find_max() const {
    if(find_max(root)){
        return find_max(root)->val;
    }
    return NULL;
}

//insert function move
template<typename T>
void BSTree<T>::insert(const T& value){
    insert(value, root);
}

//insert function
template<typename T>
void BSTree<T>::insert(T&& value){
    insert(value, root);
}

//remove function
template<typename T>
void BSTree<T>::remove(const T& value){
    remove(value, root);
}

//if tree contains T value
template<typename T>
bool BSTree<T>::contains(const T& value) const {
    if(contains(value, root)){
        return true;
    }
    else{
        return false;
    }
}

//if tree contains T value
template<typename T>
bool BSTree<T>::contains(T&& value) const {
    if(contains(value, root)){
        return true;
    }
    else{
        return false;
    }
}

//clear the tree
template <typename T>
void BSTree<T>::clear() noexcept {
    destruct(root);
}

//if the tree is empty
template <typename T>
bool BSTree<T>::is_empty() const {
    return is_empty(root);
}

template <typename T>
T BSTree<T>::get_predecessor(const T& value){
    Node* node = contains(value, root);
    if(node){
        if(get_predecessor(node) != nullptr){
            return get_predecessor(node)->val;
        }
    }
    return NULL;
}

template <typename T>
T BSTree<T>::get_predecessor(T&& value){
    Node* node = contains(value, root);
    if(node){
        if(get_predecessor(node) != nullptr){
            return get_predecessor(node)->val;
        }
    }
    return NULL;
}

template <typename T>
T BSTree<T>::get_successor(const T& value){
    Node* node = contains(value, root);
    if(node){
        if(get_successor(node) != nullptr){
            return get_successor(node)->val;
        }
    }
    return NULL;
}

template <typename T>
T BSTree<T>::get_successor(T&& value){
    Node* node = contains(value, root);
    if(node){
        if(get_successor(node) != nullptr){
            return get_successor(node)->val;
        }
    }
    return NULL;
}
