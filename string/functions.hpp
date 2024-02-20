//functions and methods

unsigned long ams::string::lenght() {return m_size;}

unsigned long ams::string::size() {return m_size;}

unsigned long ams::string::capacity() {return m_cap;}

char* ams::string::data() {return m_buf;}

void ams::string::reSize() {
    while (m_cap < m_size) {
        m_cap *= 2;
    }
    while (m_cap/2 >= m_size) {
        m_cap /=2;
    }
}
void ams::string::push_back(char s) {
    m_size++;
    reSize();
    if (m_buf) {
        m_buf[m_size-1] = s;
        return;
    }
    m_buf = new char[1];
    m_buf[0] = s;
    m_size = 1;
}

bool ams::string::empty() {return m_size == 0;}

void ams::string::clear() {
    if (m_buf) {
        for (int i = 0; i < m_size; ++i) {
            m_buf[i] = '\0';
        }
        m_size = 0;
    }
}

void ams::string::pop_back() {
    m_buf[--m_size] = '\0';
    reSize();
}

void ams::string::append(const char* s) {
    if (!s) {
        perror("bad access");
        exit(-1);
    }
    if (m_size + strlen(s) < m_cap ) {
        for (int i = 0; i < strlen(s); ++i) {
            m_buf[m_size++] = s[i];
        }
        m_buf[m_size] = '\0';
    }
    
    char* tmp = m_buf;
    m_size += strlen(s);
    m_cap = 1;
    while (m_cap < m_size) {
        m_cap *= 2;
    }
    m_buf = new char[m_cap];
    strcpy(m_buf, tmp);
    delete[] tmp;
    for (int i = 0; i < strlen(s); ++i) {
        m_buf[m_size - strlen(s) + i] = s[i];
    }
    m_buf[m_size] = '\0';
}

void ams::string::append(const char* s, size_t size) {
    if (!size) {return;}
    if (!s) {
        perror("bad access");
        exit(-1);
    }
    if (size < strlen(s)) {
        char* tmp = new char[size];
        for (int i = 0; i < size; ++i) {
            tmp[i] = s[i];
        }
        s = tmp;
        tmp = nullptr;
    }
    else if (size > strlen(s)) {
        perror("bad access");
        exit(-1);
    }
    m_size += strlen(s);
    
    char* tmp = m_buf;
    m_cap = 1;
    while(m_cap < m_size) {
        m_cap *= 2;
    }
    m_buf = new char[m_cap];
    strcpy(m_buf, tmp);
    delete[] tmp;
    tmp = nullptr;
    for (int i = 0; i < strlen(s); ++i) {
        m_buf[m_size - strlen(s) + i] = s[i];
    }
    m_buf[m_size] = '\0';
}


void ams::string::erase() {
    if (m_buf) {
        for (int i = 0; i < m_size; ++i) {
            m_buf[i] = '\0';
        }
        m_size = 0;
    }
}

void ams::string::insert(size_t pos,const char* s) {
    if (pos < 0 || pos > m_size ) {
        perror("given position is not valid");
        exit(-1);
    }
    unsigned long size = m_size + strlen(s);
    unsigned long capacity = 1;
    while (capacity < size) {
        capacity *= 2;
    }
    char* tmp = new char[m_cap];
    int count = 0;
    for (int i = 0; i < pos; ++i) {
        count++;
        tmp[i] = m_buf[i];
    }
    for (int i = 0; i < strlen(s); ++i) {
        tmp[count] = s[i];
        count++;
    }
    for (int i = 0; i < m_size - pos; ++i) {
        tmp[count + i] = m_buf[pos + i];
    }
    tmp[size] = '\0';
    delete[] m_buf;
    m_buf = nullptr;
    m_buf = tmp;
    tmp = nullptr;
    m_size = size;
    m_cap = capacity;
}

void ams::string::insert(size_t pos, const char* s, int size) {
    if (pos < 0 || pos > m_size ) {
        perror("given position is not valid");
        exit(-1);
    }
    if (size > strlen(s)) {
        perror("given size is bigger than size og given char*");
        exit(-1);
    }
    unsigned long tmp_size = m_size + size;
    unsigned long capacity = 1;
    while (capacity < tmp_size) {
        capacity *= 2;
    }
    char* tmp = new char[m_cap];
    int count = 0;
    for (int i = 0; i < pos; ++i) {
        count++;
        tmp[i] = m_buf[i];
    }
    for (int i = 0; i < size; ++i) {
        tmp[count] = s[i];
        count++;
    }
    for (int i = 0; i < m_size - pos; ++i) {
        tmp[count + i] = m_buf[pos + i];
    }
    tmp[tmp_size] = '\0';
    delete[] m_buf;
    m_buf = nullptr;
    m_buf = tmp;
    tmp = nullptr;
    m_size = tmp_size;
    m_cap = capacity;
}

void ams::string::erase(size_t pos) {
    if (pos < 0) {
        perror("given position is negative");
        exit(-1);
    }
    
    else if(pos == 0) {
        for (int i = 0; i < m_size; ++i) {
            m_buf[i] = '\0';
        }
        m_size = 0;
        return;
    }
    
    if(pos >= m_size) {
        perror("given position is bigger than the size of the string");
        exit(-1);
    }
    
    if (m_buf) {
        for (auto i = pos; i < m_size; ++i) {
            m_buf[i] = '\0';
        }
        m_size = pos;
        reSize();
    }
}

void ams::string::erase(size_t pos1, size_t pos2) {
    if (pos1 < 0) {
        perror("given position is negative");
        exit(-1);
    }
    
    else if (pos1 > pos2) {
        perror("given position 1 is bigger than given position 2");
        exit(-1);
    }
    
    else if (pos2 >= m_size) {
        perror("given position 2 is bigger than the size of the string");
        exit(-1);
    }
    
    if (pos1 == pos2) {
        if (pos1 == 0) {
            char* tmp = new char[m_size-1];
            for (int i = 0; i < m_size-1; ++i) {
                tmp[i] = m_buf[i+1];
            }
            tmp[m_size-1] = '\0';
            delete[] m_buf;
            m_buf = tmp;
            tmp = nullptr;
            --m_size;
            reSize();
            return;
        }
        char* tmp = new char[m_size-1];
        for (int i = 0; i < m_size; ++i) {
            if (i == pos1) {continue;}
            if (i > pos1) {
                tmp[i-1] = m_buf[i];
            }
            else{
                tmp[i] = m_buf[i];
            }
        }
        tmp[m_size-1] = '\0';
        delete[] m_buf;
        m_buf = tmp;
        tmp = nullptr;
        --m_size;
        reSize();
        return;
    }
    
    char* tmp = new char [m_size-(pos2-pos1+1)];
    int i;
    for (i = 0; i < pos1; ++i) {
        tmp[i] = m_buf[i];
    }
    tmp[i] = '\0';
    for (i += pos2 - pos1 + 1; i < m_size; ++i) {
        tmp[i - (pos2 - pos1 + 1)] = m_buf[i];
    }
    delete[] m_buf;
    m_buf = tmp;
    tmp = nullptr;
    m_size -= (pos2-pos1+1);
    reSize();
}

void ams::string::resize(size_t size, char symbol) {
    if (size < m_size) {
        erase(size);
        m_size = size;
        reSize();
    }
    else if (size > m_size) {
        m_size = size;
        m_cap = 1;
        while (m_cap < m_size) {
            m_cap *= 2;
        }
        char* tmp = new char[m_cap];
        strcpy(tmp, m_buf);
        for (size_t i = strlen(m_buf); i < m_size; ++i) {
            tmp[i] = symbol;
        }
        delete[] m_buf;
        m_buf = tmp;
        tmp = nullptr;
    }
}

void ams::string::resize(size_t size) {
    if (size < m_size) {
        erase(size);
        m_size = size;
        reSize();
        return;
    }
    perror("given size must be smaller than size of string");
    exit(-1);
}

char ams::string::back() {
    return m_buf[m_size-1];
}

char ams::string::front() {
    return m_buf[0];
}

void ams::string::replace(size_t pos1, size_t size, char* s) {
    size_t pos2 = pos1 + size - 1;
    erase(pos1, pos2);
    insert(pos1, s);
}

size_t ams::string::find(char s) {
    for (size_t i = 0; i < m_size; ++i) {
        if (m_buf[i] == s) {
            return i;
        }
    }
    return -1;
}

size_t ams::string::find(char* s) {
    if (strlen(s) > m_size) {
        return -1;
    }
    else if (strlen(s) == m_size) {
        for (int i = 0; i < m_size; ++i) {
            if(m_buf[i] != s[i]) {
                return - 1;
            }
        }
        return 0;
    }
    for (int i = 0; i < m_size - strlen(s) + 1; ++i) {
        int count = 0;
        for (int j = 0; j < strlen(s); ++j) {
            if (m_buf[i+j] == s[j]) {
                count++;
            }
        }
        if(count == strlen(s)) {
            return i;
        }
    }
    return -1;
}

void ams::string::swap(string& str) {
    unsigned long tmp = str.m_size;
    str.m_size = this -> m_size;
    this -> m_size = tmp;
    
    unsigned long tmp1 = str.m_cap;
    str.m_cap = this -> m_cap;
    this -> m_cap = tmp1;
    
    char* tmp2 = str.m_buf;
    str.m_buf = this -> m_buf;
    this -> m_buf = tmp2;
}

char* ams::string::substr(size_t pos, size_t size) {
    if (empty()) {
        perror("your string is empty");
        exit(-1);
    }
    if (pos < 0 || pos > m_size) {
        perror("given arguments are not valid for this situation");
        exit(-1);
    }
    if (size > m_size - pos) {
        size = m_size - pos;
    }
    char* new_m_buf = new char[size];
    for (auto i = pos; i < size + pos; ++i) {
        new_m_buf[i - pos] = m_buf[i];
    }
    return new_m_buf;
}

bool ams::string::compare(string& ss) {
    if (ss.m_size != this -> m_size) {
        return 0;
    }
    for (int i = 0; i < m_size; ++i) {
        if (m_buf[i] != ss.m_buf[i]) {
            return 0;
        }
    }
    return 1;
}
