#ifndef __FORWARD_LIST__H
#define __FORWARD_LIST__H
#include <iostream>
namespace ams{

template <typename T>
class frw_list {
    
private:
    
    class Node {
    public:
        Node() : value{} , next {nullptr} {}
        Node(T val) : value{val} , next{nullptr} {}
        Node(T val, Node* ptr) : value{val} , next{ptr} {}
        
        T value;
        Node* next;
    };
    Node* head;
    
public:

    frw_list();
    frw_list(size_t);
    frw_list(size_t, T);
    frw_list(const frw_list&);
    frw_list(frw_list&&);
    frw_list(std::initializer_list<T>);
    ~frw_list();

    frw_list& operator = (const frw_list&);
    frw_list& operator = (frw_list&&);
    frw_list& operator = (std::initializer_list<T>);

public:
    void clear() noexcept;
    void swap(frw_list&) noexcept;
    const T& front() const;
    bool empty() const;
    size_t size();
    void insert(size_t, const T&);
    void insert(size_t, size_t, const T&);
    void erase(size_t);
    void push_front(const T&);
    void pop_front();
    void sort(); //Insertion Sort
    void reverse();
    void print() const;

    bool operator == (const frw_list&) const;
    bool operator != (const frw_list&) const;
    bool operator <  (const frw_list&) const;
    bool operator >  (const frw_list&) const;
    bool operator <= (const frw_list&) const;
    bool operator >= (const frw_list&) const;

public:
    friend std::ostream& operator << (std::ostream& os, const frw_list<T>& f1) {
        Node* tmp = f1.head;
        while(tmp) {
            os << tmp -> value << " -> ";
            tmp = tmp -> next;
        }
        return os;
    }

public:
    
class frw_iterator {
    
private:
    Node* iterator;
public:
    
    frw_iterator() {iterator = nullptr;}
    frw_iterator(Node* ptr) {iterator = ptr;}
    T& operator*() const {return iterator -> value;}
    T* operator ->() {return &(iterator -> value);}
    frw_iterator& operator++() {
        iterator = iterator -> next;
        return *this;
    }
    frw_iterator operator++(int) {
        frw_iterator tmp(iterator);
        iterator = iterator -> next;
        return tmp;
    }
    bool operator ==(const frw_iterator& oth) {return iterator == oth.iterator;}
    bool operator !=(const frw_iterator& oth) {return !(*this == oth);}
};

public:
    frw_iterator begin() noexcept {return frw_iterator(head);}
    frw_iterator end() const noexcept {return frw_iterator(nullptr);}
};
}

#endif /*__FORWARD_LIST__H*/
