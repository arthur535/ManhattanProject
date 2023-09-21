#include <iostream>
template<typename T>
class Vector {
private:
    
    int m_capacity;
    int m_size;
    T* m_arr;
    void resize();
    void resize(int);
public:
    
    void my_swap(T&,T&);
    Vector();
    ~Vector();
    Vector(int x);
    Vector(const Vector<T>&);
    Vector(const std::initializer_list<T>&);
    
    T& operator[](int);
    const T& operator[](int) const;
    Vector& operator=(const Vector&);
    Vector operator+(const Vector&);
    Vector& operator+=(const Vector&);
    
    
    /* O(1) */void push_back(T);
    /* O(1) */void pop_back();
    /* O(n) */void push_front(T);
    /* O(n) */void erase(int,int);
    /* O(1) */int size();
    /* O(1) */int capacity();
    /* O(1) */int front();
    /* O(1) */int back();
    /* O(n) */void insert(int,T);
    /* O(1) */bool isEmpty();
    /* O(1) */void clear();
    /* O(n) */int find(T);
    /* O(n) */T at(int);
    /* O(n) */void reserve(int);
    /* O(n) */void print();
    friend std::ostream& operator<<(std::ostream& os,Vector<T>& vec){
        for (int i = 0; i < vec.size(); ++i) {
            os << vec[i] << " ";
        }
        os << std::endl;
        return os;
    }
};
