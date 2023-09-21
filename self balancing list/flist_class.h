#ifndef FLIST_H
#define FLIST_H
#include <ostream>
template <typename T>
class FList {
public:
    FList(); // deafult ctor
    
    FList(std::initializer_list<T>); // initializer list ctor
    FList(const FList&); // copy ctor
    FList(FList&&); // move ctor
    FList& operator=(const FList&); // copy assignment operator
    FList& operator=(FList&&); // move assignment operator
    ~FList();
    bool operator==(const FList&) const;
    void operator+=(FList&);
    
    
    friend FList operator+(const FList f1, const FList f2) {
        FList result(f1);
        FList tmp(f2);
        result += tmp;
        tmp.clean();
        return result;
    }
    
    friend std::ostream& operator<<(std::ostream& os, FList f){
        f.print_next();
        return os;
    }
    
public:
    class ListNode {
    public:
        ListNode() = default;
        ListNode(T elem) : data(elem){};
        T data;
        ListNode* prev = nullptr;
        ListNode* asc = nullptr;

        ListNode* desc = nullptr;
        ListNode* next = nullptr;
    };
    
private: //memebers
    ListNode* head; // pointer to head node
    ListNode* tail; // pointer to tail node
    ListNode* aschead; // pointer to minimum node
    ListNode* deschead; // pointer to maximum node
    
    size_t m_size = 0;
    
public:
    class Iterator {
    private:
        ListNode* current;

    public:
        Iterator(ListNode* node) : current(node) {}

        T& operator*() const {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };
    
    Iterator begin() const{
        return Iterator(head);
    }

    Iterator end() const{
        return Iterator(nullptr);
    }
    
public:
    bool empty() const;
    size_t size() const;
    
    void print_next() const noexcept;
    void print_prev() const noexcept;
    void print_asc() const noexcept;
    void print_desc() const noexcept;
    
    void insert(size_t, const T&);
    void insert(size_t, T&&);
    void insert(size_t pos, std::initializer_list<T>);
    void push_front(const T&);
    void push_front(T&&);
    void push_back(const T&);
    void push_back(T&&);
    
    void remove(const T&);
    void pop_front();
    void pop_back();
    
    void clean() noexcept;
    
    void erase(size_t);
    void erase(size_t, size_t);
    
    bool find(const T&);
    bool find(T&&);
    
    void reverse() noexcept;
    
    T get_min() const;
    T get_max() const;
    
private:
    void put_in_sorted_order(ListNode*) noexcept;
    void balance(ListNode* n) noexcept;
    void merge(FList&) noexcept;
    void delete_single_node() noexcept;
    void advance_node(ListNode*);
};

#endif
