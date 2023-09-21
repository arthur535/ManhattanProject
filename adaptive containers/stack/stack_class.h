#ifndef STCK_H
#define STCK_H

#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
    Stack();
    Stack(const Stack&);
    Stack(Stack&&);
    ~Stack();
    
    Stack& operator=(const Stack&);
    Stack& operator=(Stack&&);
    
    friend ostream& operator<<(ostream& os, const Stack<T>& obj){
        auto x = obj.tail;
        for (; x != nullptr; x = x->prev) {
            os << x->value << " ";
        }
        return os;
    }
    
public:
    unsigned int size() const;
    bool empty() const;
    void push(const T&);
    void push(T&&);
    void pop();
    const T& top() const;
    void swap(Stack&);
    
private:
    struct Node {
        Node(const T& v) : val{v} {}
        T val;
        Node* next;
        Node* prev;
    }*head,*tail;
    
    unsigned int m_size;
};

#endif // STCK_H
