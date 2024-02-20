#include <iostream>
#ifndef _STRING_IMP_
#define _STRING_IMP_
namespace ams{

class string {
    
public:// constructors and destructor
    
    string();//default constructor
    ~string();//destructor
    string(char*);//constructor with parameters
    string(const string&);//copy constructor
    string(string&&);//move constructor
    string(const std::initializer_list<char>&);//initializer list
    
public://operator overloadings
    
    string& operator=(const string&);//copy assignment operator
    string& operator=(string&&);//move assignment opertaor
    
    friend string operator+(const string& str1, const string& str2) {
        string result;
        result.m_size = str1.m_size + str2.m_size;
        result.m_buf = new char[result.m_size + 1];
        result.m_cap = 1;
        while(result.m_cap < result.m_size){
            result.m_cap *= 2;
        }
        for (int i = 0; i < str1.m_size; ++i) {
            result.m_buf[i] = str1[i];
        }
        for (int i = 0; i < str2.m_size; ++i) {
            result.m_buf[str1.m_size + i] = str2[i];
        }
        result.m_buf[result.m_size] = '\0';
        return result;
    };//operator+ overloading
    
    string& operator+=(const string&);//opertor += overloading
    char& operator[](size_t);//subscript operator overloading
    const char& operator[](size_t) const;//subscript operator overloading
    
    friend std::ostream& operator<<(std::ostream& os, const string& str) {
        for (int i = 0; i < str.m_size; ++i) {
            os << str.m_buf[i];
        }
        return os;
    }//ostream operator overloading
    
public://functions and methods
    
    unsigned long lenght();//function to get lenght of string
    unsigned long size();//function to get size of string
    unsigned long capacity();//function to get capacity of string
    char* data();//function returns string data
    void push_back(char);//function for adding one element to the string
    bool empty();//function to check if the string is empty
    void clear();//clear the string, size = 0; capacity stays the same
    void pop_back();//function to remove the last element of the string
    void append(const char*);//function to add char* to the end of the string
    void append(const char*, size_t);//function to add given part of char* to the end of the string
    void insert(size_t, const char*);//insert char* where user wants
    void insert(size_t, const char*, int);//insert part of char* wher user wants
    void erase();//same as clear()
    void erase(size_t);//erase from the given position
    void erase(size_t, size_t);//erase from the given position1 to the given position2
    void resize(size_t, const char);//resize the string, cut it or make it bigger and initialize with given char symbol
    void resize(size_t);//resize the string into smaller one or dont do anything
    char back();//returns the last character of the string
    char front();//return the first character of the string
    void replace(size_t, size_t, char*);//position is the first given integer, then function replace takes given part(second integer) of the string and replaces it with the third parameter char*
    size_t find(char);//function returns the first appearance of the given symbol
    size_t find(char*);//function returns the first appearance of the given char*
    void swap(string&);//function swaps to strings
    char* substr(size_t, size_t);//return the string which includes (second parameter) characters from the (first parameter) index;
    bool compare(string&);//compare two strings
private:
    char* m_buf;//main member char*
    unsigned long m_size;//size of char*
    unsigned long m_cap;//capacity of char*
private:
    void reSize();
};

}

#endif /*_STRING_IMP_*/
