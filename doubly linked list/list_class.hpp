#ifndef LIST_H_
#define LIST_H_
#include <iostream>
template<typename T>
class List {
    
private:
    struct Node {
        Node(T v) : val(v){};
        Node* prev;
        T val;
        Node* next;
    }*head,*tail;
    

public:
    List();
    List(const List&);
    List(List&&);
    List(std::initializer_list<T>);
    ~List();

    List& operator=(const List&);
    List& operator=(List&&);
    
    void push_back(const T&) noexcept;
    void push_back(T&&) noexcept;
    void pop_back();
    void print() const noexcept;
    void push_front(const T&) noexcept;
    void push_front(T&&) noexcept;
    void pop_front();
    void insert(const T&, int);
    void insert(T&&, int);
    void erase(int, int);
    void erase(int);
    size_t size() const noexcept;
    bool empty() const noexcept;
    int front() const;
    int back() const;
    void clear() noexcept;
    void resize(int);
    T data(int);
};

#endif // LIST_H_
