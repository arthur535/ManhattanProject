#ifndef BST_H
#define BST_H
#include <vector>
#include <string>
using namespace std;
template<typename T>
class BSTree {
public:
    
    
    BSTree();
    BSTree(const BSTree&);
    BSTree(BSTree&&);
    ~BSTree();
    BSTree(std::initializer_list<T>);
    
    void inorder_traversal() const;
    void preorder_traversal() const;
    void postorder_traversal() const;
    void levelorder_traversal() const;
    
    uint get_height() const;
    
    const T& find_min() const;
    const T& find_max() const;
    
    BSTree& operator=(const BSTree&);
    BSTree& operator=(BSTree&&);
    
    bool contains(const T&) const;
    bool contains(T&&) const;
    bool is_empty() const;
    
    void clear() noexcept;
    
    void insert(const T&);
    void insert(T&&);
    void remove(const T&);
    
    T get_predecessor(const T&);
    T get_successor(const T&);
    
    T get_predecessor(T&&);
    T get_successor(T&&);
    
    
private:
    struct Node {
        Node(T v,Node* l,Node* r){
            val = v;
            left = l;
            right = r;
        }
        Node(T v = T()){
            val = v;
            left = nullptr;
            right = nullptr;
        }
        
        T val;
        Node* left;
        Node* right;
        
    }* root = nullptr;
    
private:
    void inorder_traversal(Node*) const;
    void preorder_traversal(Node*) const;
    void postorder_traversal(Node*) const;
    void levelorder_traversal(Node*) const;
    
    uint get_height(Node*) const;
    
    Node* clone(Node*) const;
    
    Node* contains(const T&, Node*) const;
    void insert(const T&, Node*&);
    void remove(const T&, Node*&);
    
    Node* find_min(Node*) const;
    Node* find_max(Node*) const;
    
    void destruct(Node*&) noexcept;
    bool is_empty(Node*) const;
    
    BSTree::Node* GetNewNode(T data) {
        BSTree::Node* newNode = new Node();
        newNode->val = data;
        newNode->left = nullptr;
        newNode->right = nullptr ;
        return newNode;
    }
    
    Node* get_predecessor(Node*) const;
    Node* get_successor(Node*) const;
    
private:
    void add(string& str, int val){
        str += "->";
        str.push_back(val+48);
    }
    
    vector<string> binaryTreePaths(Node* root) {
        vector<string> res;
        if(!root)return res;
        
            
        string str = " ";
        str += char(root->val + 48);
        
        binaryTreePaths(root->left);
        binaryTreePaths(root->right);
        add(str,root->val);
        res.push_back(str);
        return res;
    }
public:
    vector<string> binaryTreePaths() {
        return binaryTreePaths(root);
    }
    
    
    void printPaths(Node* node, vector<int>& currentPath) {
        if (!node) {
            return ;
        }

        // Add the current node to the path.
        currentPath.push_back(node->val);
        string str{};
        // If it's a leaf node, print the current path.
        if (!node->left && !node->right) {
            cout << "Path: ";
            for (int value : currentPath) {
                cout << value << " ";
            }
            cout << endl;
        } else {
            // Recursively explore left and right subtrees.
            printPaths(node->left, currentPath);
            printPaths(node->right, currentPath);
        }

        // Backtrack by removing the current node from the path.
        currentPath.pop_back();
    }

    void printAllPaths() {
//        cout << root << endl;
//        cout << root->left->val;
        vector<int> currentPath;
        printPaths(root, currentPath);
    }
    
};

#endif // BST_H
