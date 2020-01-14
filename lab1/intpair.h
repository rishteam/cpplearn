#pragma once

#include <cstdio>
#include <iostream>
// Add code here

class IntPair
{
private:
    int m_a, m_b;
public:
    IntPair() = default;
    IntPair(int a, int b)
    {
        m_a = a;
        m_b = b;
    }

    void set(int a, int b);
    void print();
};