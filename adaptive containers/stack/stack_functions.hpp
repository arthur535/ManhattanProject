#include "stack_class.h"
template <typename T>
Stack<T>::Stack(){
    head = nullptr;
    tail = nullptr;
    m_size = 0;
}

template <typename T>
Stack<T>::Stack(const Stack& other){
    m_size = other.m_size;
    if (other.head == nullptr) {
        head = nullptr;
        tail = nullptr;
        return;
    }
    
    head = new Node(other.head->val);
    Node* current = head;
    Node* otherCurrent = other.head->next;
    
    while (otherCurrent) {
        current->next = new Node(otherCurrent->val);
        current->next->prev = current;
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    tail = current;
    tail->next = nullptr;
    head->prev = nullptr;
}

template <typename T>
Stack<T>::Stack(Stack&& rhs){
    head = rhs.head;
    rhs.head = nullptr;
    tail = rhs.tail;
    rhs.tail = nullptr;
    m_size = rhs.m_size;
    rhs.m_size = 0;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
    if (this != &other) {
        if (!other.head) {
            return *this;
        }
        m_size = other.m_size;
        
        head = new Node(other.head->val);
        Node* current = head;
        Node* otherCurrent = other.head->next;
        
        while (otherCurrent) {
            current->next = new Node(otherCurrent->val);
            current->next->prev = current;
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        tail = current;
        tail->next = nullptr;
        head->prev = nullptr;
    }
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& rhs) {
    if (this != &rhs) {
        head = rhs.head;
        rhs.head = nullptr;
        tail = rhs.tail;
        rhs.tail = nullptr;
        m_size = rhs.m_size;
        rhs.m_size = 0;
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack(){
    while(m_size--){
        pop();
    }
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void Stack<T>::push(const T& val) {
    if(!head){
        head = new Node(val);
        tail = head;
        head->next = nullptr;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = nullptr;
        m_size++;
    }
    else {
        tail -> next = new Node(val);
        Node* tmp = tail;
        tail = tail->next;
        tail->prev = tmp;
        tmp = nullptr;
        tail->next = nullptr;
        m_size++;
    }
}

template <typename T>
void Stack<T>::push(T&& val) {
    if(!head){
        head = new Node(val);
        tail = head;
        head->next = nullptr;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = nullptr;
        m_size++;
    }
    else {
        tail->next = new Node(val);
        tail->next->next = nullptr;
        Node* tmp = tail;
        tail = tail->next;
        tail->prev = tmp;
        tmp = nullptr;
        m_size++;
    }
}

template <typename T>
void Stack<T>::pop() {
    if(head == nullptr){
        throw std::runtime_error("");
    }
    Node* tmp = tail;
    tail = tail->prev;
    delete tmp;
    tmp = nullptr;
    m_size--;
}

template <typename T>
const T& Stack<T>::top() const{
    if(head == nullptr){
        throw std::runtime_error("");
    }
    return tail->val;
}

template <typename T>
unsigned int Stack<T>::size() const{
    if(head == nullptr){
        return 0;
    }
    return m_size;
}

template <typename T>
bool Stack<T>::empty() const{
    return 0 == m_size;
}

template <typename T>
void Stack<T>::swap(Stack<T>& rhs) {
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    std::swap(m_size, rhs.m_size);
}
