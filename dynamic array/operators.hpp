#include <fstream>
#include <iostream>
template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& vec1) {
    if (this->m_size != vec1.m_size) {
        perror("your sizes aren't equal");
        return *this;
    }
    Vector<T> tmp;
    tmp = *this;
    for (int i = 0; i < m_size; ++i) {
        tmp[i] = m_arr[i] + vec1.m_arr[i];
    }
    return tmp;
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& vec1) {
    *this = *this + vec1;
    return *this;
}
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
    if (this == &v) {
        return *this;
    }
    delete[] m_arr;
    m_capacity = v.m_capacity;
    m_size = v.m_size;
    m_arr = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = v.m_arr[i];
    }
    return *this;
}





template <typename T>
const T& Vector<T>::operator[](int index) const {
    return m_arr[index];
}


template<typename T>
T& Vector<T>::operator[](int index) {
    return m_arr[index];
}



