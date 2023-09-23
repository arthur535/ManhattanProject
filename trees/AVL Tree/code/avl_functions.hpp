#include "avl_class.h"

template <typename T>
int AVLTree<T>::get_height() const{
    return get_height(root);
}

template <typename T>
void AVLTree<T>::inorder_traversal() const{
    inorder_traversal(root);
}

template <typename T>
void AVLTree<T>::preorder_traversal() const{
    preorder_traversal(root);
}

template <typename T>
void AVLTree<T>::postorder_traversal() const{
    postorder_traversal(root);
}

template <typename T>
void AVLTree<T>::levelorder_traversal() const{
    levelorder_traversal(root);
}

template <typename T>
void AVLTree<T>::insert(const T& value) {
    insert(value,root);
}

template <typename T>
void AVLTree<T>::remove(const T& value) {
    remove(value,root);
}

template <typename T>
const T& AVLTree<T>::find_min() const {
    return find_min(root)->data;
}

template <typename T>
const T& AVLTree<T>::find_max() const {
    return find_max(root)->data;
}

template <typename T>
bool AVLTree<T>::contains(const T& value) const {
    return contains(value,root);
}

template <typename T>
void AVLTree<T>::clear() {
    clear(root);
}

template <typename T>
unsigned int AVLTree<T>::count() const {
    return count(root);
}

template <typename T>
void AVLTree<T>::merge(const AVLTree& obj){
    if (root == obj.root){return;}
    merge(root,obj.root);
}

template <typename T>
vector<vector<T>> AVLTree<T>::allpaths(){
    if(!root){return {};}
    return allpaths(root);
}
