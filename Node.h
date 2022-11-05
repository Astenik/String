#pragma once

struct Node
{
public:
    Node(char v, Node* p = nullptr, Node* n = nullptr)
        : value(v)
        , prev(p)
        , next(n)
    {}
    ~Node() {}
    
public:
    char value;
    Node* prev;
    Node* next;
};
