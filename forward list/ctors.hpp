#include "frw_list.hpp"
template <typename T>
ams::frw_list<T>::frw_list() : head{nullptr} {}

template <typename T>
ams::frw_list<T>::frw_list(size_t count) {
    head = new Node();
    Node* curr = head;
    for(int i = 0; i < count - 1; ++i) {
        curr -> next = new Node;
        curr = curr -> next;
    }
}

template <typename T>
ams::frw_list<T>::frw_list(size_t count, T value) {
    head = new Node(value);
    Node* curr = head;
    for(int i = 0; i < count - 1; ++i) {
        curr -> next = new Node(value);
        curr = curr -> next;
    }
}

template <typename T>
ams::frw_list<T>::frw_list(const frw_list<T>& oth) {
    if(oth.head == nullptr) {
        return;
    }
    head = new Node(oth.head -> value);
    Node* curr1 = oth.head -> next;
    Node* curr2 = head;
    while(curr1 != nullptr) {
        curr2 -> next = new Node(curr1 -> value);
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
}

template <typename T>
ams::frw_list<T>::frw_list(frw_list<T>&& oth) {
    head = oth.head;
    delete oth.head;
}

template <typename T>
ams::frw_list<T>::frw_list(std::initializer_list<T> init) {
    auto begin = init.begin();
    auto end = init.end();
    if(begin == end) {
        return;
    }
    head = new Node(*(begin++));
    Node* curr = head;
    while(begin != end) {
        curr -> next = new Node(*(begin++));
        curr = curr -> next;
    }
}

template <typename T>
ams::frw_list<T>::~frw_list() {
    while (head) {
        head = head -> next;
    }
    head = nullptr;
}

