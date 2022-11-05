#include "String.h"
#include <iostream>

String::String()
    : m_head(nullptr)
    , m_back(nullptr)
    , m_size(0)
{
    std::cout << "default ctor" << std::endl;
}

String::String(const char& c)
    : m_head(new Node(c))
    , m_back(m_head)
    , m_size(1)
{
    std::cout << "ctor with perimetres" << std::endl;
}

String::String(const String& ob)
    : m_head(nullptr)
    , m_back(nullptr)
    , m_size(0)
{
    Node* ptr = ob.m_head;
    while(ptr)
    {
        add_symbol(ptr->value);
        ptr = ptr->next;
    }
    std::cout << "copy ctor" << std::endl;
}

String::~String()
{
    clear();
    std::cout << "dtor" << std::endl;
}

int String::size() const
{
    return m_size;
}

int String::find_char(const char& c) const
{
    Node* ptr = m_head;
    for(int i = 0; i < m_size; ++i)
    {
        if(ptr->value == c)
        {
            return i;
        }
        ptr = ptr->next;
    }
    return -1;
}

int String::rfind_char(const char& c) const
{
    Node* ptr = m_back;
    for(int i = m_size - 1; i >= 0; --i)
    {
        if(ptr->value == c)
        {
            return i;
        }
        ptr = ptr->prev;
    }
    return -1;
}

int String::find_substr(const String& str) const 
{
    for(int i = 0; i < m_size; ++i)
    {
        String k;
        for(int j = i; j < str.size() + i; ++j)
        {
            k.add_symbol(str[j]);
        }
        if(k == str)
        {
            return i;
        } 
    }
    return -1;
}

void  print(const String& ob)
{
    for(int i = 0; i < ob.m_size; ++i)
    {
        std::cout << ob[i];
    }
    std::cout << std::endl;
}

void String::add_symbol(const char& c)
{
    if(m_head == nullptr)
    {
        m_back = m_head = new Node(c);
    }
    else 
    {
        m_back = m_back->next = new Node(c, m_back);
    }
    ++m_size;
}

void String::remove_symbol(const char& c)
{
    if(m_head == nullptr)
    {
        throw "your string is empty";
    }
    Node* ptr = m_head;
    while(ptr)
    {
        if(ptr->value == c)
        {
            if(ptr->prev && ptr-> next)
            {
                Node* p = ptr;
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                ptr = ptr->next;
                delete p;
                p = nullptr;
            }
            if(ptr->prev)
            {
                m_back = m_back->prev;
                delete m_back->next;
                m_back->next = nullptr;
                ptr = nullptr;
            }
            if(ptr->next)
            {
                m_head = m_head->next;
                delete m_head->prev;
                m_head->prev = nullptr;
                ptr = m_head;
            }
            else
            {
                delete m_head;
                m_back = m_head = nullptr;
                ptr = nullptr;
                break;
            }
            --m_size;
        }
        else 
        {
            ptr = ptr->next;
        }
    }
}

void String::clear()
{
    while(m_head)
    {
        remove_symbol(m_head->value);
    }
    m_back = nullptr;
}

String& String::operator=(const String& ob)
{
    if(&ob == this)
    {
        return *this;
    }
    clear();
    Node* ptr = ob.m_head;
    while(ptr)
    {
        add_symbol(ptr->value);
        ptr = ptr->next;
    }
    return *this;
}

String String::operator+(const String& ob) const
{
    String res(*this);
    Node* ptr = ob.m_head;
    while(ptr)
    {
        res.add_symbol(ptr->value);
        ptr = ptr->next;
    }
    return res;
}

bool String::operator==(const String& ob) const
{
    if(&ob == this)
    {
        return true;
    }
    if(m_size != ob.size())
    {
        return false;
    }
    for(int i = 0; i < m_size; ++i)
    {
        if((*this)[i] != ob[i])
        {
            return false;
        }
    }
    return true;
}

char String::operator[](int i) const
{
    if(i >= 0 && i < m_size)
    {
        Node* ptr = m_head;
        for(int j = 0; j < i; ++j)
        {
            ptr = ptr->next;
        }
        return ptr->value;
    }
    else
    {
        throw "index out of range";
    }
}
