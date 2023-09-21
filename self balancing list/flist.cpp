#include <iostream>
#include "flist_class.h"
using namespace std;

template <typename T>
FList<T>::FList(){
    head = nullptr;
    tail = nullptr;
    aschead = nullptr;
    deschead = nullptr;
}; // deafult ctor


template <typename T>
FList<T>::FList(std::initializer_list<T> init){
    auto begin = init.begin();
    auto end = init.end();
    if(begin == end) {
        return;
    }
    ListNode* headnode = new ListNode(*(begin++));
    m_size++;
    
    head = headnode;
    aschead = headnode;
    deschead = headnode;
    tail = headnode;
        
    ListNode* curr = head;
    while(begin != end) {
        m_size++;
        ListNode* currnode = new ListNode(*(begin++));
        curr->next = currnode;
        currnode->prev = curr;
        curr = curr -> next;
        put_in_sorted_order(currnode);
        tail = curr;
    }
} // initializer list ctor


template <typename T>
FList<T>::FList(const FList& oth){
    if(oth.head == nullptr) {
        return;
    }
    m_size = oth.m_size;
    head = new ListNode(oth.head -> data);
    aschead = head;
    deschead = head;
    tail = head;
    ListNode* curr1 = oth.head -> next;
    ListNode* curr2 = head;
    while(curr1 != nullptr) {
        ListNode* n = new ListNode(curr1 -> data);
        put_in_sorted_order(n);
        curr2 -> next = n;
        n->prev = curr2;
        tail = n;
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
} // copy ctor


template <typename T>
FList<T>::FList(FList&& rhs){
    if(rhs.head == nullptr) {
        return;
    }
    
    m_size = rhs.m_size;
    head = rhs.head;
    tail = rhs.tail;
    deschead = rhs.deschead;
    aschead = rhs.aschead;
    
    rhs.head = nullptr;
    rhs.tail= nullptr;
    rhs.deschead = nullptr;
    rhs.aschead = nullptr;
    
} // move ctor


template <typename T>
FList<T>::~FList(){
    clean();
}


template <typename T>
bool FList<T>::operator==(const FList& flist) const{
    ListNode* curr1 = head;
    ListNode* curr2 = flist.head;

    while (curr1 && curr2) {
        if (curr1->data != curr2->data) {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return (curr1 == nullptr && curr2 == nullptr);
}


template <typename T>
FList<T>& FList<T>::operator=(const FList& oth){
    if(oth.head == nullptr) {
        return *this;
    }
    m_size = oth.m_size;
    head = new ListNode(oth.head -> data);
    aschead = head;
    deschead = head;
    tail = head;
    ListNode* curr1 = oth.head -> next;
    ListNode* curr2 = head;
    while(curr1 != nullptr) {
        ListNode* n = new ListNode(curr1 -> data);
        put_in_sorted_order(n);
        curr2 -> next = n;
        n->prev = curr2;
        tail = n;
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
    return *this;
} // copy assignment operator


template <typename T>
FList<T>& FList<T>::operator=(FList&& rhs){
    if(rhs.head == nullptr) {
        return *this;
    }
    
    m_size = rhs.m_size;
    head = rhs.head;
    tail = rhs.tail;
    deschead = rhs.deschead;
    aschead = rhs.aschead;
    
    rhs.head = nullptr;
    rhs.tail= nullptr;
    rhs.deschead = nullptr;
    rhs.aschead = nullptr;
    
    return *this;
} // move assignment operator


template <typename T>
void FList<T>::operator+=(FList& fl1) {
    merge(fl1);
    m_size += fl1.size();
        
    fl1.head->prev = nullptr;
    fl1.tail->next = nullptr;

    tail->next = fl1.head;
    fl1.head->prev = tail;
    tail = fl1.tail;
    
    fl1.head = nullptr;
}


template <typename T>
bool FList<T>::empty() const {
    if(m_size){
        return false;
    }
    return true;
};


template <typename T>
size_t FList<T>::size() const {
    return m_size;
};


template <typename T>
void FList<T>::print_next() const noexcept {
    if(head == nullptr){
        return;
    }
    ListNode* curr = head;
    while(curr){
        cout << curr->data << " ";
        curr = curr->next;
    }
}


template <typename T>
void FList<T>::print_prev() const noexcept {
    if(head == nullptr){
        return;
    }
    ListNode* curr = tail;
    while(curr){
        cout << curr->data << " ";
        curr = curr->prev;
    }
}


template <typename T>
void FList<T>::print_asc() const noexcept {
    if(head == nullptr){
        return;
    }
    ListNode* curr = aschead;
    while(curr){
        cout << curr->data << " ";
        curr = curr->asc;
    }
}


template <typename T>
void FList<T>::print_desc() const noexcept {
    if(head == nullptr){
        return;
    }
    ListNode* curr = deschead;
    while(curr){
        cout << curr->data << " ";
        curr = curr->desc;
    }
}
    

template <typename T>
void FList<T>::insert(size_t pos, const T& elem){
    if(static_cast<int>(pos) < 0 or pos > this->size()) {
        throw std::invalid_argument("invalid position");
    }
    if(0 == pos){
        push_front(elem);
        return;
    }
    if(pos == this->size()){
        push_back(elem);
        return;
    }
    ListNode* n = new ListNode(elem);
    ListNode* curr = head;
    while(pos-1){
        curr = curr->next;
        pos--;
    }
    n->prev = curr;
    n->next = curr->next;
    curr->next->prev = n;
    curr->next = n;
    put_in_sorted_order(n);
    m_size++;
    
}


template <typename T>
void FList<T>::insert(size_t pos, T&& elem){
    if(static_cast<int>(pos) < 0 or pos > this->size()) {
        throw std::invalid_argument("invalid position");
    }
    if(0 == pos){
        push_front(elem);
        return;
    }
    if(pos == this->size()){
        push_back(elem);
        return;
    }
    ListNode* n = new ListNode(elem);
    ListNode* curr = head;
    while(pos-1){
        curr = curr->next;
        pos--;
    }
    n->prev = curr;
    n->next = curr->next;
    curr->next->prev = n;
    curr->next = n;
    put_in_sorted_order(n);
    m_size++;
    
}


template <typename T>
void FList<T>::insert(size_t pos, std::initializer_list<T> init){
    if(static_cast<int>(pos) < 0 or pos > this->size()){
        throw std::invalid_argument("invalid position");
    }
    FList<T> part(init);
    if(0 == pos){
        part += *this;
        return;
    }
    if(pos == size()){
        *this += part;
        return;
    }
    m_size += init.size();
    merge(part);
    ListNode* curr = head;
    while(pos-1){
        curr = curr->next;
        pos--;
    }
    ListNode* n = curr->next;
    curr->next = part.head;
    part.head->prev = curr;
    part.tail->next = n;
    n->prev = part.tail;
}


template <typename T>
void FList<T>::push_front(const T& elem){
    ListNode* n = new ListNode(elem);
    if(nullptr == head){
        head = n;
        tail = n;
        aschead = n;
        deschead = n;
        m_size++;
        return;
    }
    
    n->next = head;
    put_in_sorted_order(n);
    head->prev = n;
    head = n;
    m_size++;
}


template <typename T>
void FList<T>::erase(size_t pos1, size_t pos2) {
    if(static_cast<int>(pos1) < 0 or static_cast<int>(pos2) < 0) {
        throw std::invalid_argument("invalid position");
    }
    if(static_cast<int>(pos1) >= m_size or static_cast<int>(pos2) >= m_size) {
        throw std::invalid_argument("invalid position");
    }
    if(pos1 > pos2) {
        throw std::invalid_argument("invalid position");
    }
    if(pos2 == 0){
        pop_front();
        return;
    }
    if(pos1 == m_size-1){
        pop_back();
        return;
    }
    ListNode* curr = head;
    for(int i = 0; i < pos1 - 1; ++i) {
        curr = curr->next;
    }
    ListNode* garb = curr->next;
    int range = pos2 - pos1 + 1;
    while(range && garb->next){
        balance(garb);
        garb = garb->next;
        delete garb->prev;
        range--;
    }
    if(garb->next == nullptr){
        balance(garb);
        delete garb;
        tail = curr;
        curr->next = nullptr;
    }
    else{
        curr->next = garb;
        garb->prev = curr;
    }
    m_size -= (pos2-pos1+1);
}


template <typename T>
void FList<T>::erase(size_t pos) {
    int pos2 = m_size - 1;
    erase(pos, pos2);
}


template <typename T>
bool FList<T>::find(const T& value) {
    ListNode* curr = head;
    while (curr != nullptr) {
        if (curr->data == value) {
            advance_node(curr);
            return true;
        }
        curr = curr->next;
    }
    return false;
}


template <typename T>
bool FList<T>::find(T&& value) {
    ListNode* curr = head;
    while (curr != nullptr) {
        if (curr->data == value) {
            advance_node(curr);
            return true;
        }
        curr = curr->next;
    }
    return false;
}


template <typename T>
void FList<T>::push_front(T&& elem){
    ListNode* n = new ListNode(elem);
    
    if(nullptr == head){
        head = n;
        tail = n;
        aschead = n;
        deschead = n;
        m_size++;
        return;
    }
    
    n->next = head;
    put_in_sorted_order(n);
    head->prev = n;
    head = n;
    m_size++;
}


template <typename T>
void FList<T>::push_back(const T& elem){
    ListNode* n = new ListNode(elem);
    
    if(nullptr == head){
        head = n;
        tail = n;
        aschead = n;
        deschead = n;
        m_size++;
        return;
    }
    
    n->prev = tail;
    put_in_sorted_order(n);
    tail->next = n;
    tail = n;
    m_size++;
}


template <typename T>
void FList<T>::push_back(T&& elem){
    ListNode* n = new ListNode(elem);
    
    if(nullptr == head){
        head = n;
        tail = n;
        aschead = n;
        deschead = n;
        m_size++;
        return;
    }
    
    n->prev = tail;
    put_in_sorted_order(n);
    tail->next = n;
    tail = n;
    m_size++;
}


template <typename T>
void FList<T>::remove(const T& elem) {
    ListNode* curr = head;
    if(1 == m_size){
        m_size--;
        delete_single_node();
    }
    while(curr){
        if(curr->data == elem){
            if (curr == head) {
                head = curr->next;
            }
            if (curr == tail) {
                tail = curr->prev;
            }
            if (curr->next) {
                curr->next->prev = curr->prev;
            }
            if (curr->prev) {
                curr->prev->next = curr->next;
            }
            balance(curr);
            
            ListNode* tmp = curr;
            curr = curr->next;
            delete tmp;
            tmp = nullptr;
            m_size--;
        }
        else{curr = curr->next;}
    }
}


template <typename T>
void FList<T>::pop_front(){
    if(1 == m_size){
        m_size--;
        delete_single_node();
        return;
    }
    if(head == nullptr) {
        throw std::runtime_error("");
    }
    ListNode* front = head;
    head = head->next;
    head->prev = nullptr;
    balance(front);
    delete front;
    front = nullptr;
    m_size--;
}


template <typename T>
void FList<T>::pop_back(){
    if(m_size == 1){
        m_size--;
        delete_single_node();
        return;
    }
    if(head == nullptr) {
        throw std::runtime_error("");
    }
    ListNode* back = tail;
    tail = tail->prev;
    tail->next = nullptr;
    balance(back);
    delete back;
    back = nullptr;
    m_size--;
}
 

template <typename T>
T FList<T>::get_min() const {
    if(head){
        return aschead->data;
    }
    throw std::runtime_error("");
}


template <typename T>
T FList<T>::get_max() const {
    if(head){
        return deschead->data;
    }
    throw std::runtime_error("");
}


template <typename T>
void FList<T>::put_in_sorted_order(ListNode* n) noexcept {
    if(n->data < aschead->data){
        n->asc = aschead;
        aschead->desc = n;
        aschead = n;
        return;
    }
    if(n->data >= deschead->data){
        n->desc = deschead;
        deschead->asc = n;
        deschead = n;
        return;
    }
    ListNode* node = aschead;
    while(node){
        if(node->data > n->data){
            n->desc = node->desc;
            n->asc = node;
            n->desc->asc = n;
            n->asc->desc = n;
            return;
        }
        node = node->asc;
    }
}


template <typename T>
void FList<T>::balance(ListNode* n) noexcept {
    if (n == aschead) {
        aschead = n->asc;
    }
    if (n == deschead) {
        deschead = n->desc;
    }
    if (n->asc) {
        n->asc->desc = n->desc;
    }
    if (n->desc) {
        n->desc->asc = n->asc;
    }
}


template <typename T>
void FList<T>::merge(FList<T>& part) noexcept{
    ListNode* curr = this->aschead;
    while(curr and part.aschead){
        if(curr->data <= part.aschead->data){
            curr = curr->asc;
        }
        else{
            curr->desc->asc = part.aschead;
            part.aschead->desc = curr->desc;
            curr->desc = curr->desc->asc;
            part.aschead = part.aschead->asc;
            part.aschead->desc->asc = curr;
            part.aschead->desc = nullptr;
        }
    }
    if(curr){
        part.deschead->asc = curr;
        curr->desc = part.deschead;
    }

    if(part.aschead){
        this->deschead->asc = part.aschead;
        part.aschead->desc = this->deschead;
        this->deschead = part.deschead;
    }

}


template <typename T>
void FList<T>::advance_node(ListNode* node)
{
    if (!node) return;
    if (node == head) return;
        
    ListNode* lhs = node->prev;
    ListNode* rhs = node->next;

    if (lhs) {lhs->next = rhs;}
    else {head = rhs;}
    
    if (rhs) {rhs->prev = lhs;}
    else {tail = lhs;}
            
    if (lhs) {
        node->prev = lhs->prev;
        if (lhs->prev) {
            lhs->prev->next = node;
        }
        lhs->prev = node;
        node->next = lhs;
    }
}


template <typename T>
void FList<T>::clean() noexcept {
    if(head == nullptr) {
        return;
    }
    ListNode* curr = head;
    ListNode* tmp = curr;
    while (curr) {
        tmp = curr;
        curr = curr->next;
        delete tmp;
    }
    head = nullptr;
    aschead = nullptr;
    deschead = nullptr;
    tail = nullptr;
    m_size = 0;
}


template <typename T>
void FList<T>::delete_single_node() noexcept {
    delete head;
    head = nullptr;
    tail = nullptr;
    aschead = nullptr;
    deschead = nullptr;
    m_size--;
    return;
}


template <typename T>
void FList<T>::reverse() noexcept {
    ListNode* current = head;
    head = tail;
    tail = current;
    while (current != nullptr) {
        ListNode* temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
}
