#include "frw_list.hpp"
template <typename T>
ams::frw_list<T>& ams::frw_list<T>::operator=(const frw_list<T>& fl) {
    this -> clear();
    if(fl.head == nullptr) {
        return *this;
    }
    head = new Node(fl.head -> value);
    Node* curr1 = fl.head;
    Node* curr2 = head;
    while(curr1 -> next != nullptr) {
        curr2 -> next = new Node(*curr1 -> next);
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
    return *this;
}

template <typename T>
void ams::frw_list<T>::clear() noexcept {
    while(head) {
        Node* tmp = head;
        head = head -> next;
        delete tmp;
        tmp = nullptr;
    }
    
}

template <typename T>
ams::frw_list<T>& ams::frw_list<T>::operator=(frw_list<T>&& fl) {
    this -> clear();
    head = fl.head;
    fl.head = nullptr;
    return *this;
}

template <typename T>
ams::frw_list<T>& ams::frw_list<T>::operator=(std::initializer_list<T> init) {
    auto begin = init.begin();
    auto end = init.end();
    if(begin == end) {
        return *this;
    }
    head = new Node(*(begin++));
    Node* curr = head;
    while(begin != end) {
        curr -> next = new Node(*(begin++));
        curr = curr -> next;
    }
    return *this;
}

template <typename T>
void ams::frw_list<T>::swap(frw_list<T>& fl) noexcept {
    Node* tmp = head;
    head = fl.head;
    fl.head = tmp;
}

template <typename T>
const T& ams::frw_list<T>::front() const {
    return head -> value;
}

template <typename T>
bool ams::frw_list<T>::empty() const {
    return head == nullptr;
}

template <typename T>
size_t ams::frw_list<T>::size() {
    size_t value = 0;
    Node* curr = head;
    while(curr != nullptr) {
        ++value;
        curr = curr -> next;
    }
    return value;
}

template <typename T>
void ams::frw_list<T>::push_front(const T& val) {
    Node* curr = head;
    curr = new Node(val);
    curr -> next = head;
    head = curr;
}

template <typename T>
void ams::frw_list<T>::insert(size_t pos, const T& value) {
    if(static_cast<int>(pos) < 0 or pos > size())
        throw std::invalid_argument("");
    
    if(pos == 0) {
        push_front(value);
        return;
    }
    
    Node* curr = head;
    size_t size{};
    while(size != pos and curr->next != nullptr) {
        ++size;
        curr = curr -> next;
    }
    Node* tmp = new Node(value, curr -> next);
    curr -> next = tmp;
    tmp = nullptr;
}

template <typename T>
void ams::frw_list<T>::pop_front() {
    if(head){
        Node* tmp = head;
        head = head -> next;
        delete tmp;
        tmp = nullptr;
    }
    else{
        throw std::runtime_error("Dereferencing a null pointer.");
    }
}

template <typename T>
void ams::frw_list<T>::insert(size_t pos, size_t count, const T& value) {
    if(static_cast<int>(pos) < 0 or pos > size())
        throw std::invalid_argument("");
    
    if(static_cast<int>(count) < 0)
        throw std::invalid_argument(" ");
     
    while(count--) {
        insert(pos, value);
    }
}

template <typename T>
void ams::frw_list<T>::erase(size_t pos) {
    
    if (static_cast<int>(pos) < 0 or pos > size())
        throw std::invalid_argument(" ");

    if (!head) return;
    
    if(0 == pos){
        clear();
        return;
    }
    
//    std::cout << head->value << std::endl;
    Node* current = head;
            int index = 0;

            while (index < pos - 1) {
                current = current->next;
                index++;
            }
            while (current->next) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
    
}

template <typename T>
void ams::frw_list<T>::sort() {
    Node* start = new Node();
    start -> next = head;
    Node* curr = head;
    Node* prev = start;
    while(curr != nullptr) {
        if(curr -> next && curr -> next -> value < curr -> value) {
            while(prev -> next && prev -> next -> value < curr -> next -> value) {
                prev = prev -> next;
            }
            auto tmp = prev -> next;
            prev -> next = curr -> next;
            curr -> next = curr -> next -> next;
            prev -> next -> next = tmp;
            prev = start;
        }
        else {
            curr = curr -> next;
        }
    }
    head = start -> next;
}

template <typename T>
void ams::frw_list<T>::reverse() {
    Node* curr = head;
    Node* prev = nullptr;
    while(curr != nullptr) {
        Node* next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template <typename T>
void ams::frw_list<T>::print() const {
    Node* curr = head;
    while(curr){
        std::cout << curr->value << " ";
        curr = curr->next;
    }
    
    
}


template <typename T>
bool ams::frw_list<T>::operator==(const frw_list<T>& fl) const {
    Node* curr1 = head;
    Node* curr2 = fl.head;
    while(curr1 != nullptr && curr2 != nullptr) {
        if(curr1 -> value != curr2 -> value) {
            return false;
        }
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
    if(curr1 != nullptr || curr2 != nullptr) {
        return false;
    }
    return true;
}

template <typename T>
bool ams::frw_list<T>::operator!=(const frw_list<T>& fl) const {
    return !(*this == fl);
}

template <typename T>
bool ams::frw_list<T>::operator<(const frw_list<T>& fl) const {
    Node* curr1 = head;
    Node* curr2 = fl.head;
    if (curr1 && !curr2) {
        return false;
    }
    if (!curr1 && curr2) {
        return false;
    }
    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1 -> value > curr2 -> value) {
            return false;
        }
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
    return true;
}

template <typename T>
bool ams::frw_list<T>::operator<=(const frw_list<T>& fl) const {
    return (*this == fl) || (*this < fl);
}

template <typename T>
bool ams::frw_list<T>::operator>(const frw_list<T>& fl) const {
    return !(this->operator<(fl));
}

template <typename T>
bool ams::frw_list<T>::operator>=(const frw_list<T>& fl) const {
    return (*this == fl) || (*this > fl);
}
