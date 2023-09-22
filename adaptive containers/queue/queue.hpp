#include "queue_class.h"
template <typename T>
Queue<T>::Queue(){
    head = nullptr;
    tail = nullptr;
    m_size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue& other){
    m_size = other.m_size;
    if (other.head == nullptr) {
        head = nullptr;
        return;
    }
    
    head = new Node(other.head->val);
    Node* current = head;
    Node* otherCurrent = other.head->next;
    
    while (otherCurrent) {
        current->next = new Node(otherCurrent->val);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    tail = current;
    tail->next = nullptr;
}

template <typename T>
Queue<T>::Queue(Queue&& rhs){
    head = rhs.head;
    rhs.head = nullptr;
    tail = rhs.tail;
    rhs.tail = nullptr;
    m_size = rhs.m_size;
    rhs.m_size = 0;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
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
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        tail = current;
        tail->next = nullptr;
    }
    return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& rhs) {
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
Queue<T>::~Queue(){
    while(head){
        pop();
    }
    tail = nullptr;
}

template <typename T>
void Queue<T>::push(const T& val) noexcept{
    if(!head){
        head = new Node(val);
        tail = head;
        m_size++;
    }
    else {
        tail -> next = new Node(val);
        tail = tail->next;
        tail->next = nullptr;
        m_size++;
    }
}

template <typename T>
void Queue<T>::push(T&& val) noexcept{
    if(!head){
        head = new Node(val);
        tail = head;
        m_size++;
    }
    else {
        tail -> next = new Node(val);
        tail = tail->next;
        tail->next = nullptr;
        m_size++;
    }
}

template <typename T>
void Queue<T>::pop() {
    if(head == nullptr){
        throw std::runtime_error("");
    }
    Node* tmp = head;
    head = head->next;
    delete tmp;
    tmp = nullptr;
    m_size--;
}

template <typename T>
const T& Queue<T>::front() const{
    if(head == nullptr){
        throw std::runtime_error("");
    }
    return head->val;
}
template <typename T>
const T& Queue<T>::back() const{
    if(head == nullptr){
        throw std::runtime_error("");
    }
    return tail->val;
}

template <typename T>
unsigned int Queue<T>::size() const noexcept{
    if(head == nullptr){
        return 0;
    }
    return m_size;
}

template <typename T>
bool Queue<T>::empty() const noexcept{
    if(0 == m_size){
        return true;
    }
    return false;
}

template <typename T>
void Queue<T>::swap(Queue<T>& rhs) {
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    std::swap(m_size, rhs.m_size);
}

