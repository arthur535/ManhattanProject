#include "avl_class.h"
#include <queue>
template<typename T>
int AVLTree<T>::get_height(const Node* root) const{
    if (!root)
        return 0;
    return max(get_height(root->left), get_height(root->right))+1;
}

template<typename T>
int AVLTree<T>::get_balance(const Node* root) const{
    if(!root){
        return 0;
    }
    return get_height(root->left) - get_height(root->right);
}

template<typename T>
void AVLTree<T>::inorder_traversal(Node* root) const {
    if(!root){
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}
template<typename T>
void AVLTree<T>::preorder_traversal(Node* root) const {
    if(!root){
        return;
    }
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
template<typename T>
void AVLTree<T>::postorder_traversal(Node* root) const {
    if(!root){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}

template<typename T>
void AVLTree<T>::levelorder_traversal(Node* root) const {
    if(!root)return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            Node* top = q.front();
            cout << top->data << " ";
            q.pop();
            if(top->left)q.push(top->left);
            if(top->right)q.push(top->right);
        }
        cout << endl;
    }
    cout << endl;
}

template <typename T>
void AVLTree<T>::insert(const T& value, Node*& root){
    if(!root){
        root = new Node(value);
    }
    if(root->data > value) {
        insert(value,root->left);
    }
    if(root->data < value) {
        insert(value,root->right);
    }
    int bf = get_balance(root);
    if(abs(bf) > 1){
        root = do_rotation(root);
    }
}


template <typename T>
bool AVLTree<T>::contains(const T& value, Node* root) const{
    if(!root){
        return false;
    }
    if(root->data > value) {
        return contains(value, root->left);
    }
    else if(root->data < value) {
        return contains(value, root->right);
    }
    return true;
}


template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::find_max(Node* root) const {
    if(!root){
        return nullptr;
    }
    if(!root->right){
        return root;
    }
    return find_max(root->right);
}


template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::find_min(Node* root) const {
    if(!root){
        return nullptr;
    }
    if(!root->left){
        return root;
    }
    return find_min(root->left);
}


template <typename T>
void AVLTree<T>::remove(const T& value, Node*& root) {
    if(!root){
        return;
    }
    if(root->data > value) {
        remove(value, root->left);
    }
    else if(root->data < value) {
        remove(value, root->right);
    }

    else{
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if(root->left != nullptr || root->right != nullptr){
            root->data = find_min(root->right)->data;
            remove(root->data, root->right);
        }
    }
}


template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::clone(Node* node_ptr) const {
    Node* tmp = nullptr;
    if (node_ptr == nullptr){return tmp;}
    
    tmp = new Node(node_ptr->data);
    tmp->left = clone(node_ptr->left);
    tmp->right = clone(node_ptr->right);
    return tmp;
}


template <typename T>
void AVLTree<T>::clear(Node*& root) noexcept { 
    if(root) {
        clear(root->left);
        clear(root->right);
        delete root;
    }
    root = nullptr;
}


//rotations

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::right_rotate(Node* root) {
    Node* b = root->left;
    Node* T2 = b->right;
    
    b->right = root;
    root->left = T2;
    
    return b;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::right_left_rotate(Node* root) {
    root->right = right_rotate(root->right);
    root = left_rotate(root);
    return root;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::left_rotate(Node* root) {
    Node* b = root->right;
    Node* T2 = b->left;

    b->left = root;
    root->right = T2;

    return b;
}
template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::left_right_rotate(Node* root) {
    root->left = left_rotate(root->left);
    root = right_rotate(root);
    return root;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::do_rotation(Node* root) {
    if (root == nullptr){
        return nullptr;
    }
    int bf = get_balance(root);
    if (bf > 1){
        if (get_balance(root->left) >= 0){
            root = right_rotate(root);
        }
        else {
            root = left_right_rotate(root);
        }
    }
    if (bf < -1){
        if (get_balance(root->right) <= 0){
            root = left_rotate(root);
        }
        else {
            root = right_left_rotate(root);
        }
    }
    return root;
}


template <typename T>
unsigned int AVLTree<T>::count(const Node* root) const {
    if (root == nullptr){
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}

template <typename T>
void AVLTree<T>::merge(Node*& obj1, const Node* obj2){
    if (obj2 == nullptr){
        return;
    }
    if (obj1 == nullptr){
        obj1 = new Node(obj2->data);
    }
    merge(obj1, obj2->left);
    insert(obj2->data, obj1);
    merge(obj1,obj2->right);
    insert(obj2->data, obj1);
}

template <typename T>
vector<vector<T>> AVLTree<T>::allpaths(Node* node){
    vector<vector<T>> paths;
    vector<T> currentPath;

    allPathsRecursive(root, currentPath, paths);

    return paths;
}

template <typename T>
void AVLTree<T>::allPathsRecursive(Node* node, vector<T>& currentPath, vector<vector<T>>& paths) {
    if (node == nullptr) {
        return;
    }
    currentPath.push_back(node->data);

    if (node->left == nullptr && node->right == nullptr) {
        paths.push_back(currentPath);
    }
    allPathsRecursive(node->left, currentPath, paths);
    allPathsRecursive(node->right, currentPath, paths);

    currentPath.pop_back();
}
