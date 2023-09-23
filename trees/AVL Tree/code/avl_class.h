#ifndef AVL_H
#define AVL_H

#include <initializer_list>
#include <iostream>
using namespace std;
template <typename T>
class AVLTree {
public:
    AVLTree();
    AVLTree(const AVLTree&);
    AVLTree(AVLTree&&);
    AVLTree(T);
    AVLTree(std::initializer_list<T>);
    ~AVLTree();
    AVLTree& operator=(const AVLTree&);
    AVLTree& operator=(AVLTree&&);
    friend std::ostream& operator<<(std::ostream& os, const AVLTree& obj)
    {
        cout << "inorder: ";
        obj.inorder_traversal();
        return os;
    }
    
public:
    int get_height() const;
    void insert(const T&);
    void remove(const T&);
    bool contains(const T&) const;
    unsigned int count() const;
    bool is_empty() const;
    void merge(const AVLTree&);
    
    const T& find_min() const;
    const T& find_max() const;

    void inorder_traversal() const;
    void preorder_traversal() const;
    void postorder_traversal() const;
    void levelorder_traversal() const;
    
    void clear();
    
    vector<vector<T>> allpaths();
private:
    struct Node {
        Node* left;
        Node* right;
        T data;
        Node(){
            left = nullptr;
            right  = nullptr;
        }
        Node(T data){
            left = nullptr;
            right  = nullptr;
            this->data = data;
        }
    }*root;
    
    int get_balance(const Node*) const;
    int get_height(const Node*) const;
    
    void inorder_traversal(Node*) const;
    void preorder_traversal(Node*) const;
    void postorder_traversal(Node*) const;
    void levelorder_traversal(Node*) const;
    
    bool contains(const T&, Node*) const;
    unsigned int count(const Node*) const;
    void insert(const T&, Node*&);
    void remove(const T&, Node*&);
    
    Node* find_min(Node*) const;
    Node* find_max(Node*) const;
    
    void clear(Node*&) noexcept;
    bool is_empty(Node*) const;
    
    Node* right_rotate(Node*);
    Node* left_rotate(Node*);
    Node* right_left_rotate(Node*);
    Node* left_right_rotate(Node*);
    Node* do_rotation(Node*);
    
    Node* clone(Node*) const;
    void merge(Node*& obj1, const Node* obj2);
    
    vector<vector<T>> allpaths (Node*);
    void allPathsRecursive(Node*, vector<T>&, vector<vector<T>>&);
};


#endif // AVL_H
