#include <iostream>
template<typename T>
Vector<T>::Vector() {
//    std::cout << "default ctor\n";
    m_capacity = 0;
    m_size = 0;
    m_arr = nullptr;
}

template<typename T>
Vector<T>::Vector(int x):m_capacity(x) {
//    std::cout << "ctor with parameters\n";
    m_size = 0;
    m_arr = new T [m_capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& vec) {
//    std::cout << "copy ctor\n";
    m_size = vec.m_size;
    m_capacity = vec.m_capacity;
    m_arr = new T[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = vec.m_arr[i];
    }
}
template<typename T>
Vector<T>::~Vector() {
    if (!m_arr) {
        delete[] m_arr;
    }
//    std::cout << "dtor \n";
    m_arr = nullptr;
}

template<typename T>
Vector<T>::Vector(const std::initializer_list<T>& init) {
//    std::cout << "ctor initializer list\n";
    m_capacity = static_cast<int>(init.size());
    m_size = static_cast<int>(init.size());
    m_arr = new T[m_capacity];
    int i = 0;
    for (auto it = init.begin(); it != init.end(); ++it) {
        m_arr[i++] = *it;
    }
}

template<typename T>
void Vector<T>::push_back(T element) {
    if (m_size == m_capacity) {
        resize();
    }
    m_arr[m_size++] = element;
}


template<typename T>
void Vector<T>::pop_back() {
    if (0 == m_size) {
//        std::cout << "vector is empty" << std::endl;
        return;
    }
    m_size--;
}


template<typename T>
void Vector<T>::resize() {
    m_capacity *= 2;
    T* tmp = new T [m_capacity];
    for (int i = 0; i < m_size; ++i) {
        tmp[i] = m_arr[i];
    }
    delete[] m_arr;
    m_arr = tmp;
}
template<typename T>
void Vector<T>::resize(int new_cap) {
    m_capacity = new_cap;
    T* tmp = new T [m_capacity];
    for (int i = 0; i < m_size; ++i) {
        tmp[i] = m_arr[i];
    }
    delete[] m_arr;
    m_arr = tmp;
}



template<typename T>
void Vector<T>::push_front(T element) {
    if (m_size == m_capacity) {
        resize();
    }
    m_size++;
    for (int i = 0; i < m_size; ++i) {
        my_swap(m_arr[m_size-1-i],m_arr[m_size-i]);
    }
    m_arr[0] = element;
}


template<typename T>
void Vector<T>::my_swap(T& a,T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void Vector<T>::erase(int pos1,int pos2) {
    if(pos2 < pos1){
        throw std::invalid_argument("pos1 must be less than or equal to pos2");
    }
    if(pos2 < 0 or pos1 < 0){
        throw std::invalid_argument("pos1 and pos2 must be positive integers");
    }
    
    int i = pos1;
    int j = i + (pos2 - pos1 + 1);
    
    while(j < m_size){
        m_arr[i] = m_arr[j];
        i++;
        j++;
    }
    m_size -= (pos2 - pos1 + 1);
}

template<typename T>
int Vector<T>::size(){
    return m_size;
}


template<typename T>
int Vector<T>::capacity(){
    return m_capacity;
}


template<typename T>
int Vector<T>::front(){
    if(isEmpty()){
        throw std::out_of_range("Index out of bounds");
        return -1;
    }
    return m_arr[0];
}


template<typename T>
int Vector<T>::back(){
    if(isEmpty()){
        throw std::out_of_range("Index out of bounds");
        return -1;
    }
    return m_arr[m_size-1];
}


template<typename T>
void Vector<T>::insert(int pos, T element) {
    if (m_size == m_capacity) {
        resize();
    }
    m_size++;
    if(pos > m_size or pos < 0){
        throw std::invalid_argument("invalid argument");
    }
    for (int j = m_size - 1; j > pos; --j) {
        m_arr[j] = m_arr[j-1];
    }
    m_arr[pos] = element;
}


template<typename T>
bool Vector<T>::isEmpty() {
    return (m_size == 0);
}


template<typename T>
void Vector<T>::clear() {
    T* tmp = new T[m_capacity];
    m_size = 0;
    delete[] m_arr;
    m_arr = tmp;
}


template<typename T>
int Vector<T>::find(T value) {
    for (int i = 0; i < size(); ++i) {
        if (m_arr[i] == value) {
            return i;
        }
    }
    return -1;
}



template<typename T>
T Vector<T>::at(int index) {
    if (isEmpty() || index < 0 || index >= size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_arr[index];
}

template<typename T>
void Vector<T>::reserve(int new_cap) {
    if(new_cap > m_capacity){
        resize(new_cap);
    }
    if (new_cap < 0) {
        throw std::invalid_argument("give positive integer argument");
    }
}


template<typename T>
void Vector<T>::print() {
    for(int i = 0; i < m_size; ++i){
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}
