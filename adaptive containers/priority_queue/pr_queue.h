#ifndef PR_QUEUE_H
#define PR_QUEUE_H
#include </Users/arthur/Desktop/data structures/vector/vector.h>
#include <iostream>
template <typename T>
class priority_queue {
public:
    priority_queue(){
        m_size = 0;
    }
    priority_queue(const priority_queue& oth){
        m_size = oth.m_size;
        m_arr = new T[m_size];
        for (int i = 0; i < m_size; ++i) {
            m_arr[i] = oth.m_arr[i];
        }
    }
    priority_queue(priority_queue&& rhs){
        m_size = rhs.m_size;
        m_arr = rhs.m_arr;
        rhs.m_arr = nullptr;
    }
    priority_queue(std::initializer_list<T> init){
        m_size = init.size();
        m_arr = init;
        build_heap();
    }
    priority_queue(const Vector<T>& vec){
        m_size = vec.size();
        m_arr = vec;
        build_heap();
    }
    
    
    priority_queue& operator=(const priority_queue& oth) {
        m_size = oth.m_size;
        m_arr = new T[m_size];
        for (int i = 0; i < m_size; ++i) {
            m_arr[i] = oth.m_arr[i];
        }
        return *this;
    }
    
    priority_queue& operator=(priority_queue&& rhs) {
        m_size = rhs.m_size;
        m_arr = rhs.m_arr;
        rhs.m_arr = nullptr;
        return *this;
    }
    
    void insert(const T& value){
        m_arr.push_back(value);
        m_size++;
        int i = m_size - 1;
        while(i > 0 && m_arr[i] > m_arr[parent(i)]){
            swap(m_arr[parent(i)],m_arr[i]);
            i = parent(i);
        }
        
    }
    
    void insert(T&& value){
        m_arr.push_back(value);
        m_size++;
        int i = m_size - 1;
        while(i > 0 && m_arr[i] > m_arr[parent(i)]){
            std::swap(m_arr[parent(i)],m_arr[i]);
            i = parent(i);
        }
    }
    
    void deletion(int i) {
        if(i < 0 or i >= m_size){
            throw std::out_of_range("");
        }

        // Replace the element to be deleted with the last element.
        m_arr[i] = m_arr.back();
        m_arr.pop_back();
        m_size--;
        // Perform a "sift down" operation to maintain the max-heap property.
        max_heapify(i);
    }
    void increase_key(int i,T value){
        if(i < 0 or i >= m_size){
            throw std::out_of_range("");
        }
        m_arr[i] = value;
        while(i > 0 && m_arr[i] > m_arr[parent(i)]){
            std::swap(m_arr[parent(i)],m_arr[i]);
            i = parent(i);
        }
    }
    
    T extractMax() {
        if (0 == m_size) {
            throw std::out_of_range("");
        }

        T maxElement = m_arr[0]; // Store the maximum element (root).
        m_arr[0] = m_arr.back(); // Replace root with the last element.
        m_arr.pop_back(); // Remove the last element.
        m_size--;
        // Restore the max-heap property by calling max_heapify on the root.
        max_heapify(0);

        return maxElement; // Return the extracted maximum element.
    }
    
    uint size() const noexcept {
        return m_size;
    }

    Vector<T>& data() {
        return m_arr;
    }
    
    T get_max(){
        return m_arr[0];
    }
    
    
private:
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    
    Vector<T> m_arr;
    int m_size;
    void build_heap(){
        for (int i = m_size/2 - 1; i >= 0; --i) {
            max_heapify(i);
        }
    }
    void max_heapify(unsigned i){
        int l = left(i);
        int r = right(i);
        int largest = i;
        
        if(l < m_size && m_arr[l] > m_arr[largest]){
            largest = l;
        }
        if(r < m_size && m_arr[r] > m_arr[largest]){
            largest = r;
        }
        if(largest != i){
            std::swap(m_arr[i],m_arr[largest]);
            max_heapify(largest);
        }
    }
};


#endif
