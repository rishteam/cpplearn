#include <bits/stdc++.h>

#include "intpair.h"

void testIntPairSet(int a, int b)
{
    IntPair t;
    t.set(a, b);
    t.print();
}

void testIntPairConstruct(int a, int b)
{
    IntPair t;
    t.print();
}

int main()
{
    int a, b;

    while(std::cin >> a >> b)
    {
        testIntPairSet(a, b);
        testIntPairConstruct(a, b);
    }
}