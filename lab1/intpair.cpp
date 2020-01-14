#include "intpair.h"

// Add code here

void IntPair::set(int a, int b)
{
    m_a = a;
    m_b = b;
}

void IntPair::print()
{
    std::printf("Pair(%d, %d)\n", m_a, m_b);
}