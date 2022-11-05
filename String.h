#pragma once

#include "Node.h"

class String
{
public:
    String();
    String(const char&);
    String(const String&);
    ~String();
    
public:
    int size() const;
    int find_char(const char&) const;
    int rfind_char(const char&) const;
    int find_substr(const String&) const;
    friend void print(const String&);
    
    void add_symbol(const char&);
    void remove_symbol(const char&);
    void clear();

public:
    String& operator=(const String&);
    String operator+(const String&) const;
    bool operator==(const String&) const;
    char operator[](int) const;
    

private:
    Node* m_head;
    Node* m_back;
    int m_size;
};

