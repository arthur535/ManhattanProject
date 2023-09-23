#include "bst_class.h"
#include <queue>
#include <iostream>

using namespace std;

//traversals : private
template<typename T>
void BSTree<T>::inorder_traversal(Node* root) const {
    if(!root){
        return;
    }
    inorder_traversal(root->left);
    cout << root->val << " ";
    inorder_traversal(root->right);
}

template<typename T>
void BSTree<T>::preorder_traversal(Node* root) const {
    if(!root){
        return;
    }
    cout << root->val << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

template<typename T>
void BSTree<T>::postorder_traversal(Node* root) const {
    if(!root){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->val << " ";
}

template<typename T>
void BSTree<T>::levelorder_traversal(Node* root) const {
    if(!root)return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* top = q.front();
        cout << top->val << " ";
        q.pop();
        if(top->left)q.push(top->left);
        if(top->right)q.push(top->right);
    }
    cout << endl;
}

template <typename T>
uint BSTree<T>::get_height(Node* root) const {
    if(!root) return 0;
    return max(get_height(root->left),get_height(root->right)) + 1;
}

//insert function : private
template<typename T>
void BSTree<T>::insert(const T& value, Node*& root){
    if(!root){
        root = GetNewNode(value);
        return;
    }
    if(root->val > value) {
        insert(value, root->left);
    }
    else if(root->val < value) {
        insert(value, root->right);
    }
}

//find_min function : private
template <typename T>
typename BSTree<T>::Node* BSTree<T>::find_min(Node* root) const {
    if (!root) {
        return nullptr;
    }
    if (!root->left) {
        return root;
    }
    return find_min(root->left);
}

//find_max function : private
template <typename T>
typename BSTree<T>::Node* BSTree<T>::find_max(Node* root) const {
    if (!root) {
        return nullptr;
    }
    if (!root->right) {
        return root;
    }
    return find_max(root->right);
}

//remove function : private
template<typename T>
void BSTree<T>::remove(const T& value, Node*& root){
    if(!root){
        return;
    }
    if(root->val > value) {
        remove(value, root->left);
    }
    else if(root->val < value) {
        remove(value, root->right);
    }
    else{
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }
        else if(root->left != nullptr or root->right != nullptr){
            root->val = find_min(root->right)->val;
            remove(root->val, root->right);
        }
    }
}

//if tree contains T value : private
template<typename T>
typename BSTree<T>::Node* BSTree<T>::contains(const T& value, Node* root) const {
    if(!root){
        return nullptr;
    }
    if(root->val > value) {
        return contains(value, root->left);
    }
    else if(root->val < value) {
        return contains(value, root->right);
    }
    
    return root;
}

//destruct function : private
template <typename T>
void BSTree<T>::destruct(Node*& root) noexcept {
    if(root) {
        destruct(root->left);
        destruct(root->right);
        delete root;
        root = nullptr;
    }
    root = nullptr;
}

//if the tree is empty : private
template <typename T>
bool BSTree<T>::is_empty(Node* root) const {
    return root == nullptr;
}

//private function for copy constructor
template <typename T>
typename BSTree<T>::Node* BSTree<T>::clone(Node* root) const {
    if (!root) {
        return nullptr;
    }
    return new Node(root->val, clone(root->left), clone(root->right));
}

template <typename T>
typename BSTree<T>::Node* BSTree<T>::get_predecessor(Node* node) const {
    if(!node){return nullptr;}
    
    if(node->left){
        return find_max(node->left);
    }
    
    Node* predecessor = nullptr;
    Node* curr = root;
    
    while(curr != node) {
        if(node->val > curr->val){
            predecessor = curr;
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }
    
    return predecessor;
}

template <typename T>
typename BSTree<T>::Node* BSTree<T>::get_successor(Node* node) const {
    if(!node){return nullptr;}
    
    if(node->right){
        return find_min(node->right);
    }
    
    Node* successor = nullptr;
    Node* curr = root;
    
    while(curr != node) {
        if(node->val < curr->val){
            successor = curr;
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    
    return successor;
}
