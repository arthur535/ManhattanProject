//operator overloadings

ams::string& ams::string::operator=(const string& other){
    std::cout << "copy assignment operator call\n";
    if (this != &other) {
        m_size = other.m_size;
        m_cap = other.m_cap;
        if (!m_buf) {
            m_buf = new char[m_cap];
        }
        for (int i = 0; i < m_size; ++i) {
            m_buf[i] = other.m_buf[i];
        }
    }
    return *this;
}

ams::string& ams::string::operator=(string&& rhs) {
    std::cout << "move assignment operator call\n";
    if (!m_size) {
        m_size = rhs.m_size;
        m_cap = rhs.m_cap;
        m_buf = rhs.m_buf;
        rhs.m_buf = nullptr;
    }
    else {
        m_buf = (char*)"";
        m_size = rhs.m_size;
        m_cap = rhs.m_cap;
        m_buf = rhs.m_buf;
        rhs.m_buf = nullptr;
    }
    return *this;
}

char& ams::string::operator[](size_t index) {
    if (index > m_cap) {
        perror("segmentation fault ");
        exit(-1);
    }
    return m_buf[index];
}

const char& ams::string::operator[](size_t index) const {
    if (index > m_cap) {
        perror("segmentation fault ");
        exit(-1);
    }
    return m_buf[index];
}

ams::string& ams::string::operator+=(const string& str) {
    if (!str.m_buf) {
        return *this;
    }
    if (m_size >= str.m_size) {
        m_cap *= 2;
    }
    else {
        m_cap = 2 * str.m_size;
    }
    std::cout << std::endl;
    string tmp;
    std::cout << std::endl;
    tmp.m_buf = new char[m_cap];
    
    for (int i = 0; i < m_size; ++i) {
        tmp.m_buf[i] = m_buf[i];
    }
    for (int i = 0; i < str.m_size; ++i) {
        tmp.m_buf[m_size + i] = str[i];
    }
    this -> m_size += str.m_size;
    strcpy(m_buf, tmp.m_buf);
    delete[] tmp.m_buf;
    tmp.m_buf = nullptr;
    tmp.m_cap = 0;
    tmp.m_size = 0;
    return *this;
}
