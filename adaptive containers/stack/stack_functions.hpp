#include "stack_class.h"
template <typename T>
Stack<T>::Stack(){
    head = nullptr;
    tail = nullptr;
    m_size = 0;
}

template <typename T>
Stack<T>::Stack(const Stack& other){
    if (head == nullptr) {
        head = nullptr;
        return;
    }

    // Copy elements from the other stack to create a new stack
    head = new Node(other.head->val);
    Node* current = head;
    Node* otherCurrent = other.head->next;
    
    while (otherCurrent) {
        current->next = new Node(otherCurrent->val);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}

template <typename T>
Stack<T>::Stack(Stack&& rhs){
    head = std::move(rhs.head);
    tail = std::move(rhs.tail);
    m_size = rhs.m_size;
    rhs.m_size = 0;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& obj) {
    if (this != &obj) {
        if (!obj.head) {
            return *this;
        }
        head = new Node(obj.head->val);
        Node* tmp1 = head;
        Node* tmp2 = obj.head->next;
        while (tmp2) {
            tmp1->next = new Node(tmp2->val);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
            tail = tmp1;
        }
    }
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& rhs) {
    if (this != &rhs) {
        head = std::move(rhs.head);
        tail = std::move(rhs.tail);
        m_size = rhs.m_size;
        rhs.m_size = 0;
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack(){
//    while(m_size--){
//        cout << 88 << endl;
//        pop();
//    }
//    tail = nullptr;
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
        throw 404;
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
        throw 404;
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
    if(0 == m_size){
        return true;
    }
    return false;
}

template <typename T>
void Stack<T>::swap(Stack<T>& rhs) {
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    std::swap(m_size, rhs.m_size);
}
