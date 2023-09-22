#ifndef QUE_H
#define QUE_H

#include <iostream>
using namespace std;
template <typename T>
class Queue {
public:
    Queue();
    Queue(const Queue&);
    Queue(Queue&&);
    ~Queue();
    
    Queue& operator=(const Queue&);
    Queue& operator=(Queue&&);
    
    friend ostream& operator<<(ostream& os, const Queue<T>& obj){
        auto x = obj.head;
        for (; x != nullptr; x = x->next) {
            os << x->val << " ";
        }
        return os;
    }
    
public:
    unsigned int size() const noexcept;
    bool empty() const noexcept;
    void push(const T&) noexcept;
    void push(T&&) noexcept;
    void pop();
    
    const T& front() const;
    const T& back() const;
    
    void swap(Queue&);
private:
    struct Node {
        Node(const T& v) : val{v} {}
        T val;
        Node* next;
    }*head,*tail;
    
    size_t m_size;
};


#endif // QUE_H

