#include "list_class.hpp"
template<typename T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
List<T>::List(const List& other) {
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

template<typename T>
List<T>::List(std::initializer_list<T> init)  : head(nullptr), tail(nullptr) {
    for (const T& elem : init) {
        push_back(elem);
    }
}
template<typename T>
List<T>::~List() {
    clear();
}


template<typename T>
void List<T>::push_back(const T& elem) noexcept{
    if(head == nullptr){
        head = new Node(elem);
        tail = head;
        return;
    }
    
    tail->next = new Node(elem);
    tail->next->prev = tail;
    tail = tail->next;
    tail->next = nullptr;
}

template<typename T>
void List<T>::push_back(T&& elem) noexcept{
    if(head == nullptr){
        head = new Node(elem);
        tail = head;
        tail->next = nullptr;
        tail->prev = nullptr;
        return;
    }
    
    tail->next = new Node(elem);
    tail->next->prev = tail;
    tail = tail->next;
    tail->next = nullptr;
}

template<typename T>
void List<T>::pop_back() {
    if (head == nullptr) {
        throw std::runtime_error("");
    }
    
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    
    tail = tail -> prev;
    delete tail->next;
    tail -> next = nullptr;
}


template<typename T>
void List<T>::print() const noexcept {
    Node* curr = head;
    while(curr) {
        std::cout << curr -> val << " ";
        curr = curr -> next;
    }
    std::cout << std::endl;
}


template<typename T>
void List<T>::insert(const T& elem, int pos) {
    if(pos < 0 or pos > size())
        throw std::invalid_argument("");
    
    if (pos == size()) {
        push_back(elem);
        return;
    }
    if (pos == 0) {
        push_front(elem);
        return;
    }
    
    Node* node = new Node(elem);
    if(pos <= size()/2){
        Node* curr = head;
        for (int i = 0; i < pos; ++i) {
            curr = curr->next;
        }
        node->next = curr;
        node->prev = curr->prev;
        curr->prev->next = node;
        curr->prev = node;
    }
    else if(pos > size()/2){
        Node* curr = tail;
        for (int i = 0; i < size() - pos - 1; ++i) {
            curr = curr->prev;
        }
        node->next = curr;
        node->prev = curr->prev;
        curr->prev->next = node;
        curr->prev = node;
    }
}

template<typename T>
void List<T>::insert(T&& elem, int pos) {
    if(pos < 0 or pos > size())
        throw std::invalid_argument("");
    
    if (pos == size()) {
        push_back(elem);
        return;
    }
    if (pos == 0) {
        push_front(elem);
        return;
    }
    
    Node* node = new Node(elem);
    if(pos <= size()/2){
        Node* curr = head;
        for (int i = 0; i < pos; ++i) {
            curr = curr->next;
        }
        node->next = curr;
        node->prev = curr->prev;
        curr->prev->next = node;
        curr->prev = node;
    }
    else if(pos > size()/2){
        Node* curr = tail;
        for (int i = 0; i < size() - pos - 1; ++i) {
            curr = curr->prev;
        }
        node->next = curr;
        node->prev = curr->prev;
        curr->prev->next = node;
        curr->prev = node;
    }
}

template<typename T>
void List<T>::push_front(const T& elem) noexcept {
    Node* front = new Node(elem);
    front->prev = nullptr;
    front->next = head;
    head->prev = front;
    head = front;
}

template<typename T>
void List<T>::push_front(T&& elem) noexcept {
    Node* front = new Node(elem);
    front->prev = nullptr;
    front->next = head;
    head->prev = front;
    head = front;
}


template<typename T>
size_t List<T>::size() const noexcept {
    size_t size = 0;
    Node* curr = head;
    while (curr) {
        size++;
        curr = curr -> next;
    }
    return size;
}


template<typename T>
int List<T>::front() const {
    if(head == nullptr)
        throw std::runtime_error("");
    
    return head->val;
}


template<typename T>
int List<T>::back() const {
    if(head == nullptr)
        throw std::runtime_error("");
    
    return tail->val;
}


template<typename T>
void List<T>::clear() noexcept{
    if(head == nullptr){
        return;
    }
    while (tail != nullptr) {
        Node* tmp = tail;
        tail = tail->prev;
        delete tmp;
    }
    head = nullptr;
    tail = nullptr;
}


template<typename T>
void List<T>::resize(int new_size) {
    if (new_size < size()) return;
    
    for (int i = 0; i < new_size; ++i) {
        push_back(0);
    }
}


template<typename T>
void List<T>::erase(int pos1, int pos2) {
    if (head == nullptr)
        throw std::runtime_error("");
    
    if(pos1 < 0 or pos1 >= size() or pos2 >= size() or pos2 < 0 or pos2 < pos1 )
        throw std::invalid_argument("");
    
    if(pos2 - pos1 == size() - 1){
        clear();
        return;
    }
    if (pos1 == 0) {
        for (int i = 0; i < pos2 + 1; ++i) {
            pop_front();
        }
        return;
    }
    if(pos2 == size() - 1){
        for (int i = 0; i < pos2 - pos1 + 1; ++i) {
            pop_back();
        }
        return;
    }
    
    Node* curr = head;
    for (int i = 0; i < pos1; ++i) {
        curr = curr -> next;
    }
    for(int i = pos1; i <= pos2; ++i){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        Node* tmp = curr;
        curr = curr->next;
        tmp->prev = nullptr;
        tmp->next = nullptr;
        delete tmp;
        tmp = nullptr;
    }
    
    
    
}


template<typename T>
void List<T>::pop_front() {
    if(head == nullptr)
        throw std::runtime_error("");
    
    Node* tmp = head;
    head = head -> next;
    head->prev = nullptr;
    delete tmp;
    tmp = nullptr;
}

template<typename T>
void List<T>::erase(int pos1) {
    int pos2 = size() - 1;
    erase(pos1, pos2);
}

template<typename T>
T List<T>::data(int pos) {
    if(head == nullptr)
        throw std::runtime_error("");
    if(pos < 0 or pos >= size())
        throw std::invalid_argument("");
    Node* curr = head;
    for (int i = 0; i < pos; ++i) {
        curr = curr -> next;
    }
    return curr -> val;
}

template<typename T>
bool List<T>::empty() const noexcept{
    return 0 == size();
}
