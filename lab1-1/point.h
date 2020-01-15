#pragma once

#include <cstdio>
#include <iostream>
// Add code here
class Point
{
private:
    int m_x, m_y, m_z;
public:
    Point()
    {
        m_x = m_y = m_z = 0;
    }
    Point(int x, int y, int z)
    {
        set(x, y, z);
    }
    Point(const Point &o)
    {
        set(o.m_x, o.m_y, o.m_z);
    }

    void print()
    {
        std::printf("Point(%d, %d, %d)\n", m_x, m_y, m_z);
    }
    void set(int x, int y, int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }
    Point& operator+=(const Point& other)
    {
        m_x += other.m_x;
        m_y += other.m_y;
        m_z += other.m_z;
        return *this;
    }
    friend Point operator+(const Point &lhs, const Point &rhs)
    {
        Point tmp;
        tmp += lhs;
        tmp += rhs;
        return tmp;
    }
};