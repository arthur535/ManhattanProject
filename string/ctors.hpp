//constructors and destructor

ams::string::string() {
    std::cout << "default constructor\n";
    m_size = 0;
    m_cap = 1;
    m_buf = nullptr;
}
ams::string::~string() {
    std::cout << "destructor\n";
    if(m_buf) {
        delete[] m_buf;
        m_buf = nullptr;
    }
}
ams::string::string(char* val) {
    std::cout << "constructor with parameters\n";
    if (!val) {
        m_buf = new char[1];
        m_buf[0] = '\0';
        m_size = 0;
        m_cap = 1;
        return;
    }
    m_size = strlen(val);
    m_cap = 1;
    while(m_cap < m_size) {
        m_cap *= 2;
    }
    m_buf = new char[m_cap];
    strcpy(m_buf, val);
    m_buf[strlen(val)] = '\0';
}

ams::string::string(const string& other) {
    if (!other.m_buf) {
        m_buf = new char[1];
        m_buf[0] = '\0';
        return;
    }
    std::cout << "copy constructor\n";
    m_buf = new char[other.m_cap];
    strcpy(m_buf, other.m_buf);
    m_buf[strlen(other.m_buf)] = '\0';
    m_size = other.m_size;
    m_cap = other.m_cap;
}

ams::string::string(string&& rhs) {
    if (!rhs.m_buf) {
        m_buf = new char[1];
        m_buf[0] = '\0';
        return;
    }
    std::cout << "move constructor\n";
    m_buf = rhs.m_buf;
    m_size = rhs.m_size;
    m_cap = rhs.m_cap;
    rhs.m_buf = nullptr;
}

ams::string::string(const std::initializer_list<char>& init) {
    this -> m_size = init.size();
    int i = 0;
    for (auto it = init.begin(); it != init.end(); ++it) {
        this -> m_buf[i] = *it;
        i++;
    }
    m_cap = 1;
    while(m_cap < m_size){
        m_cap *= 2;
    }
}
